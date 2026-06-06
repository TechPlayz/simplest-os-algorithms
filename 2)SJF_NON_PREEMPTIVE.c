#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n];
    int ct[n], tat[n], wt[n], rt[n];
    int done[n];

    // Input
    for(int i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        done[i] = 0; // not completed
    }

    int completed = 0;
    int time = 0;

    while(completed < n)
    {
        int idx = -1;
        int minBT = 9999;

        // Find shortest arrived process
        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && done[i]==0)
            {
                if(bt[i] < minBT)
                {
                    minBT = bt[i];
                    idx = i;
                }
            }
        }

        // No process has arrived
        if(idx == -1)
        {
            time++;
            continue;
        }

        // First CPU allocation
        rt[idx] = time - at[idx];

        // Run completely
        time += bt[idx];

        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = 1;
        completed++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],
               ct[i],tat[i],wt[i],rt[i]);
    }

    return 0;
}