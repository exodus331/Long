all:
	g++ -c -Wall test_cpp.cpp -o test_cpp.o
	g++ -c -fPIC sso.cpp -o sso.o
	g++ sso.o -g -shared -L. -lfso -Wl,-rpath,. -o libsso.so
	g++ test_cpp.o -o test_cpp -L. -lsso -Wl,-rpath,.

