/*
ALGORITHM : FIFO PAGE REPLACEMENT

LOGIC:
When frame becomes full,
remove the page that entered first.
*/

#include <stdio.h>

int main()
{
    int n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int page[n];

    printf("Enter page reference string:\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&page[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d",&f);

    int frame[f];

    // Initially empty
    for(int i=0;i<f;i++)
    {
        frame[i] = -1;
    }

    int faults = 0;
    int hits = 0;
    int pos = 0;

    for(int i=0;i<n;i++)
    {
        int found = 0;

        // Check hit
        for(int j=0;j<f;j++)
        {
            if(frame[j] == page[i])
            {
                found = 1;
                hits++;
                break;
            }
        }

        // Page fault
        if(found == 0)
        {
            frame[pos] = page[i];

            pos = (pos + 1) % f;

            faults++;
        }

        // Display frames
        printf("\n%d : ",page[i]);

        for(int j=0;j<f;j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ",frame[j]);
        }
    }

    printf("\n\nPage Faults = %d",faults);
    printf("\nPage Hits = %d\n",hits);

    return 0;
}