#Apaga arquivos
rm -f build/out build/*.o

#Compila
gcc src/*.c test/*.c -c
mv *.o build/
gcc -o build/out build/*.o
./build/out