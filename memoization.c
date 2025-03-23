#include <stdio.h>

struct memo_table {
    int burgers_eaten;
    int t;
};

int memoization(int n, int m, int t, struct memo_table mtable[]);

int main(void) {
    int n, m, t;

    while (scanf("%d %d %d", &n, &m, &t) != EOF) {
        struct memo_table memo_table[t + 1];

        for (int i = 0; i <= t; i++) {
            memo_table[i].burgers_eaten = -1;
            memo_table[i].t = -1;
        }

        memoization(n, m, t, memo_table);

        if (memo_table[t].t > 0) {
            printf("%d %d\n", memo_table[t].burgers_eaten, memo_table[t].t);
        } else {
            printf("%d\n", memo_table[t].burgers_eaten);
        }
    }

    return 0;
}

int memoization(int n, int m, int t, struct memo_table mtable[]) {
    if (t < n && t < m) {
        mtable[t].t = t;
        mtable[t].burgers_eaten = 0;
        return 0;
    }

    if (mtable[t].burgers_eaten != -1) {
        return mtable[t].burgers_eaten;
    }

    int remaining_time_1 = t, remaining_time_2 = t;
    int result_burger_1 = 0, result_burger_2 = 0;

    if (t >= n) {
        result_burger_1 = 1 + memoization(n, m, t - n, mtable);
        remaining_time_1 = mtable[t - n].t;
    }

    if (t >= m) {
        result_burger_2 = 1 + memoization(n, m, t - m, mtable);
        remaining_time_2 = mtable[t - m].t;
    }

    if (remaining_time_1 < remaining_time_2 || (remaining_time_1 == remaining_time_2 && result_burger_1 > result_burger_2)) {
        mtable[t].t = remaining_time_1;
        mtable[t].burgers_eaten = result_burger_1;
    } else {
        mtable[t].t = remaining_time_2;
        mtable[t].burgers_eaten = result_burger_2;
    }

    return mtable[t].burgers_eaten;
}
