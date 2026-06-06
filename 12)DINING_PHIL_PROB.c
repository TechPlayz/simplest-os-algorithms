/*
ALGORITHM : DINING PHILOSOPHERS PROBLEM

LOGIC:
A philosopher alternates between thinking and eating.
To eat, both left and right forks must be available.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of philosophers: ");
    scanf("%d",&n);

    int fork[n];

    // All forks available initially
    for(int i=0;i<n;i++)
    {
        fork[i]=1;
    }

    int p;

    while(1)
    {
        printf("\nEnter Philosopher Number (-1 to Exit): ");
        scanf("%d",&p);

        if(p==-1)
            break;

        int left = p;
        int right = (p+1)%n;

        printf("\nPhilosopher %d is THINKING\n",p);

        // Check fork availability
        if(fork[left] && fork[right])
        {
            fork[left]=0;
            fork[right]=0;

            printf("Fork %d Acquired\n",left);
            printf("Fork %d Acquired\n",right);

            printf("Philosopher %d is EATING\n",p);

            // Release forks
            fork[left]=1;
            fork[right]=1;

            printf("Fork %d Released\n",left);
            printf("Fork %d Released\n",right);

            printf("Philosopher %d is THINKING AGAIN\n",p);
        }
        else
        {
            printf("Forks Not Available\n");
            printf("Philosopher %d is WAITING\n",p);
        }
    }

    return 0;
}