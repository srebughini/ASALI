# -*- mode: python ; coding: utf-8 -*-

import sys
import os
import tomllib  # Python 3.11+ built-in TOML parser

# ----------------------------
# Load project metadata
# ----------------------------
with open("pyproject.toml", "rb") as f:
    config = tomllib.load(f)

project = config.get("project", {})
tool_config = config.get("tool", {}).get("pyinstaller", {})

APP_NAME = project.get("name", "app")

# ----------------------------
# Detect platform and icon
# ----------------------------
PLATFORM = sys.platform.lower()
if PLATFORM.startswith("win"):
    icon_file = f"{tool_config.get('icon', 'src/resources/images/Icon')}.ico"
else:
    icon_file = f"{tool_config.get('icon', 'src/resources/images/Icon')}.png"

# ----------------------------
# Module configuration
# ----------------------------
excluded_modules = [
    'tkinter', 'unittest', 'pydoc', 'doctest', 'http', 'xmlrpc',
    'distutils', 'setuptools', 'test', 'asyncio', 'concurrent',
    'multiprocessing', 'sqlite3', 'wsgiref'
]

hiddenimports = [
    'PySide6.QtWidgets',
    'PySide6.QtCore',
    'PySide6.QtGui'
]

# ----------------------------
# Collect data paths
# ----------------------------
data_entries = []
for path in tool_config.get("include-data", []):
    data_entries.append((path, path))

# ----------------------------
# PyInstaller build pipeline
# ----------------------------
a = Analysis(
    [tool_config.get("entry-point", "app.py")],
    pathex=[],
    binaries=[],
    datas=data_entries,
    hiddenimports=hiddenimports,
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=excluded_modules,
    noarchive=False,
    optimize=0,
)

pyz = PYZ(
    a.pure,
    a.zipped_data,
    cipher=None
)

# ----------------------------
# Platform-specific EXE options
# ----------------------------
exe_kwargs = {
    "exclude_binaries": True,
    "name": f"{APP_NAME}",
    "debug": False,
    "bootloader_ignore_signals": False,
    "strip": True,
    "upx": True,
    "console": False,
    "disable_windowed_traceback": False,
    "target_arch": None,
    "icon": icon_file,
}

if PLATFORM.startswith("win"):
    exe_kwargs.update({
        "win_no_prefer_redirects": False,
        "win_private_assemblies": True,
    })

exe = EXE(
    pyz,
    a.scripts,
    [],
    **exe_kwargs
)

coll = COLLECT(
    exe,
    a.binaries,
    a.datas,
    strip=True,
    upx=True,
    upx_exclude=[],
    name=f"{APP_NAME}",
)
