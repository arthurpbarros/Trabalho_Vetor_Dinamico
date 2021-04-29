#Apaga arquivos
rm -f build/out build/*.o

#Compila
gcc src/arrayInt.c test/main.c -c
mv *.o build/
gcc -o build/out build/*.o -Wall
./build/out