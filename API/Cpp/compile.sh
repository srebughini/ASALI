mkdir -p shared

rm -f database-generator
g++ -std=c++11 -Wall -Wextra database-generator.cpp -o database-generator

./database-generator

rm -f example
g++ -std=c++11 -Wall -Wextra Asali.cpp example.cpp -o example
