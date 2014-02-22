#include <stdio.h>
#include <string.h>
#include "test_cpp.h"

int main(int argc, char *argv[])
{
        char *inputFirst,*inputSecond,*out,*inputThird;
        SoooLong n1,n2,res,n4;
        int module;
        if (argc < 5 )
        {
            printf("\nEnter correct parameters\n");
            return 0;
        }
        if (argc == 6)
        {
                        module=1;
                        inputThird=argv[5];
                        n4.read(inputThird);
        }
        if ( argc < 6)
                module=0;

        inputFirst = argv[1];
        inputSecond = argv[3];
        out = argv[4];
        n1.read(inputFirst);
        n2.read(inputSecond);
        switch(argv[2][0])
        {
                case '+' :                      
                        res=(n1+n2);
                        if (module)
                                res=res%n4;
                        break;
                case '-' :
                        res=n1-n2;
                        if (module)
                                res=res%n4;
                        break;
                case '*' :
                        res=n1*n2;
                        if (module)
                                res=res%n4;
                        break;
                case '/' :
                        res=n1/n2;
                        if (module)
                                res=res%n4;
                        break;
                case '%' :
                        res=n1%n2;
                        if (module)
                                res=res%n4;
                        break;
                case '^' :
                        res=n1^n2;
                        if (module)
                                res=res%n4;
                        break;

                default:
                        break;
        }
        
        res.output(out);

}
