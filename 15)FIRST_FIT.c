/*
ALGORITHM : FIRST FIT

LOGIC:
Allocate each process to the first memory block
that is large enough.
*/

#include <stdio.h>

int main()
{
    int nb,np;

    printf("Enter number of memory blocks: ");
    scanf("%d",&nb);

    int block[nb];

    for(int i=0;i<nb;i++)
    {
        printf("Block %d Size: ",i+1);
        scanf("%d",&block[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d",&np);

    int process[np];

    for(int i=0;i<np;i++)
    {
        printf("Process %d Size: ",i+1);
        scanf("%d",&process[i]);
    }

    for(int i=0;i<np;i++)
    {
        int allocated=0;

        // Check blocks one by one
        for(int j=0;j<nb;j++)
        {
            if(block[j] >= process[i])
            {
                printf("Process %d -> Block %d\n",
                       i+1,j+1);

                block[j]-=process[i];
                allocated=1;

                break;
            }
        }

        if(!allocated)
        {
            printf("Process %d -> Not Allocated\n",
                   i+1);
        }
    }

    return 0;
}