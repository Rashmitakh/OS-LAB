#include <stdio.h>

int main() {
    int n;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int burst[n], deadline[n], period[n], remaining[n];

    // Input
    for (int i = 0; i < n; i++) {
        printf("\nTask %d:\n", i + 1);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);

        printf("Deadline: ");
        scanf("%d", &deadline[i]);

        printf("Period: ");
        scanf("%d", &period[i]);

        remaining[i] = burst[i];
    }

    // Print Table (same as screenshot)
    printf("\nPID\tBurst\tDeadline\tPeriod\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\n",
               i + 1, burst[i], deadline[i], period[i]);
    }

    int time = 0, completed = 0;
    int hyper = 20;   // as in screenshot (fixed scheduling time)

    printf("\nScheduling occurs for %d ms\n\n", hyper);

    while (time < hyper) {

        int min_deadline = 9999;
        int selected = -1;

        // Select task with earliest deadline
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (deadline[i] < min_deadline) {
                    min_deadline = deadline[i];
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("%dms : CPU is idle.\n", time);
        } else {
            printf("%dms : Task %d is running.\n", time, selected + 1);
            remaining[selected]--;
        }

        // Reset task when period completes (like periodic tasks)
        for (int i = 0; i < n; i++) {
            if ((time + 1) % period[i] == 0) {
                remaining[i] = burst[i];
            }
        }

        time++;
    }

    return 0;
}
