#include <stdio.h>
#include <string.h>

#define MAX 20

/*
    Implementing Longest Common Subsequence In Unit 3: Dynamic Programming.
*/
char s1[MAX], s2[MAX], ans[MAX];
int s1len, s2len, count, max_value, ans_table[MAX][MAX];

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

void lcs()
{
    int i, j;

    // initialise ans table with all zeroes
    for (i = 0; i <= s1len; i++)
    {
        for (j = 0; j <= s2len; j++)
        {
            ans_table[i][j] = 0;
        }
    }

    // filling ans table values
    for (i = 1; i <= s1len; i++)
    {
        for (j = 1; j <= s2len; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans_table[i][j] = ans_table[i - 1][j - 1] + 1;
            }
            else
            {
                ans_table[i][j] = max(ans_table[i - 1][j], ans_table[i][j - 1]);
            }
        }
        max_value = ans_table[i][j-1];
    }

    // Print ans Table
    for (i = 0; i <= s1len; i++)
    {
        for(j = 0; j <= s2len; j++)
        {
            printf(" %d ", ans_table[i][j]);
        }
        printf("\n");
    }

    // Backtracking MAIN PART
    for (i = s1len; i >= 1; i --)
    {
        for(j = s2len; j >=1; j --)
        {
            if(max_value == ans_table[i][j] && max_value != ans_table[i][j-1])
            {
                ans[max_value-1] = s2[j-1];
                max_value -= 1;
                j = 0;
            }
        }
    }
    printf("\nLCS = %s\n", ans);
    
}

int main()
{

    // Take Input Strings
    printf("Enter String 1: ");
    scanf("%s", s1);

    printf("Enter String 2: ");
    scanf("%s", s2);

    // Get String Length
    s1len = strlen(s1);
    s2len = strlen(s2);
    lcs();
    return 0;
}