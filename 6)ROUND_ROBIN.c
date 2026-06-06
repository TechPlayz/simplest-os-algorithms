/*
----------------------------------------------------
ALGORITHM : ROUND ROBIN
TYPE      : PREEMPTIVE

FORMULAS:
TAT = CT - AT
WT  = TAT - BT
RT  = First CPU Allocation Time - AT

AIM:
To calculate CT, TAT, WT and RT using
Round Robin Scheduling.
----------------------------------------------------
*/

#include <stdio.h>

int main()
{
    int n, q;

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

        rem[i]=bt[i];
        started[i]=0;
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d",&q);

    int completed=0;
    int time=0;

    while(completed<n)
    {
        int found=0;

        // Visit each process one by one
        for(int i=0;i<n;i++)
        {
            if(at[i]<=time && rem[i]>0)
            {
                found=1;

                // First CPU allocation
                if(started[i]==0)
                {
                    rt[i]=time-at[i];
                    started[i]=1;
                }

                // Execute for quantum
                if(rem[i]>q)
                {
                    rem[i]-=q;
                    time+=q;
                }
                else
                {
                    time+=rem[i];

                    rem[i]=0;

                    ct[i]=time;

                    tat[i]=ct[i]-at[i];
                    wt[i]=tat[i]-bt[i];

                    completed++;
                }
            }
        }

        // CPU idle
        if(found==0)
            time++;
    }

    // Output
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1,at[i],bt[i],
               ct[i],tat[i],wt[i],rt[i]);
    }

    return 0;
}