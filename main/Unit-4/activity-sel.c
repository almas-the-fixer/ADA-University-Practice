#include <stdio.h>
/* Activity Selection Probllem */

int n, lsal, act[10], st[10], ft[10], sel_act[10], count = 0;
/*
What Each Variables are and what they do..
n           =   This is Just No of Activities.
lsal        =   This is short for Last selected Activity Location.. (index).
act[]       =   This is Activity Array. This just contain sequential No for Activities.
st[]        =   This is Start time array
ft[]        =   This is Finishing time array.
sel_act[]   =   This is Final answer array displays which activities are selected by algorithm.
count       =   Shows no of activities selected.
*/

/*
We Will be given Bunch of activities with start times and end times for each one,
And Our Goal is to get maximum activities scheduled in the given time slot....

Here are the Steps We Will Take:

Step 1: Sort The Activities in Ascending Order by their Finishing Time and also sort the act no ans st aswell to be consistent
Step 2: Select the first activity and then if Starting time for current activity is greater than or equal to the end time of last selected activity.
then select that activity and move on after updating lsal Variable
*/

/* Here is the Function for Above */
void asp()
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            sel_act[count] = act[i];
            lsal = i;
            count++;
        }
        else
        {
            if (st[i] >= ft[lsal])
            {
                sel_act[count] = act[i];
                lsal = i;
                count++;
            }
        }
    }
    printf("\n Selected Activities are: ");
    for (i = 0; i < count; i++)
    {
        printf(" %d ", sel_act[i]);
    }
    printf("\n");
}
void main()
{
    int i, j, temp;

    printf("Enter No of Activities: ");
    scanf("%d", &n);

    printf("Enter Activities along with start and finish times: ");

    for (i = 0; i < n; i++)
    {
        act[i] = i + 1;

        printf("Enter Activity %d 's Start Time: ", i + 1);
        scanf("%d", &st[i]);

        printf("Enter Activity %d 's Finishing Time: ", i + 1);
        scanf("%d", &ft[i]);
    }
    printf("---------------------\n");
    printf("Sorting Array in Ascending Order on basis of Finishing Time...\n");

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ft[i] > ft[j])
            {
                temp = ft[i];
                ft[i] = ft[j];
                ft[j] = temp;

                temp = st[i];
                st[i] = st[j];
                st[j] = temp;

                temp = act[i];
                act[i] = act[j];
                act[j] = temp;
            }
        }
    }

    printf("Printing the Ascended Sorted Finish Time Array: \n");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", ft[i]);
    }
    printf("\n");
    asp();
}