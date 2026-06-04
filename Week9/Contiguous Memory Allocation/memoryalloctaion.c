#include <stdio.h>

void printResult(int a[], int p[], int n, char name[])
{
    int i;

    printf("\n--- %s ---\n", name);
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, p[i]);

        if(a[i] != -1)
            printf("%d\n", a[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void firstFit(int b[], int m, int p[], int n)
{
    int a[10], i, j;

    for(i = 0; i < n; i++)
        a[i] = -1;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(b[j] >= p[i])
            {
                a[i] = j;
                b[j] -= p[i];
                break;
            }
        }
    }

    printResult(a, p, n, "First Fit");
}

void bestFit(int b[], int m, int p[], int n)
{
    int a[10], i, j, best;

    for(i = 0; i < n; i++)
        a[i] = -1;

    for(i = 0; i < n; i++)
    {
        best = -1;

        for(j = 0; j < m; j++)
        {
            if(b[j] >= p[i])
            {
                if(best == -1 || b[j] < b[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            a[i] = best;
            b[best] -= p[i];
        }
    }

    printResult(a, p, n, "Best Fit");
}

void worstFit(int b[], int m, int p[], int n)
{
    int a[10], i, j, worst;

    for(i = 0; i < n; i++)
        a[i] = -1;

    for(i = 0; i < n; i++)
    {
        worst = -1;

        for(j = 0; j < m; j++)
        {
            if(b[j] >= p[i])
            {
                if(worst == -1 || b[j] > b[worst])
                    worst = j;
            }
        }

        if(worst != -1)
        {
            a[i] = worst;
            b[worst] -= p[i];
        }
    }

    printResult(a, p, n, "Worst Fit");
}

int main()
{
    int m, n, i;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int b[10], b1[10], b2[10], b3[10];

    printf("Enter sizes of %d memory blocks:\n", m);

    for(i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
        b1[i] = b2[i] = b3[i] = b[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[10];

    printf("Enter sizes of %d processes:\n", n);

    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    firstFit(b1, m, p, n);
    bestFit(b2, m, p, n);
    worstFit(b3, m, p, n);

    return 0;
}
