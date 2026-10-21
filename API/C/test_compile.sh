#!/bin/sh
# Run with: sh API/C/test_compile.sh. No compiler or database files are required.
set -eu

script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
work=$(mktemp -d)
trap 'rm -rf "$work"' 0
trap 'exit 1' 1 2 3 15
mkdir "$work/bin"
cp "$script_dir/compile.sh" "$work/compile.sh"

cat > "$work/bin/gcc" <<'STUB'
#!/bin/sh
case "$1" in
    database-generator.c) stage=generator ;;
    example.c) stage=example ;;
    *) exit 99 ;;
esac
printf 'gcc:%s\n' "$stage" >> "$CASE_LOG"
[ "$FAIL_STAGE" != "gcc:$stage" ] || exit 23
STUB
cat > "$work/bin/rm" <<'STUB'
#!/bin/sh
printf 'rm:%s\n' "$2" >> "$CASE_LOG"
[ "$FAIL_STAGE" != "rm:$2" ] || exit 31
STUB
chmod +x "$work/bin/gcc" "$work/bin/rm"

check() {
    fail=$1 expected_status=$2 expected_calls=$3
    : > "$work/calls"
    status=0
    (cd "$work" && PATH="$work/bin:$PATH" CASE_LOG="$work/calls" \
        FAIL_STAGE="$fail" sh compile.sh) || status=$?
    calls=$(cat "$work/calls")
    if [ "$status" -ne "$expected_status" ] || [ "$calls" != "$expected_calls" ]; then
        printf 'FAIL %s: exit=%s, calls:\n%s\n' "$fail" "$status" "$calls" >&2
        exit 1
    fi
    printf 'PASS %s\n' "$fail"
}

check none 0 'rm:database-generator
gcc:generator
rm:example
gcc:example'
check gcc:generator 23 'rm:database-generator
gcc:generator'
check gcc:example 23 'rm:database-generator
gcc:generator
rm:example
gcc:example'
check rm:database-generator 31 'rm:database-generator'
check rm:example 31 'rm:database-generator
gcc:generator
rm:example'
