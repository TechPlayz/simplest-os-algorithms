/*
ALGORITHM : LRU PAGE REPLACEMENT

LOGIC:
When frame is full,
remove the least recently used page.
*/

#include <stdio.h>

int main()
{
    int n,f;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    int page[n];

    printf("Enter page reference string:\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d",&f);

    int frame[f];
    int recent[f];

    for(int i=0;i<f;i++)
    {
        frame[i]=-1;
        recent[i]=-1;
    }

    int faults=0,hits=0;

    for(int i=0;i<n;i++)
    {
        int found=0;

        // Check hit
        for(int j=0;j<f;j++)
        {
            if(frame[j]==page[i])
            {
                found=1;
                hits++;
                recent[j]=i;
                break;
            }
        }

        // Fault
        if(found==0)
        {
            int pos=0;

            // Find least recently used
            for(int j=1;j<f;j++)
            {
                if(recent[j] < recent[pos])
                {
                    pos=j;
                }
            }

            frame[pos]=page[i];
            recent[pos]=i;

            faults++;
        }

        printf("\n%d : ",page[i]);

        for(int j=0;j<f;j++)
        {
            if(frame[j]==-1)
                printf("- ");
            else
                printf("%d ",frame[j]);
        }
    }

    printf("\n\nPage Faults = %d",faults);
    printf("\nPage Hits = %d\n",hits);

    return 0;
}