echo "Database"
rm -f database-generator
gcc database-generator.c -o database-generator
./database-generator

echo "Example"
rm -f example
gcc example.c AsaliVector.c AsaliMatrix.c Asali.c -lm -o example
./example
