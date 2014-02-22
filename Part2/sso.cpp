#include "sso.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define block 10000


        SoooLong::SoooLong()
        {
                sign='+';
                size=0;
                number=NULL;
        }

        int SoooLong::read(char *inputFile)
        {
                size=Reading(&number,inputFile,&sign);
                return 0;
        }

        int SoooLong::output(char *out)
        {
                FILE *inputFile;
		inputFile=fopen(out,"w");
                if (sign=='+')
                       fprintf(inputFile,"%s\n",number);
                else
                    fprintf(inputFile,"-%s\n",number);
                fclose(inputFile);
                return 0;
        }

        SoooLong SoooLong::operator+(SoooLong n1)
        {
                SoooLong n;
                unsigned char *del;
                        Invert(&number);
                        Invert(&n1.number);
                        del=n.number;
                        if ((sign=='+')&&(n1.sign=='+'))
                        {
                                n.number = Addition(&number,&n1.number);
                                n.sign='+';
                        }
                        if ((sign=='-')&&(n1.sign=='-'))
                        {
                                n.number = Addition(&number,&n1.number);
                                n.sign='-';
                        }
                        if ((sign=='+')&&(n1.sign=='-'))
                        {
                                if (Comparing(&number,&n1.number) == 1 || Comparing(&number,&n1.number) ==2)
                                        {
                                                n.number = Subtraction(&number,&n1.number);
                                                n.sign='+';
                                        }
                                        else
                                        {
                                                n.number = Subtraction(&n1.number,&number);
                                                n.sign='-';
                                        }
                        }
                        if ((sign=='-')&&(n1.sign=='+'))
                        {
                                if (Comparing(&number,&n1.number) == 1)
                                        {
                                                n.number = Subtraction(&number,&n1.number);
                                                n.sign='-';
                                        }
                                        else
                                        {
                                                n.number = Subtraction(&n1.number,&number);
                                                n.sign='+';
                                        }
                        }
                        n.size = MyStrlen(&n.number);
                        Invert(&number);
                        Invert(&n1.number);
                        Invert(&n.number);
                        if (del != NULL)
                                free(del);
                return n;
        }

        SoooLong SoooLong::operator-(SoooLong n1)
        {
                SoooLong n;
                        Invert(&number);
                        Invert(&n1.number);
                        if ((sign=='+')&&(n1.sign=='+'))
                        {
                                if (Comparing(&number,&n1.number) == 1 || Comparing(&number,&n1.number) == 2)
                                        {
                                                n.number = Subtraction(&number,&n1.number);
                                                n.sign='+';
                                        }
                                        else
                                        {
                                                n.number = Subtraction(&n1.number,&number);
                                                n.sign='-';
                                        }
                        }
                        if ((sign=='-')&&(n1.sign=='+'))
                        {
                                if (Comparing(&number,&n1.number) == 1)
                                        {
                                                n.number = Subtraction(&number,&n1.number);
                                                n.sign='-';
                                        }
                                        else
                                        {
                                                n.number = Subtraction(&n1.number,&number);
                                                n.sign='+';
                                        }
                        }
                        if ((sign=='+')&&(n1.sign=='-'))
                        {
                                n.number = Addition(&number,&n1.number);
                                n.sign='+';
                        }
                        if ((sign=='-')&&(n1.sign=='-'))
                        {
                                n.number = Addition(&number,&n1.number);
                                n.sign='-';
                        }
                        n.size = MyStrlen(&n.number);
                        Invert(&number);
                        Invert(&n1.number);
                        Invert(&n.number);
                return n;
        }

        SoooLong SoooLong::operator*(SoooLong n1)
        {
                SoooLong n;
                Invert(&number);
                        if (&number != &n1.number)
                                Invert(&n1.number);
                        if (((sign=='+')&&(n1.sign=='+'))||((sign=='-')&&(n1.sign=='-')))
                        {
                                n.number = Multiplying(&number,&n1.number);
                                n.sign='+';
                        }
                        else
                        {
                                n.number = Multiplying(&number,&n1.number);
                                n.sign='-';
                        }
                        n.size = MyStrlen(&n.number);
                        Invert(&number);
                        if (&number != &n1.number)
                                Invert(&n1.number);
                        Invert(&n.number);
                return n;
        }

        SoooLong SoooLong::operator/(SoooLong n1)
        {
                SoooLong n;
                unsigned char *ostatok;
                int lenOst;
                        if (((sign=='+')&&(n1.sign=='+'))||((sign=='-')&&(n1.sign=='-')))
                        {
                                n.number = Dividing(&number,&n1.number,&ostatok);
                                n.sign='+';
                        }
                        else
                        {
                                n.number = Dividing(&number,&n1.number,&ostatok);
                                n.sign='-';
                        }
                        n.size = MyStrlen(&n.number);
                return n;
        }

        SoooLong SoooLong::operator%(SoooLong n1)
        {
                SoooLong n;
                unsigned char *ostatok;
                int lenOst;
                Dividing(&number,&n1.number,&n.number);
                        n.size = MyStrlen(&n.number);
                return n;
        }

        SoooLong SoooLong::operator^(SoooLong n1)
        {
                SoooLong n;                
		Invert(&number);
                        Invert(&n1.number);
                        n.sign=sign;
                        n.number = Raising(&number,&n1.number,&n.sign);
                        n.size = MyStrlen(&n.number);
                        Invert(&number);
                        Invert(&n1.number);
                        Invert(&n.number);
                return n;
        }

        int SoooLong::MyStrlen(unsigned char **s)
        {
                int i=0;
                while(true)
                {
                        if ((*s)[i]=='\0')
                                break;
                        i++;
                }
                return i;
        }

        SoooLong SoooLong::operator=(SoooLong n1)
        {
                if ((*this).number != NULL)
                        free((*this).number);
                (*this).number = (unsigned char*) malloc(block);
                (*this).size=n1.size;
                for (int i=0;i<n1.size;i++)
                        (*this).number[i]=n1.number[i];
                (*this).number[(*this).size]='\0';
                (*this).sign=n1.sign;
                return *this;           
        }

        bool SoooLong::operator==(SoooLong n1)
        {
                int i;
		i=Comparing(&(*this).number,&n1.number);
		if (i==2)
                        return true;
                else
                        return false;                           
        }

        bool SoooLong::operator<(SoooLong n1)
        {
                int i;
                i=Comparing(&(*this).number,&n1.number);
                if (i==0)
                        return true;
                else
                        return false;
        }

        bool SoooLong::operator>(SoooLong n1)
        {
                int i;
		i=Comparing(&(*this).number,&n1.number);
                if (i==1)
                        return true;
                else
                        return false;
        }

        SoooLong SoooLong::operator=(const char* str)
        {
                int i;
                (*this).number=(unsigned char*)malloc(block);
                for (i=0;i<strlen(str);i++)
                        (*this).number[i]=str[i];
                (*this).number[i]='\0';
                (*this).size=MyStrlen(&(*this).number);
                return *this;
        }

        SoooLong::~SoooLong()
        {
                free(number);
        }

        SoooLong:: SoooLong(const SoooLong & n)
        {
                int i;
                (*this).sign=n.sign;
                (*this).size=n.size;
                (*this).number=(unsigned char*)malloc(block);
                for (i=0;i<n.size;i++)
                        (*this).number[i]=n.number[i];
                (*this).number[i]='\0';
        }
