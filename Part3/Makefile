all:
	swig -c++ -python SoooLong.i
	g++ -c -fPIC SoooLong_wrap.cxx -I/usr/include/python2.7
	g++ SoooLong_wrap.o -shared -fPIC -L. -lsso -Wl,-rpath,. -o _SoooLong.so

