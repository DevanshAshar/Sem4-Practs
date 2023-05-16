#include<stdio.h>
#include<string.h>
void main()
{
    char str[100],stuff[100];
    printf("Enter sentence ");
    gets(str);
    int i=0,j,r,ind=0,len;
    len=strlen(str);
    while(i<strlen(str))
    {
        r=rand()%8+2;
        if(r>len && len>0)
        r=len+1;
        len-=r-1;
        stuff[ind++]=r+'0';
        for(j=i;j<i+r-1;j++)
        stuff[ind++]=str[j];
        i=j;
    }
    puts(stuff);
}
