/*
ALGORITHM : MULTI LEVEL QUEUE SCHEDULING

LOGIC:
Processes are divided into two queues.
System queue gets executed first.
FCFS is used inside each queue.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int bt[n], type[n];

    printf("\nType 1 = System Process");
    printf("\nType 2 = User Process\n");

    for(int i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Type: ");
        scanf("%d",&type[i]);
    }

    int time=0;

    printf("\nExecution Order:\n");

    // Execute System Queue first
    for(int i=0;i<n;i++)
    {
        if(type[i]==1)
        {
            printf("P%d : %d -> %d\n",
                   i+1,time,time+bt[i]);

            time+=bt[i];
        }
    }

    // Execute User Queue
    for(int i=0;i<n;i++)
    {
        if(type[i]==2)
        {
            printf("P%d : %d -> %d\n",
                   i+1,time,time+bt[i]);

            time+=bt[i];
        }
    }

    return 0;
}