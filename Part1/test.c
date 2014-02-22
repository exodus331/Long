#include <stdio.h>
#include <stdlib.h>
#include "test.h"

int main(int argc, char *argv[])
{
    char *inputFirst,*inputSecond,*inputThird; 
    FILE *output;
    int lenghtFirst,lenghtSecond,i,binary,module,lenghtModule;
    unsigned char *numberOne,*numberTwo,*ostatok,*numModule;
        unsigned char znak1,znak2,znak3;
        if (argc < 5 )
        {
                printf("\nEnter correct parameters\n");
                return 0;
        }
        
        if (argc == 5)
        {
                        module=1;
                        inputThird=argv[5];
                        lenghtModule = Reading(&numModule,inputThird,&znak3);
        }
        if (argc < 5)
                module=0;
        inputFirst =argv[1];
        inputSecond=argv[3];
	output = fopen(argv[4],"w");
        switch(argv[2][0])
        {
                case '+' :
                                lenghtFirst = Reading(&numberOne,inputFirst,&znak1);
                                lenghtSecond = Reading(&numberTwo,inputSecond,&znak2);
                                Invert(&numberOne);
                                Invert(&numberTwo);
                                if ((znak1=='+')&&(znak2=='+'))
                                {
                                        numberOne = Addition(&numberOne,&numberTwo);
                                        Invert(&numberOne);
                                        fprintf(output,"%s",numberOne);
                                        break;
                                }
                                if ((znak1=='-')&&(znak2=='-'))
                                {
                                        numberOne = Addition(&numberOne,&numberTwo);
                                        Invert(&numberOne);
                                        fprintf(output,"-%s",numberOne);
                                        break;
                                }
                                if ((znak1=='+')&&(znak2=='-'))
                                {
                                        if (Comparing(&numberOne,&numberTwo) == 1)
                                        {
                                                numberOne = Subtraction(&numberOne,&numberTwo);
                                                Invert(&numberOne);
                                                fprintf(output,"%s",numberOne);
                                        }
                                        else
                                        {
                                                numberOne = Subtraction(&numberTwo,&numberOne);
                                                Invert(&numberOne);
                                                fprintf(output,"-%s",numberOne);
                                        }
                                        break;
                                }
                                if ((znak1=='-')&&(znak2=='+'))
                                {
                                        if (Comparing(&numberOne,&numberTwo) == 1)
                                        {
                                                numberOne = Subtraction(&numberOne,&numberTwo);
                                                Invert(&numberOne);
                                                fprintf(output,"-%s",numberOne);
                                        }
                                        else
                                        {
                                                numberOne = Subtraction(&numberTwo,&numberOne);
                                                Invert(&numberOne);
                                                fprintf(output,"%s",numberOne);
                                        }
                                        break;
                                }
                        break;

                case '-' :
                                lenghtFirst = Reading(&numberOne,inputFirst,&znak1);
                                lenghtSecond = Reading(&numberTwo,inputSecond,&znak2);
                                Invert(&numberOne);
                                Invert(&numberTwo);
                                if ((znak1=='+')&&(znak2=='+'))
                                {
                                        if (Comparing(&numberOne,&numberTwo) == 1)
                                        {
                                                numberOne = Subtraction(&numberOne,&numberTwo);
                                                Invert(&numberOne);
                                                fprintf(output,"%s",numberOne);
                                        }
                                        else
                                        {
                                                numberOne = Subtraction(&numberTwo,&numberOne);
                                                Invert(&numberOne);
                                                fprintf(output,"-%s",numberOne);
                                        }
                                        break;
                                }
                                if ((znak1=='-')&&(znak2=='-'))
                                {
                                        if (Comparing(&numberOne,&numberTwo) == 1)
                                        {
                                                numberOne = Subtraction(&numberOne,&numberTwo);
                                                Invert(&numberOne);
                                                fprintf(output,"-%s",numberOne);
                                        }
                                        else
                                        {
                                                numberOne = Subtraction(&numberTwo,&numberOne);
                                                Invert(&numberOne);
                                                fprintf(output,"%s",numberOne);
                                        }
                                        break;
                                }
                                if ((znak1=='+')&&(znak2=='-'))
                                {
                                        numberOne = Addition(&numberOne,&numberTwo);
                                        Invert(&numberOne);
                                        fprintf(output,"%s",numberOne);
                                        break;
                                }
                                if ((znak1=='-')&&(znak2=='+'))
                                {
                                        numberOne = Addition(&numberOne,&numberTwo);
                                        Invert(&numberOne);
                                        fprintf(output,"-%s",numberOne);
                                        break;
                                }
                        
                        break;

                case '*' :
                   		lenghtFirst = Reading(&numberOne,inputFirst,&znak1);
                                lenghtSecond = Reading(&numberTwo,inputSecond,&znak2);
                                Invert(&numberOne);
                                Invert(&numberTwo);
                                if (((znak1=='+')&&(znak2=='+'))||((znak1=='-')&&(znak2=='-')))
                                {
                                        numberOne=Multiplying(&numberOne,&numberTwo);
                                        Invert(&numberOne);
                                        fprintf(output,"%s",numberOne);
                                }
                                else
                                {
                                        numberOne=Multiplying(&numberOne,&numberTwo);
                                        Invert(&numberOne);
                                        fprintf(output,"-%s",numberOne);
                                }
                       
                        break;

                case '/' :
                                lenghtFirst = Reading(&numberOne,inputFirst,&znak1);
                                lenghtSecond = Reading(&numberTwo,inputSecond,&znak2);
                                if (((znak1=='+')&&(znak2=='+'))||((znak1=='-')&&(znak2=='-')))
                                {
                                        fprintf(output,"%s",Dividing(&numberOne,&numberTwo,&ostatok));
                                }
                                else
                                {
                                        fprintf(output,"-%s",Dividing(&numberOne,&numberTwo,&ostatok));
                                }
                        
                        break;

                case '%' :
                                lenghtFirst = Reading(&numberOne,inputFirst,&znak1);
                                lenghtSecond = Reading(&numberTwo,inputSecond,&znak2);
                                Dividing(&numberOne,&numberTwo,&ostatok);
                                fprintf(output,"%s",ostatok);
                        break;

                case '^' :
				lenghtFirst = Reading(&numberOne,inputFirst,&znak1);
                                lenghtSecond = Reading(&numberTwo,inputSecond,&znak2);
                                Invert(&numberOne);
                                Invert(&numberTwo);
                                numberOne=Raising(&numberOne,&numberTwo,&znak1);
                                Invert(&numberOne);
                                if (znak1=='+')
                                        fprintf(output,"%s",numberOne);
                                else
                                        fprintf(output,"-%s",numberOne);
                        break;
                default:
                        break;
        }

    fclose(output);

        if (module)
        {
                output = fopen(argv[4],"w");
                        Dividing(&numberOne,&numModule,&ostatok);
                        fprintf(output,"%s",ostatok);
                fclose(output);
            
        }
    return 0;
}
