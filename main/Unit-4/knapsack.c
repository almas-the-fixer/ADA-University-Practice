#include <stdio.h>
/*
-----Stuff We Need and Why-----
capacity       =   Capacity of our 'Sack'.
weight[]       =   Represents the Weight of Items.
profit[]       =   Represents the Profit Gained from Items.
ratio[]        =   Represents the Weight : Profit Ratio.
rc             =   Represents Remaining Capacity.
tp             =   Represents Total Profit.
*/

float weight[10], profit[10], ratio[10];
int capacity, n;

void knapsack()
{
    int i;
    float tp = 0, rc = capacity;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > rc)
        {
            break;
        }
        else
        {
            tp = tp + profit[i];
            rc = rc - weight[i];
        }
    }
    if (i < n)
    {
        tp = tp + ((rc / weight[i]) * profit[i]);
    }
    printf("The Total Profit is: >> %.2f <<\n", tp);
}

void print(float arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf(" %.3f ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int i, j, temp;

    printf("Enter The Capacity: ");
    scanf("%d", &capacity);
    ;

    printf("Enter the no of Items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter The Item %d's Weight: ", i);
        scanf("%f", &weight[i]);

        printf("Enter the Item %d's Profit: ", i);
        scanf("%f", &profit[i]);
    }

    printf("Printing Weights: ");
    print(weight, n);

    printf("Printing Profits: ");
    print(profit, n);

    printf("Making Profit::Weight Ratios...\n");

    for (i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    printf("Printing Ratios: ");
    print(ratio, n);

    printf("Sorting In Descending Order In Terms of Ratio: \n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (ratio[i] > ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    printf("Printing the sorted Result: \n");
    print(ratio, n);
    knapsack();
}