#include <stdio.h>

int main() {
    int n, h, pos[10], choice;
    int i, j;

    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &h);

    for (i = 0; i < h; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, n);
        scanf("%d", &pos[i]);
    }

    while (1) {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3)
            break;

        if (choice == 1) {
            printf("Allow one philosopher to eat at any time\n");

            for (i = 0; i < h; i++) {
                // Print waiting for all
                for (j = 0; j < h; j++) {
                    printf("P %d is waiting\n", pos[j]);
                }

                printf("P %d is granted to eat\n", pos[i]);
                printf("P %d has finished eating\n", pos[i]);
            }
        }

        else if (choice == 2) {
            printf("Allow two philosophers to eat at a time\n");

            for (i = 0; i < h; i++) {
                for (j = i + 1; j < h; j++) {

                    // Check they are not adjacent
                    if (pos[i] != pos[j] &&
                        (pos[i] % n + 1) != pos[j] &&
                        (pos[j] % n + 1) != pos[i]) {

                        printf("P %d and P %d are granted to eat\n", pos[i], pos[j]);
                        printf("P %d and P %d have finished eating\n", pos[i], pos[j]);
                        break;
                    }
                }
            }
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
