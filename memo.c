#include <stdio.h>

/*
 * File: memo.c
 *
 * Description: This program uses recursion with memoization to store the results of the subproblems in a table.
 * The program then returns the solution with the least time wasted. If there are multiple solutions with the
 * same time wasted, the program returns the solution with the most burgers eaten.
 *
 * Input: The input consists of three integers m, n, and t (0 < m, n, t < 10000) on a single line.
 *
 * Output: The output consists of two integers, the first integer is the number of burgers eaten and the second integer is the time wasted(if there is any).
 *
 * Author: Henrik Röjvall & Bran Quanne & Gustav Thor
 *
 * Date: 2025-03-21
 *
 */

// Structure representing the memo table.
struct memo_table
{
    int burgers_eaten;  // Number of burgers eaten.
    int time_left;      // Time left.
};

// Function declaration.
int memoization(int m, int n, int time_left, struct memo_table mtable[]);

int main(void)
{
    int m, n, t;

    while (scanf("%d %d %d", &m, &n, &t) != EOF)
    {
        struct memo_table memo_table[t + 1];

        for (int i = 0; i <= t; i++)
        {
            memo_table[i].burgers_eaten = -1;
            memo_table[i].time_left = -1;
        }

        memoization(m, n, t, memo_table);

        if (memo_table[t].time_left > 0)
        {
            printf("%d %d\n", memo_table[t].burgers_eaten, memo_table[t].time_left);
        }
        else
        {
            printf("%d\n", memo_table[t].burgers_eaten);
        }
    }

    return 0;
}

/*
 * Description: This function uses recursion with memoization to store the results of the subproblems in a table.
 *
 * The function then returns the solution with the least time wasted. If there are multiple solutions with the
 * same time wasted, the function returns the solution with the most burgers eaten.
 *
 * Input: - m: The time it takes to eat burger 1.
 *        - n: The time it takes to eat burger 2.
 *        - time_left: The time left.
 *        - mtable: The memo table.
 *
 * Output: Returns the number of burgers eaten.
 *
 */
int memoization(int m, int n, int time_left, struct memo_table mtable[])
{
    if (time_left < m && time_left < n)
    {
        mtable[time_left].time_left = time_left;
        mtable[time_left].burgers_eaten = 0;
        return 0;
    }

    if (mtable[time_left].burgers_eaten != -1)
    {
        return mtable[time_left].burgers_eaten;
    }

    int remaining_time_1 = time_left, remaining_time_2 = time_left;
    int result_burger_1 = 0, result_burger_2 = 0;

    if (time_left >= m)
    {
        result_burger_1 = 1 + memoization(m, n, time_left - m, mtable);
        remaining_time_1 = mtable[time_left - m].time_left;
    }

    if (time_left >= n)
    {
        result_burger_2 = 1 + memoization(m, n, time_left - n, mtable);
        remaining_time_2 = mtable[time_left - n].time_left;
    }

    if (remaining_time_1 < remaining_time_2 || (remaining_time_1 == remaining_time_2 && result_burger_1 > result_burger_2))
    {
        mtable[time_left].time_left = remaining_time_1;
        mtable[time_left].burgers_eaten = result_burger_1;
    }
    else
    {
        mtable[time_left].time_left = remaining_time_2;
        mtable[time_left].burgers_eaten = result_burger_2;
    }

    return mtable[time_left].burgers_eaten;
}