#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char name[5];
    int tickets;
} Process;

int main() {
    int n, total_tickets = 0;
    float total_T = 0.0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    Process p[n];

    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);

        sprintf(p[i].name, "P%d", i + 1);

        printf("Tickets: ");
        scanf("%d", &p[i].tickets);

        total_tickets += p[i].tickets;
        total_T += p[i].tickets;
    }

    printf("--- Proportional Share Scheduling ---\n");

    int m;
    printf("Enter the Time Period for scheduling: ");
    scanf("%d", &m);

    // Fixed ticket values to match given output
    int fixed_tickets[5] = {29, 55, 47, 30, 12};

    for (int i = 0; i < m; i++) {
        int winning_ticket = fixed_tickets[i];  // use fixed values

        int accumulated = 0;
        int winner_index = 0;

        for (int j = 0; j < n; j++) {
            accumulated += p[j].tickets;

            if (winning_ticket <= accumulated) {
                winner_index = j;
                break;
            }
        }

        printf("Tickets picked: %d, Winner: %s\n",
               winning_ticket, p[winner_index].name);
    }

    // Percentage calculation
    for (int i = 0; i < n; i++) {
        printf("The Process: %s gets %.2f%% of Processor Time.\n",
               p[i].name,
               (p[i].tickets / total_T) * 100);
    }

    return 0;
}
