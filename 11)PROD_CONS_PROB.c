/*
ALGORITHM : PRODUCER CONSUMER PROBLEM

LOGIC:
Producer adds items into buffer.
Consumer removes items from buffer.
Buffer size cannot exceed maximum size.
*/

#include <stdio.h>

int main()
{
    int bufferSize;
    int choice;

    int buffer = 0; // current items in buffer

    printf("Enter Buffer Size: ");
    scanf("%d", &bufferSize);

    while(1)
    {
        printf("\n1. Produce");
        printf("\n2. Consume");
        printf("\n3. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            // Buffer full
            if(buffer == bufferSize)
            {
                printf("Buffer Full!\n");
            }
            else
            {
                buffer++;
                printf("Produced 1 Item\n");
                printf("Items in Buffer = %d\n", buffer);
            }
        }

        else if(choice == 2)
        {
            // Buffer empty
            if(buffer == 0)
            {
                printf("Buffer Empty!\n");
            }
            else
            {
                buffer--;
                printf("Consumed 1 Item\n");
                printf("Items in Buffer = %d\n", buffer);
            }
        }

        else if(choice == 3)
        {
            break;
        }

        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}