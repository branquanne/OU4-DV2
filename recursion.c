#include <stdio.h>

/*
 * File: recursion.c
 *
 * Description: This program uses brute force recursion to explore all possible paths to the problem.
 * The program then returns the solution with the least time wasted. If there are multiple solutions
 * with the same time wasted, the program returns the solution with the most burgers eaten.
 *
 * Input: The input consists of three integers m, n, and t (0 < m, n, t < 10000) on a single line.
 *
 * Output: The output consists of two integers, the first integer is the number of burgers
 *         eaten and the second integer is the time wasted (if there is any).
 *
 * Author: Henrik Röjvall & Bran Quanne & Gustav Thor
 *
 * Date: 2025-03-21
 *
 */

// Function declaration.
int simple_recursion(int m, int n, int time_left, int *time_drinking);

int main(void)
{
    int m, n, t, burgers_eaten, time_drinking;

    while (scanf("%d %d %d", &m, &n, &t) != EOF)
    {
        time_drinking = t;
        burgers_eaten = simple_recursion(m, n, t, &time_drinking);

        if (time_drinking > 0)
        {
            printf("%d %d\n", burgers_eaten, time_drinking);
        }
        else
        {
            printf("%d\n", burgers_eaten);
        }
    }

    return 0;
}

/*
 * Description: This function uses brute force recursion to explore all possible paths to the problem.
 *
 * The function then returns the solution with the least time wasted. If there are multiple solutions with the
 * same time wasted, the function returns the solution with the most burgers eaten.
 *
 * Input: - m: The time it takes to eat burger 1.
 *        - n: The time it takes to eat burger 2.
 *        - time_left: The time left to eat burgers.
 *        - time_drinking: The time left to drink.
 *
 * Output: Returns the number of burgers eaten.
 *
 */
int simple_recursion(int m, int n, int time_left, int *time_drinking)
{
    if (time_left < m && time_left < n)
    {
        *time_drinking = time_left;
        return 0;
    }

    int remaining_time_1 = time_left, remaining_time_2 = time_left;
    int result_burger_1 = 0, result_burger_2 = 0;

    if (time_left >= m)
    {
        result_burger_1 = 1 + simple_recursion(m, n, time_left - m, &remaining_time_1);
    }

    if (time_left >= n)
    {
        result_burger_2 = 1 + simple_recursion(m, n, time_left - n, &remaining_time_2);
    }

    if (remaining_time_1 < remaining_time_2 || (remaining_time_1 == remaining_time_2 && result_burger_1 > result_burger_2))
    {
        *time_drinking = remaining_time_1;
        return result_burger_1;
    }
    else
    {
        *time_drinking = remaining_time_2;
        return result_burger_2;
    }
}