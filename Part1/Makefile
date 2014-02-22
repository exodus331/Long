all:
	gcc -c -fPIC fso.c -o fso.o
	gcc -shared -o libfso.so fso.o
	gcc -c test.c -o test.o
	gcc test.o -L. -Wl,-rpath,. -lfso -o test 

