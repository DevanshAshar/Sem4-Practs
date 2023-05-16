#include<stdio.h>
#include<string.h>
char data[100],divisor[100],rem[100],ans[100];
int divs[100],dt[100];
void crc()
{
    for(int i=0;i<strlen(divisor);i++)
    divs[i]=divisor[i]-'0';
    for(int i=0;i<strlen(data);i++)
    dt[i]=data[i]-'0';
    for(int i=0;i<strlen(data)-strlen(divisor)+1;i++)
    {
        if(dt[i]==1)
        {
            for(int j=0;j<strlen(divisor);j++)
            dt[i+j]^=divs[j];
        }
    }
    int ct=0,k=strlen(divisor)-1,m=strlen(data)-1;
    while(ct!=strlen(divisor))
    {
        rem[k--]=dt[m--]+'0';
        ct++;
    }
}
void main()
{
    char ogdata[100];
    int ch;
    do
    {
    printf("1)Transmission\n2)Reception\n3)Exit");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:printf("Enter data");
            scanf("%s",&ogdata);
        printf("Enter divisor ");
        scanf("%s",&divisor);
        int l=strlen(ogdata);
        strcpy(data,ogdata);
        for(int i=0;i<strlen(divisor)-1;i++)
        data[l+i]='0';
        crc();
        strcpy(ans,ogdata);
        int k=strlen(ans);
        if(rem[0]=='1')
        ans[k++]=rem[0];
        for(int i=1;i<strlen(rem);i++)
        ans[k++]=rem[i];
        puts(ans);
        break;
    case 2:printf("Enter data ");
        scanf("%s",&data);
        printf("Enter divisor ");
        scanf("%s",&divisor);
        crc();
        int c=0;
        for(int i=0;i<strlen(rem);i++)
        {
            if(rem[i]=='0')
            c++;
        }
        if(c==strlen(rem))
        printf("No error");
        else
        printf("Errors");
        break;
    case 3:printf("Thenks");
    }
    }while(ch!=3);
}
