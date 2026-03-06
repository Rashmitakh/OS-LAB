//Write a C program to simulate the SJF preemptive CPU scheduling algorithm to find turnaround time and waiting time.

#include <stdio.h>

int main() {
    int n,i,time=0,completed=0,smallest;
    int at[10],bt[10],ct[10],tat[10],wt[10],done[10]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    while(completed<n){
        smallest=-1;

        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(smallest==-1 || bt[i]<bt[smallest])
                    smallest=i;
            }
        }

        if(smallest==-1)
            time++;
        else{
            time+=bt[smallest];
            ct[smallest]=time;
            tat[smallest]=ct[smallest]-at[smallest];
            wt[smallest]=tat[smallest]-bt[smallest];
            done[smallest]=1;
            completed++;
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
Enter AT and BT of P1: 1
4
Enter AT and BT of P2: 2
5
Enter AT and BT of P3: 7
2
Enter AT and BT of P4: 8
9

P       AT      BT      CT      TAT     WT
P1      1       4       5       4       0
P2      2       5       10      8       3
P3      7       2       12      5       3
P4      8       9       21      13      4
*/
