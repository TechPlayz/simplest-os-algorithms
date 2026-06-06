/*
----------------------------------------------------
ALGORITHM : PRIORITY SCHEDULING
TYPE      : NON-PREEMPTIVE

ASSUMPTION:
Smaller priority number = Higher priority

FORMULAS:
TAT = CT - AT
WT  = TAT - BT
RT  = First CPU Allocation Time - AT

AIM:
To calculate CT, TAT, WT and RT using
Non-Preemptive Priority Scheduling.
----------------------------------------------------
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], pr[n];
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

        printf("Priority: ");
        scanf("%d",&pr[i]);

        done[i]=0;
    }

    int completed=0;
    int time=0;

    while(completed<n)
    {
        int idx=-1;
        int bestPriority=9999;

        // Find highest priority process
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && done[i]==0)
            {
                if(pr[i]<bestPriority)
                {
                    bestPriority=pr[i];
                    idx=i;
                }
            }
        }

        // No process available
        if(idx==-1)
        {
            time++;
            continue;
        }

        // First response
        rt[idx]=time-at[idx];

        // Execute completely
        time+=bt[idx];

        ct[idx]=time;

        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];

        done[idx]=1;
        completed++;
    }

    // Output
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],pr[i],
               ct[i],tat[i],wt[i],rt[i]);
    }

    return 0;
}