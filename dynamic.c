#include <stdio.h>
#include <stdlib.h>

/*
 * File: dynamic.c
 *
 * Description: This program uses iteration (dynamic programming) to store the results of the subproblems in a table.
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

// Function declaration.
int dynamic(int m, int n, int *t);

int main(void)
{
    int m, n, t;

    while (scanf("%d %d %d", &m, &n, &t) != EOF)
    {
        int result = dynamic(m, n, &t);
        if (t == 0)
        {
            printf("%d\n", result);
        }
        else
        {
            printf("%d %d\n", result, t);
        }
    }

    return 0;
}

/*
 * Description: This function uses iteration (dynamic programming) to store the results of the subproblems in a table.
 *
 * The function then returns the solution with the least time wasted. If there are multiple solutions with the
 * same time wasted, the function returns the solution with the most burgers eaten.
 *
 * Input: - m: The time it takes to eat burger 1.
 * 	 	  - n: The time it takes to eat burger 2.
 * 	  	  - t: The time left to eat burgers.
 *
 * Output: Returns the number of burgers eaten.
 *
 */
int dynamic(int m, int n, int *t)
{
    int max_time = *t;

    int arr[max_time + 1];
    int remaining[max_time + 1];

    for (int i = 0; i <= max_time; i++)
    {
        arr[i] = 0;
        remaining[i] = i;
    }

    for (int time = 1; time <= max_time; time++)
    {
        if (time < m && time < n)
        {
            continue;
        }

        if (time >= m)
        {
            int prev_time = time - m;
            int burgers_with_m = arr[prev_time] + 1;
            int remaining_with_m = remaining[prev_time];

            arr[time] = burgers_with_m;
            remaining[time] = remaining_with_m;
        }

        if (time >= n)
        {
            int prev_time = time - n;
            int burgers_with_n = arr[prev_time] + 1;
            int remaining_with_n = remaining[prev_time];

            if (time % m > time % n)
            {
                arr[time] = burgers_with_n;
                remaining[time] = remaining_with_n;
            }
            else if (time % m == time % n && m >= n)
            {
                arr[time] = burgers_with_n;
                remaining[time] = remaining_with_n;
            }
        }
    }

    int result = arr[max_time];
    *t = remaining[max_time];

    return result;
}