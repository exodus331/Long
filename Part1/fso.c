#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define block 10000

int Reading(unsigned char **number,char *file,unsigned char *znak)
{
    unsigned char Char;
    FILE *inputFile=fopen(file,"r");
    int i = 0,it;
    int k = 1;
        (*number) = (unsigned char *)malloc(block);
        fscanf(inputFile,"%c",&Char);
        if (Char == '-')
                (*znak)='-'; 
        else
        {
                (*znak)='+';
                fseek(inputFile,0,SEEK_SET);
        }
    while (fscanf(inputFile,"%c",&Char) > 0)
    {
          if (i == block*k-5)
          {
            k++;
            (*number) = (unsigned char *)realloc((*number),block*k*sizeof(char));
          }
          if ((Char <48) || (Char > 57))
              break;
          (*number)[i] = Char;
          i++;
    }
    (*number)[i]='\0';
    fclose(inputFile);
    return i;
}



int Comparing(unsigned char **numberOne,unsigned char **numberTwo) 
{
        int i;
        if (strlen((*numberOne)) > strlen ((*numberTwo)))
                return 1;
        if (strlen((*numberOne)) < strlen ((*numberTwo)))
                return 0;
        for(i=0;i<strlen((*numberOne));i++)
        {
                if ((*numberOne)[i] > (*numberTwo)[i])
                        return 1;
                if ((*numberOne)[i] < (*numberTwo)[i])
                        return 0;
        }
        return 2;       
}


int Invert(unsigned char **number)
{
        char Char;
        int it,len=strlen((*number))-1;
        for (it=0;it<=len/2;it++)
                {
                        Char = (*number)[it];
                        (*number)[it] = (*number)[len-it];
                        (*number)[len-it] = Char;
                }
        return 0;
}

unsigned char *Addition(unsigned char **numberOne,unsigned char **numberTwo)
{
    unsigned char *result;
    int temp,i,carry = 0;
    int k = 1;
    result = (unsigned char*) malloc(block*sizeof(char));
    i=0;
    while(1)
    {
        if ((*numberOne)[i] == '\0')
        {
            temp=1;
            break;
        }
        if ((*numberTwo)[i] == '\0')
        {
            temp=2;
            break;
        }
        temp = (*numberOne)[i] + (*numberTwo)[i]-96;
        result[i] = (temp+carry) % 10+48;
        carry = (temp+carry) / 10;
        i++;
        if (i == block*k-5)
        {
          k++;
          result = (unsigned char *)realloc(result,block*k*sizeof(char));
        }
    }
    if (temp == 1)
        while(1)
        {
            if ((*numberTwo)[i] == '\0')
            {
                break;
            }
            result[i] = ((*numberTwo)[i]+carry-48) % 10 + 48;
            carry = ((*numberTwo)[i]+carry-48) / 10;
            i++;
            if (i == block*k-5)
            {
              k++;
              result = (unsigned char *)realloc(result,block*k*sizeof(char));
            }
        }
    else
        while(1)
        {
            if ((*numberOne)[i] == '\0')
            {
                break;
            }
            result[i] = ((*numberOne)[i]+carry-48) % 10 + 48;
            carry = ((*numberOne)[i]+carry-48) / 10;
            i++;
            if (i == block*k-5)
            {
              k++;
              result = (unsigned char *)realloc(result,block*k*sizeof(char));
            }
        }
    if (carry != 0)
    {
        result[i]=carry+48;
        result[i+1]='\0';
    }
    else
        result[i]='\0';
    return result;
}

unsigned char *Subtraction(unsigned char **numberOne,unsigned char **numberTwo)
{
    unsigned char *result;
    int i = 0, carry = 0;
    result = (unsigned char*) malloc(strlen(*numberOne)+5);
    while(1)
    {
        if((*numberTwo)[i] == '\0')
        {
            break;
        }
        if (((*numberOne)[i] - carry) >= (*numberTwo)[i])
        {
            result[i] = (*numberOne)[i]-carry-(*numberTwo)[i] +48;
            carry = 0;
        }
        else
        {
            result[i] = (*numberOne)[i]-carry-(*numberTwo)[i] +58;
            carry = 1;
        }
        i++;
    }
    while(1)
    {
        if((*numberOne)[i] == '\0')
        {
            break;
        }
        if (((*numberOne)[i] - carry) >= 48)
        {
            result[i] = (*numberOne)[i]-carry;
            carry = 0;
        }
        else
        {
            result[i] = (*numberOne)[i]-carry+10;
            carry = 1;
        }
        i++;
    }
    for (i=i-1;i>0;i--)
        if (result[i] != '0')
            break;
    result[i+1]='\0';
    return result;
}

