gcc -c main.c -o build/main.o
gcc -c matrix.c -o build/lib/matrix.o
gcc build/main.o build/lib/matrix.o -o build/app
