#include <stdio.h>
/*
    Implementing Rod Cutting in Unit 3: Dynamic Programming
*/
int length[10], profit[10], size, max_profit, ans[10][10], n;

int max(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}

void rc()
{
    int i, j;

    // Initialize ans table with zeroes
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= size; j++)
        {
            ans[i][j] = 0;
        }
    }

    // Fill Answer Table
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= size; j++)
        {
            if (length[i] <= j)
            {
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - length[i]] + profit[i]);
            }
            else
            {
                ans[i][j] = ans[i - 1][j];
            }
        }
        max_profit = ans[i][j - 1];
    }

    // Printing Answer Table
    printf("Answer Table: \n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= size; j++)
        {
            printf(" %d ", ans[i][j]);
        }
        printf("\n");
    }

    // Backtracking
    for (i = n; i >= 1; i--)
    {
        for (j = size; j >= 1; j--)
        {
            if (max_profit == ans[i][j] && max_profit != ans[i - 1][j])
            {
                printf(" %d ,", i);
                max_profit = max_profit - profit[i];
                j = 0;
            }
        }
    }
}

void main()
{

    int i;

    printf("Enter Number of Pieces: ");
    scanf("%d", &n);

    length[0] = 0;
    profit[0] = 0;

    for (i = 1; i <= n; i++)
    {
        printf("Enter Length of Piece %d: ", i);
        scanf("%d", &length[i]);

        printf("Enter Profit of Piece %d: ", i);
        scanf("%d", &profit[i]);
    }

    printf("Enter Size of rod: ");
    scanf("%d", &size);

    rc();
}