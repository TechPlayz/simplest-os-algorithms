/*
ALGORITHM : OPTIMAL PAGE REPLACEMENT

LOGIC:
Replace the page whose next use
is farthest in the future.
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

    for(int i=0;i<f;i++)
    {
        frame[i]=-1;
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
                break;
            }
        }

        if(found==0)
        {
            int pos=-1;

            // Empty frame available
            for(int j=0;j<f;j++)
            {
                if(frame[j]==-1)
                {
                    pos=j;
                    break;
                }
            }

            // Find optimal victim
            if(pos==-1)
            {
                int farthest=-1;

                for(int j=0;j<f;j++)
                {
                    int nextUse=9999;

                    for(int k=i+1;k<n;k++)
                    {
                        if(frame[j]==page[k])
                        {
                            nextUse=k;
                            break;
                        }
                    }

                    if(nextUse > farthest)
                    {
                        farthest=nextUse;
                        pos=j;
                    }
                }
            }

            frame[pos]=page[i];
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