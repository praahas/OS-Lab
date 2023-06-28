#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int queue[20], head, n, i, seekTime = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\n");

    printf("Seek Sequence: ");

    for (i = 0; i < n; i++) {
        printf("%d ", queue[i]);
        seekTime += abs(head - queue[i]);
        head = queue[i];
    }

    printf("\n\nTotal Seek Time: %d\n", seekTime);

    getch();
}