unsigned char *Multiplying(unsigned char **numberOne,unsigned char **numberTwo)
{
    unsigned char *result,*help,*del;
    int i,j,carry,temp;
    result = (unsigned char*)malloc(block);
        for (i=0;i<strlen((*numberOne))*strlen((*numberTwo))+5;i++)
                result[i]='0';
        i=0;
    help = (unsigned char*)malloc(strlen((*numberOne))*strlen((*numberTwo))+5);
    while (1)
    {
        if ((*numberTwo)[i] == '\0')
            break;
        for (j=0;j<i;j++)
            help[j]='0';
        j=0;carry=0;
        while(1)
        {
            if ((*numberOne)[j] == '\0')
                break;
            temp = ((*numberTwo)[i]-48)*((*numberOne)[j]-48);
            help[i+j] = (temp+carry)%10+48;
            carry = (temp+carry) / 10;
            j++;
        }
                if (carry != 0)
                {
                        help[i+j] = carry+48;
                        help[i+j+1]='\0';
                }
                else
                        help[i+j] = '\0';
                if (i != 0)
                {
                        del=result;
                        result = Addition(&result,&help);
                        free(del);
                }
                else
                        strncpy(result,help,strlen(help)+1);
        i++;
    }
        free(help);
    return result;
}

unsigned char *Dividing(unsigned char **numberOne,unsigned char **numberTwo,unsigned char **ostatok)
{
        int i,j,k,q;
        unsigned char *delimoe,*delitel,*answer;
        delimoe = (unsigned char*)malloc(2*strlen((*numberOne)));
        delitel = (unsigned char*)malloc(2*strlen((*numberTwo)));
        answer = (unsigned char*)malloc(2*strlen((*numberOne)));
        q=0;
        i=0;j=0;
        while(1)
        {
                if ((*numberOne)[i]=='\0')
                        break;
                if ((j != 0) || ((*numberOne)[i] != '0'))
                {
                        delimoe[j]=(*numberOne)[i];
                        delimoe[j+1]='\0';
                }
                else
                        j--;
                if (Comparing(&delimoe,&(*numberTwo)) > 0)
                {
                        for (k=0;k<=strlen((*numberTwo));k++)
                                delitel[k]=(*numberTwo)[k];
                        k=1;
                        while(1)
                        {
                                if (Comparing(&delitel,&delimoe) > 0)
                                {
                                        if (strcmp(delitel,delimoe) != 0)
                                        {
                                        if (strlen(delitel) != 1)
                                                Invert(&delitel);
                                        if ((strlen(*numberTwo)) != 1)
                                                Invert(&(*numberTwo));
                                        delitel = Subtraction(&delitel,&(*numberTwo));
                                        if (strlen(delitel) != 1)
                                                Invert(&delitel);
                                        if ((strlen(*numberTwo)) != 1)
                                                Invert(&(*numberTwo));
                                        k--;
                                        }
                                        answer[q]=k+48;
                                        q++;
                                        break;
                                }
                                else
                                {
                                        if (strlen(delitel) != 1)
                                                Invert(&delitel);
                                        if ((strlen(*numberTwo)) != 1)
                                                Invert(&(*numberTwo));
                                        delitel=Addition(&delitel,&(*numberTwo));
                                        if (strlen(delitel) != 1)
                                                Invert(&delitel);
                                        if ((strlen(*numberTwo)) != 1)
                                                Invert(&(*numberTwo));
                                        k++;
                                }
                        }
                        if (strlen(delimoe) != 1)
                                Invert(&delimoe);
                        if (strlen(delitel) != 1)
                                Invert(&delitel);
                        delimoe = Subtraction(&delimoe,&delitel);
                        if (strlen(delimoe) != 1)
                                Invert(&delimoe);
                        if (strlen(delitel) != 1)
                                Invert(&delitel);
                        j=strlen(delimoe);
                        if ((strlen(delimoe) == 1) && (delimoe[0]=='0'))
                                j=0;
                        i++;
                }
                else
                {
                        if (q != 0)
                        {
                                answer[q]='0';
                                q++;
                        }
                        j++;
                        i++;
                }

        }
        if (q != 0)
                answer[q]='\0';
        else
        {
                answer[0]='0';
                answer[1]='\0';
        }
        if (j != 0)
                (*ostatok)=delimoe;
        else
        {
                (*ostatok)=delimoe;
                (*ostatok)[1]='\0';
        }

        return answer;
}

unsigned char *Raising(unsigned char **numberOne,unsigned char **numberTwo,unsigned char *znak)
{
        int i,flag;
        unsigned  char *firstNumber,*st,*incr;
        firstNumber = (unsigned char*)malloc(strlen((*numberOne)+2));
        st = (unsigned char*)malloc(block);
        incr = (unsigned char*)malloc(4);
        st[0]='0';
        st[1]='\0';
        incr[0]='1';
        incr[1]='\0';
        if ((*znak)=='+')
                flag=0;
        else
                flag=1;
        strcpy(firstNumber,(*numberOne));
        while(1)
        {
                st = Addition(&st,&incr);
                if (strcmp(st,(*numberTwo)) == 0)
                        break;
                if (flag==1)
                        if ((*znak)=='+')
                                (*znak)='-';
                        else
                                (*znak)='+';
                firstNumber = Multiplying(&(*numberOne),&firstNumber);
        }
        return firstNumber;
}
