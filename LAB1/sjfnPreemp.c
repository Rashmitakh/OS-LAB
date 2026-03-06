//Write a C program to simulate the SJF preemptive CPU scheduling algorithm to find turnaround time and waiting time.

#include <stdio.h>

int main() {
    int n,i,time=0,completed=0,smallest;
    int at[10],bt[10],rt[10],ct[10],tat[10],wt[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    while(completed<n){
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(smallest==-1 || rt[i]<rt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
            time++;
        else{
            rt[smallest]--;
            time++;

            if(rt[smallest]==0){
                ct[smallest]=time;
                tat[smallest]=ct[smallest]-at[smallest];
                wt[smallest]=tat[smallest]-bt[smallest];
                completed++;
            }
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    return 0;
}

/*
OUTPUT :
Enter number of processes: 4
Enter AT and BT of P1: 2
1
Enter AT and BT of P2: 4
2
Enter AT and BT of P3: 5
3
Enter AT and BT of P4: 6
4

P       AT      BT      CT      TAT     WT
P1      2       1       3       1       0
P2      4       2       6       2       0
P3      5       3       9       4       1
P4      6       4       13      7       3
*/
