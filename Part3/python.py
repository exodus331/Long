import sys
import SoooLong as lib


first=lib.SoooLong()
second=lib.SoooLong()
third=lib.SoooLong()
fourth=lib.SoooLong()

arg=5
try:
        a=sys.argv[5]
        arg=5
except:
        arg=4

if arg==5:
        module=True
        fourth.read(sys.argv[5])
else:
        module=False

        first.read(sys.argv[1])
        second.read(sys.argv[3])

sign=sys.argv[2]

if sign=="+":
        third=first+second
elif sign=="-":
        third=first-second
elif sign=="*":
        third=first*second
elif sign=="/":
        third=first/second
elif sign=="%":
        third=first%second
elif sign=="^":
        third=first^second

if module==True:
        third=third%fourth;

third.output(sys.argv[4])
print "Success"

