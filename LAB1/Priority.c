#include <stdio.h>
#include <limits.h>

struct Process {
    int pid, at, bt, pr, rt, ct, tat, wt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].pid = i + 1;
        p[i].rt = p[i].bt; // remaining time
    }

    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int highestPriority = INT_MAX;

        // Find highest priority process available
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (p[i].pr < highestPriority) {
                    highestPriority = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            p[idx].rt--;   // execute for 1 unit
            time++;

            // If process finishes
            if (p[idx].rt == 0) {
                completed++;
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
            }
        } else {
            time++; // CPU idle
        }
    }

    // Output
    float totalTAT = 0, totalWT = 0;

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].tat, p[i].wt);

        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}
