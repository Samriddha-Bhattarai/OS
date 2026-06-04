#include <stdio.h>

int main()
{
    int n, m, i, j;
    int allocation[10][10], request[10][10];
    int available[10], work[10];
    int finish[10];


    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    /* Initialize Work */
    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }

    /* Initialize Finish */
    for(i = 0; i < n; i++)
    {
        int zero = 1;

        for(j = 0; j < m; j++)
        {
            if(allocation[i][j] != 0)
            {
                zero = 0;
                break;
            }
        }

        if(zero)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    while(1)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    int deadlock = 0;

    printf("\nDeadlocked Processes:\n");

    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            printf("P%d\n", i);
            deadlock = 1;
        }
    }

    if(deadlock == 0)
    {
        printf("No Deadlock Detected\n");
    }

    return 0;
}
