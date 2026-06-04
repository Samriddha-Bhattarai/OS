#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], finish[10] = {0};
    int safeSeq[10];


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

    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    /* Calculate Need Matrix */
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > available[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(k = 0; k < m; k++)
                    {
                        available[k] += allocation[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            break;
        }
    }

    if(count == n)
    {
        printf("\nSystem is in SAFE STATE\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++)
        {
            printf("P%d ", safeSeq[i]);
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is NOT in safe state.\n");
    }

    return 0;
}
