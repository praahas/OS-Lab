#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int queue[20], head, n, i, j, seekTime = 0, maxTrack;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the maximum track number: ");
    scanf("%d", &maxTrack);

    printf("\n");

    int temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    int currentTrack = head;

    printf("Seek Sequence: ");

    // Scanning to the right
    for (i = head; i <= maxTrack; i++)
    {
        printf("%d ", i);
        seekTime += abs(currentTrack - i);
        currentTrack = i;
    }

    // Moving to the beginning
    printf("%d ", maxTrack);
    seekTime += abs(currentTrack - maxTrack);
    currentTrack = 0;

    // Scanning to the right again
    for (i = 0; i <= head; i++)
    {
        printf("%d ", i);
        seekTime += abs(currentTrack - i);
        currentTrack = i;
    }

    printf("\n\nTotal Seek Time: %d\n", seekTime);

    getch();
}