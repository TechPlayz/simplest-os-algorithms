#include <stdio.h>

int main()
{
    int n,i,t;

    printf("Enter number of tasks: ");
    scanf("%d",&n);

    int bt[n],period[n],rt[n];

    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);

    printf("Enter Period:\n");
    for(i=0;i<n;i++)
        scanf("%d",&period[i]);

    for(i=0;i<n;i++)
        rt[i]=0;

    printf("\nTime -> Task\n");

    for(t=0;t<20;t++)
    {
        for(i=0;i<n;i++)
        {
            if(t%period[i]==0)
                rt[i]=bt[i];
        }

        int task=-1;

        for(i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
                if(task==-1 || period[i]<period[task])
                    task=i;
            }
        }

        if(task==-1)
            printf("%d -> Idle\n",t);
        else
        {
            printf("%d -> T%d\n",t,task+1);
            rt[task]--;
        }
    }

    return 0;
}