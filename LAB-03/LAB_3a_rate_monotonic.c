#include <math.h>
#include <stdio.h>

// Function to calculate GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    int burst[n], period[n];

    printf("Enter the CPU burst times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }

    printf("Enter the time periods:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &period[i]);
    }

    // Calculate LCM
    int hyper = period[0];
    for (int i = 1; i < n; i++) {
        hyper = lcm(hyper, period[i]);
    }

    printf("LCM=%d\n\n", hyper);

    printf("Rate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, burst[i], period[i]);
    }

    // Utilization calculation
    float U = 0;
    for (int i = 0; i < n; i++) {
        U += (float)burst[i] / period[i];
    }

    // Liu & Layland bound
    float bound = n * (pow(2, (1.0 / n)) - 1);

    printf("\n%f <= %f => %s\n",
           U, bound, (U <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n\n", hyper);

    int remaining[n];
    for (int i = 0; i < n; i++) remaining[i] = 0;

    for (int t = 0; t < hyper; t++) {

        // Release tasks
        for (int i = 0; i < n; i++) {
            if (t % period[i] == 0) {
                remaining[i] = burst[i];
            }
        }

        int selected = -1;

        // Select highest priority (smallest period)
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                selected = i;
                break;
            }
        }

        if (selected != -1) {
            printf("%dms onwards: Process %d running\n", t, selected + 1);
            remaining[selected]--;
        } else {
            printf("%dms onwards: CPU is idle\n", t);
        }
    }

    return 0;
}
