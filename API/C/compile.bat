del database-generator.exe
cl database-generator.c /std:c11 /TC /Fe:database-generator.exe

del example.exe
cl /std:c11 /TC example.c AsaliVector.c AsaliMatrix.c Asali.c /Fe:example.exe
