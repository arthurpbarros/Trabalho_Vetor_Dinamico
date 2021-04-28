#Apaga arquivos
rm -f build/out build/*.o

#Apaga arquivos
rm -f build/out build/*.o

#Compila
gcc src/listInt.c test/main2.c -c
mv *.o build/
gcc -o build/out2 build/*.o -Wall
./build/out2