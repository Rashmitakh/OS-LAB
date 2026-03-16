#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, choice;
    int at[20], bt[20], pr[20], rt[20];
    int ct[20], tat[20], wt[20];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter priorities (1 for higher number means higher priority, 2 for lower number means higher priority): ");
    scanf("%d", &choice);

    printf("Enter priorities:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pr[i]);

    printf("Enter arrival times:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }

    while(completed < n){
        int selected = -1;

        for(i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0){
                if(selected == -1)
                    selected = i;
                else{
                    if(choice == 1){
                        if(pr[i] > pr[selected])
                            selected = i;
                    }
                    else{
                        if(pr[i] < pr[selected])
                            selected = i;
                    }
                }
            }
        }

        if(selected == -1){
            time++;
        }
        else{
            rt[selected]--;
            time++;

            if(rt[selected] == 0){
                ct[selected] = time;
                tat[selected] = ct[selected] - at[selected];
                wt[selected] = tat[selected] - bt[selected];

                avg_tat += tat[selected];
                avg_wt += wt[selected];

                completed++;
            }
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nPriority Scheduling (Pre-Emptive):\n");
    printf("PID\tPrior\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, pr[i], at[i], bt[i], ct[i], tat[i], wt[i], wt[i]);
    }

    printf("\nAverage turnaround time: %.6f ms\n", avg_tat);
    printf("Average waiting time: %.6f ms\n", avg_wt);

    return 0;
}
