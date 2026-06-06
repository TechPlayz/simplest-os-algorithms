#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], rem[n];
    int ct[n], tat[n], wt[n], rt[n];
    int started[n];

    // Input
    for(int i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rem[i] = bt[i];
        started[i] = 0;
    }

    int completed = 0;
    int time = 0;

    while(completed < n)
    {
        int idx = -1;
        int minRem = 9999;

        // Find process with smallest remaining time
        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && rem[i] > 0)
            {
                if(rem[i] < minRem)
                {
                    minRem = rem[i];
                    idx = i;
                }
            }
        }

        // No process available
        if(idx == -1)
        {
            time++;
            continue;
        }

        // First time process gets CPU
        if(started[idx] == 0)
        {
            rt[idx] = time - at[idx];
            started[idx] = 1;
        }

        // Execute for 1 unit
        rem[idx]--;
        time++;

        // Process finished
        if(rem[idx] == 0)
        {
            ct[idx] = time;

            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            completed++;
        }
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