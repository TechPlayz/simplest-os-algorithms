/*
ALGORITHM : RATE MONOTONIC SCHEDULING (RMS)

LOGIC:
Task with smaller period gets higher priority.
Sort tasks according to period.
Display execution order.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of tasks: ");
    scanf("%d",&n);

    int task[n];
    int exec[n];
    int period[n];

    // Input
    for(int i=0;i<n;i++)
    {
        task[i]=i+1;

        printf("\nTask %d\n",i+1);

        printf("Execution Time: ");
        scanf("%d",&exec[i]);

        printf("Period: ");
        scanf("%d",&period[i]);
    }

    // Sort by period
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(period[j] < period[i])
            {
                int temp;

                temp=period[i];
                period[i]=period[j];
                period[j]=temp;

                temp=exec[i];
                exec[i]=exec[j];
                exec[j]=temp;

                temp=task[i];
                task[i]=task[j];
                task[j]=temp;
            }
        }
    }

    printf("\n\nPriority Order:\n");

    for(int i=0;i<n;i++)
    {
        printf("Task %d (Period=%d)\n",
               task[i],period[i]);
    }

    printf("\nExecution Order:\n");

    for(int i=0;i<n;i++)
    {
        printf("T%d",task[i]);

        if(i!=n-1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}