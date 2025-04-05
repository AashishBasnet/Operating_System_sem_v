#include <stdio.h>

int main(){
        int n,burst[30],wait[30],turnaround[30],ct[30],i,j;
        float avgw=0,avgt=0;
        printf("Enter total no of processes(max = 30)");
        scanf("%d",&n);
        printf("\nEnter the process burst time:");
        for (i=0;i<n;i++){
                printf("p[%d]:",i+1);
                scanf("%d",&burst[i]);
        }

        for(i=0;i<=n;i++){
                wait[i] = 0;
                for(j=0;j<i;j++)
                        wait[i] +=burst[j];
        }
        for (i=0;i<=n;i++){
                printf("%d\n",wait[i]);
        }

        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
        for(i=0; i<n; i++)
        {
                turnaround[i] = burst[i] + wait[i];

                avgw += wait[i];
                avgt += turnaround[i];
                printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,burst[i],wait[i],turnaround[i]);

        }
        avgw /= i;
        avgt /= i;
        printf("\nAverage Waiting Time: %.2f",avgw);
        printf("\nAverage Turnaround Time: %.2f",avgt);
        return 0;
}