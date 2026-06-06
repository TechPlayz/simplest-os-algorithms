#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];
    int ct[n], tat[n], wt[n], rt[n];

    // Input
    for(int i=0;i<n;i++)
    {
        printf("\nProcess %d\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    int time = 0;

    // FCFS execution
    for(int i=0;i<n;i++)
    {
        // CPU waits if process has not arrived yet
        if(time < at[i])
            time = at[i];

        // Execute process completely
        time = time + bt[i];

        ct[i] = time;

        // Formulas
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        // In FCFS response time = waiting time
        rt[i] = wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}