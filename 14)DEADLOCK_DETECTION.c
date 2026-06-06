/*
ALGORITHM : DEADLOCK DETECTION

LOGIC:
If a process's Request is less than or equal
to Available resources, execute it and release
its Allocation resources.

Repeat until all possible processes finish.
*/

#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resources: ");
    scanf("%d",&m);

    int alloc[n][m];
    int request[n][m];
    int avail[m];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    // Input Request Matrix
    printf("\nEnter Request Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&request[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");

    for(int j=0;j<m;j++)
    {
        scanf("%d",&avail[j]);
    }

    int finish[n];

    // Initially all unfinished
    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }

    int count=0;

    while(count<n)
    {
        int found=0;

        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int possible=1;

                // Check Request <= Available
                for(int j=0;j<m;j++)
                {
                    if(request[i][j] > avail[j])
                    {
                        possible=0;
                        break;
                    }
                }

                if(possible)
                {
                    printf("P%d Executed\n",i);

                    // Release allocated resources
                    for(int j=0;j<m;j++)
                    {
                        avail[j]+=alloc[i][j];
                    }

                    finish[i]=1;
                    count++;
                    found=1;
                }
            }
        }

        if(found==0)
        {
            break;
        }
    }

    if(count==n)
    {
        printf("\nNO DEADLOCK\n");
    }
    else
    {
        printf("\nDEADLOCK DETECTED\n");

        printf("Processes in Deadlock: ");

        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                printf("P%d ",i);
            }
        }

        printf("\n");
    }

    return 0;
}