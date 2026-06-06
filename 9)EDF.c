/*
ALGORITHM : EARLIEST DEADLINE FIRST (EDF)

LOGIC:
Task with earliest deadline gets highest priority.
Sort tasks according to deadline.
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
    int deadline[n];

    // Input
    for(int i=0;i<n;i++)
    {
        task[i]=i+1;

        printf("\nTask %d\n",i+1);

        printf("Execution Time: ");
        scanf("%d",&exec[i]);

        printf("Deadline: ");
        scanf("%d",&deadline[i]);
    }

    // Sort by deadline
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(deadline[j] < deadline[i])
            {
                int temp;

                temp=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=temp;

                temp=exec[i];
                exec[i]=exec[j];
                exec[j]=temp;

                temp=task[i];
                task[i]=task[j];
                task[j]=temp;
            }
        }
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