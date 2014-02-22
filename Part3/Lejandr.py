import os, sys
import SoooLong as lib


a=lib.SoooLong()
b=lib.SoooLong()
c=lib.SoooLong()
Zero=lib.SoooLong()
a.read(sys.argv[1])
b.read(sys.argv[2])
Zero.read(sys.argv[4])
Zero.output("AAAAA.txt")
c=b
def GCD(a, b):
	while b!=Zero:
		c=a%b
		a=b
		b=c
		if c==Zero:
			return b
		else:
			return c
c=GCD(a, b)	
c.output(sys.argv[3])
print "Success"