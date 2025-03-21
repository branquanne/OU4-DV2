#include <stdio.h>

int simple_recursion(int m, int n, int t, int *time_drinking);

int main(void) {
  int n, m, t;
  int num_burgers;
  int time_drinking = 0;

  while (scanf("%d %d %d", &n, &m, &t) != EOF) {
    num_burgers = simple_recursion(m, n, t, &time_drinking);

    if (time_drinking != 0) {
      printf("%d %d\n", num_burgers, time_drinking);
    } else {
      printf("%d\n", num_burgers);
    }
  }

  return 0;
}

int simple_recursion(int m, int n, int t, int *time_drinking) {
  if (t < 0) {
    return 0;
  }
  if (t < m && t < n) {
    *time_drinking = t;
    return 0;
  }

  int time_m = t;
  int time_n = t;

  int max_m = simple_recursion(m, n, t - m, &time_m) + 1;
  int max_n = simple_recursion(m, n, t - n, &time_n) + 1;

  if (max_m == max_n) {
    *time_drinking = (time_m < time_n) ? time_m : time_n;
    return max_m;
  }

  if (time_m == time_n) {
    *time_drinking = time_m;
    return (max_m > max_n) ? max_m : max_n;
  }

  if (time_m < time_n) {
    *time_drinking = time_m;
    return max_m;
  }

  *time_drinking = time_n;
  return max_n;
}