/*
ALGORITHM : WORST FIT

LOGIC:
Allocate process to the largest block
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
        int worst=-1;

        // Find largest suitable block
        for(int j=0;j<nb;j++)
        {
            if(block[j] >= process[i])
            {
                if(worst==-1 || block[j] > block[worst])
                {
                    worst=j;
                }
            }
        }

        if(worst!=-1)
        {
            printf("Process %d -> Block %d\n",
                   i+1,worst+1);

            block[worst]-=process[i];
        }
        else
        {
            printf("Process %d -> Not Allocated\n",
                   i+1);
        }
    }

    return 0;
}