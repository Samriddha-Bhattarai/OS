#include <stdio.h>

#define MAX 10

struct Task {
    int id;
    int arrival;
    int burst;
    int deadline;
    int remaining;
    int completed;
};

int main() {
    int n, time = 0, completed = 0;

    struct Task tasks[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Input tasks
    for (int i = 0; i < n; i++) {
        printf("\nTask %d:\n", i + 1);
        tasks[i].id = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &tasks[i].arrival);

        printf("Execution Time (Burst): ");
        scanf("%d", &tasks[i].burst);

        printf("Deadline: ");
        scanf("%d", &tasks[i].deadline);

        tasks[i].remaining = tasks[i].burst;
        tasks[i].completed = 0;
    }

    printf("\nEDF Scheduling Execution:\n");

    // Run until all tasks are completed
    while (completed < n) {
        int idx = -1;
        int earliest_deadline = 99999;

        // Find task with earliest deadline among ready tasks
        for (int i = 0; i < n; i++) {
            if (tasks[i].arrival <= time && tasks[i].remaining > 0) {
                if (tasks[i].deadline < earliest_deadline) {
                    earliest_deadline = tasks[i].deadline;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Execute selected task
            printf("Time %d -> Task %d\n", time, tasks[idx].id);

            tasks[idx].remaining--;
            time++;

            // If task finished
            if (tasks[idx].remaining == 0) {
                tasks[idx].completed = 1;
                completed++;

                if (time > tasks[idx].deadline) {
                    printf("Task %d MISSED its deadline!\n", tasks[idx].id);
                } else {
                    printf("Task %d completed within deadline.\n", tasks[idx].id);
                }
            }
        } else {
            // Idle CPU
            printf("Time %d -> Idle\n", time);
            time++;
        }
    }

    return 0;
}
