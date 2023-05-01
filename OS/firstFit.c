#include <stdio.h>

void main()
{
    int n;
    int n_mem;
    int mem_loc[100];
    printf("Enter no of memory partitions\n");
    scanf("%d",&n_mem);
    int mem_sizes[] = {200, 400, 600, 500, 300, 250};
    int process_sizes[] = {357, 210, 468, 491};
    printf("Enter no of processes\n");
    scanf("%d",&n);
    int j=0;
    for(int i=0;i<n_mem;i++)
    {
        if(process_sizes[j] <= mem_sizes[i])
        {
            printf("\nfor %d , %d  %d",j,process_sizes[j],mem_sizes[i]);
            mem_loc[j] = j+1;
            j++;
        }
    }
    printf("\nFinal\n");
    for(int i =0;i<n;i++)
    {
        if(mem_loc[i])
        {
            printf("Process size = %d goes in location %d\n",process_sizes[i],mem_loc[i]);
        }
        else{printf("%d not allocated to memory",process_sizes[i]);}
    }

}
