/*
ALGORITHM : BANKER'S ALGORITHM

LOGIC:
Need = Max - Allocation

Find a process whose Need is less than or equal
to Available resources.

Execute the process and release its resources.

Repeat until all processes finish.
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
    int max[n][m];
    int need[n][m];
    int avail[m];

    // Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    // Max Matrix
    printf("\nEnter Max Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    // Available Resources
    printf("\nEnter Available Resources:\n");

    for(int j=0;j<m;j++)
    {
        scanf("%d",&avail[j]);
    }

    // Calculate Need Matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int finish[n];

    for(int i=0;i<n;i++)
    {
        finish[i]=0;
    }

    int safeSeq[n];
    int count=0;

    while(count < n)
    {
        int found=0;

        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int possible=1;

                // Check Need <= Available
                for(int j=0;j<m;j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        possible=0;
                        break;
                    }
                }

                if(possible)
                {
                    // Release resources
                    for(int j=0;j<m;j++)
                    {
                        avail[j]+=alloc[i][j];
                    }

                    safeSeq[count]=i;

                    count++;
                    finish[i]=1;
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
        printf("\nSAFE STATE\n");

        printf("Safe Sequence:\n");

        for(int i=0;i<n;i++)
        {
            printf("P%d",safeSeq[i]);

            if(i!=n-1)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nUNSAFE STATE\n");
    }

    return 0;
}