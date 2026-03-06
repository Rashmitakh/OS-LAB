//Write a C program to simulate the FCFS CPU scheduling algorithm to find turnaround time and waiting time.

#include <stdio.h>

int main() {
    int n,i;
    int at[10],bt[10],ct[10],tat[10],wt[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter AT and BT of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++){
        if(ct[i-1] < at[i])
            ct[i]=at[i]+bt[i];
        else
            ct[i]=ct[i-1]+bt[i];
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

    return 0;
}

/*
OUTPUT :
Enter number of processes: 4
Enter AT and BT of P1: 0
2
Enter AT and BT of P2: 3
4
Enter AT and BT of P3: 5
2
Enter AT and BT of P4: 1
7

P       AT      BT      CT      TAT     WT
P1      0       2       2       2       0
P2      3       4       7       4       0
P3      5       2       9       4       2
P4      1       7       16      15      8
*/
