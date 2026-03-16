#include <stdio.h>

int main() {
    int n, tq, i;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int pid[n], at[n], bt[n], rt[n];
    int wt[n], tat[n];
    int current_time = 0, completed = 0;

    for(i=0;i<n;i++){
        printf("\nProcess %d ID: ",i+1);
        scanf("%d",&pid[i]);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        rt[i] = bt[i];
    }

    while(completed < n){
        int executed = 0;

        for(i=0;i<n;i++){
            if(at[i] <= current_time && rt[i] > 0){

                executed = 1;

                if(rt[i] > tq){
                    current_time += tq;
                    rt[i] -= tq;
                }
                else{
                    current_time += rt[i];
                    tat[i] = current_time - at[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if(executed == 0){
            current_time++;
        }
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nPID\tAT\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],wt[i],tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f", avg_tat/n);

    return 0;
}
