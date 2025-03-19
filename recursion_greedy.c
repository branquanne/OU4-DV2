#include <stdio.h>

void recursive(int time_n, int time_m, int *time_t, int *tot_burgers);

int main(void) {
  int time_n, time_m, time_t, tot_burgers;

  while (scanf("%d %d %d", &time_n, &time_m, &time_t) != EOF) {

    tot_burgers = 0;

    recursive(time_n, time_m, &time_t, &tot_burgers);

    if (time_t == 0) {
      printf("%d\n", tot_burgers);
    } else {
      printf("%d %d\n", tot_burgers, time_t);
    }
  }

  return 0;
}

void recursive(int time_n, int time_m, int *time_t, int *tot_burgers) {

  if (*time_t < time_n && *time_t < time_m) {
    return;
  }

  if ((*time_t % time_n) < (*time_t % time_m)) {
    *time_t -= time_n;
    (*tot_burgers)++;
    recursive(time_n, time_m, time_t, tot_burgers);
  } else if ((*time_t % time_m) < (*time_t % time_n)) {
    *time_t -= time_m;
    (*tot_burgers)++;
    recursive(time_n, time_m, time_t, tot_burgers);
  } else {
    if (time_n < time_m) {
      *time_t -= time_n;
      (*tot_burgers)++;
      recursive(time_n, time_m, time_t, tot_burgers);
    } else {
      *time_t -= time_m;
      (*tot_burgers)++;
      recursive(time_n, time_m, time_t, tot_burgers);
    }
  }
}