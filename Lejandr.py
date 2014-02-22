import os, sys
import SoooLong as lib


a=lib.SoooLong()
p=lib.SoooLong()
c=lib.SoooLong()
Zero=lib.SoooLong()
One=lib.SoooLong()
Two=lib.SoooLong()
Four=lib.SoooLong()
Eight=lib.SoooLong()
Buf=lib.SoooLong()
Buf2=lib.SoooLong()
Buf3=lib.SoooLong()
Buf4=lib.SoooLong()
Min=lib.SoooLong()
a.read(sys.argv[1])
p.read(sys.argv[2])
One.read(sys.argv[5])
Min.read(sys.argv[4])
Zero=One-One
Two=One+One
Four=Two+Two
Eight=Four+Four
if a==One:
	c=One
elif a%Two==Zero:
	c=(((a/Two)^((p - One)/Two))%p)*((Min)^((p^Two-One)/Eight))
elif a%Two==One and a!=One:
	Buf=(((p%a)^((a - One)/Two))%a)
	Buf2=(a-One)*(p-One)
	Buf3=Buf2/Four
	Buf4=Min^Buf3
	c=Buf*(Buf4)
else:
	print "Error"
c.output(sys.argv[3])
print "Success"
