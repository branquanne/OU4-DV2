#include <stdio.h>

struct memo_table {
    int burgers_eaten;
    int time_left;
};

int memoization(int n, int m, int time_left, struct memo_table mtable[]);

int main(void) {

    int n, m, t;

    while (scanf("%d %d %d", &n, &m, &t) != EOF) {

        struct memo_table memo_table[t + 1];

        for (int i = 0; i <= t; i++) {
            memo_table[i].burgers_eaten = -1;
            memo_table[i].time_left = -1;
        }

        memoization(n, m, t, memo_table);

        if (memo_table[t].time_left > 0) {
            printf("%d %d\n", memo_table[t].burgers_eaten, memo_table[t].time_left);
        } else {
            printf("%d\n", memo_table[t].burgers_eaten);
        }
    }

    return 0;
}

int memoization(int n, int m, int time_left, struct memo_table mtable[]) {

    if (time_left < n && time_left < m) {
        mtable[time_left].time_left = time_left;
        mtable[time_left].burgers_eaten = 0;
        return 0;
    }

    if (mtable[time_left].burgers_eaten != -1) {
        return mtable[time_left].burgers_eaten;
    }

    int remaining_time_1 = time_left, remaining_time_2 = time_left;
    int result_burger_1 = 0, result_burger_2 = 0;

    if (time_left >= n) {
        result_burger_1 = 1 + memoization(n, m, time_left - n, mtable);
        remaining_time_1 = mtable[time_left - n].time_left;
    }

    if (time_left >= m) {
        result_burger_2 = 1 + memoization(n, m, time_left - m, mtable);
        remaining_time_2 = mtable[time_left - m].time_left;
    }

    if (remaining_time_1 < remaining_time_2 || (remaining_time_1 == remaining_time_2 && result_burger_1 > result_burger_2)) {
        mtable[time_left].time_left = remaining_time_1;
        mtable[time_left].burgers_eaten = result_burger_1;
    } else {
        mtable[time_left].time_left = remaining_time_2;
        mtable[time_left].burgers_eaten = result_burger_2;
    }

    return mtable[time_left].burgers_eaten;
}