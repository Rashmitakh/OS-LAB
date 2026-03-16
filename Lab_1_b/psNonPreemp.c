#include <stdio.h>

int main() {
    int n, i, current_time = 0, completed_count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], completed[n];
    float avg_wt = 0, avg_tat = 0;

    for(i=0;i<n;i++){
        printf("\nProcess %d ID: ", i+1);
        scanf("%d",&pid[i]);

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        completed[i] = 0;
    }

    while(completed_count < n){
        int highest_priority = 9999;
        int selected = -1;

        for(i=0;i<n;i++){
            if(at[i] <= current_time && completed[i]==0){
                if(pr[i] < highest_priority){
                    highest_priority = pr[i];
                    selected = i;
                }
            }
        }

        if(selected == -1){
            current_time++;
        }
        else{
            int start_time = current_time;

            ct[selected] = start_time + bt[selected];
            tat[selected] = ct[selected] - at[selected];
            wt[selected] = tat[selected] - bt[selected];

            avg_tat += tat[selected];
            avg_wt += wt[selected];

            current_time = ct[selected];

            completed[selected] = 1;
            completed_count++;
        }
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],pr[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
