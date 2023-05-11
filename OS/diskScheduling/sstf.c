#include <stdio.h>
#include<stdlib.h>
int main() {
    int head;
    int data[100],v[100],prev[100],diff;
    int hl,ll,n,i,least,ct=0,st=0,curr,minInd;
    printf("Enter lower and higher limit ");
    scanf("%d %d",&ll,&hl);
    printf("Enter no. of tracks ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter track %d ",i+1);
        scanf("%d",&data[i]);
    }
    printf("enter head ");
    scanf("%d",&head);
    for(i=0;i<n;i++)
    v[i]=0;
    curr=head;
    while(ct<n)
    {
        int least=9999;
        for(i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                diff=abs(curr-data[i]);
                if(diff<least)
                {
                    least=diff;
                    minInd=i;
                }
            }
        }
    st+=least;
    curr=data[minInd];
    v[minInd]=1;
    ct++;
 }
 printf("Seek time is %d ",st);
} 
