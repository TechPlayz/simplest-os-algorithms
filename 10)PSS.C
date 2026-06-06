/*
ALGORITHM : PROPORTIONAL SHARE SCHEDULING

LOGIC:
CPU time is distributed according to shares.
More shares means more CPU allocation.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of tasks: ");
    scanf("%d",&n);

    int share[n];
    int total=0;

    // Input shares
    for(int i=0;i<n;i++)
    {
        printf("Enter shares for Task %d: ",i+1);
        scanf("%d",&share[i]);

        total += share[i];
    }

    printf("\nCPU Allocation:\n");

    for(int i=0;i<n;i++)
    {
        float percent;

        percent = ((float)share[i] / total) * 100;

        printf("Task %d -> %.2f%% CPU\n",
               i+1, percent);
    }

    return 0;
}