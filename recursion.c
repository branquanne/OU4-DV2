#include <stdio.h>

int simple_recursion(int time_to_eat_burger_2, int time_to_eat_burger_1, int time_to_eat_burgers, int *time_drinking);

int main(void) {
  int time_to_eat_burger_1, time_to_eat_burger_2, time_to_eat_burgers;
  int num_burgers;
  int time_drinking = 0;

  while (scanf("%d %d %d", &time_to_eat_burger_1, &time_to_eat_burger_2, &time_to_eat_burgers) != EOF) {
    num_burgers = simple_recursion(time_to_eat_burger_2, time_to_eat_burger_1, time_to_eat_burgers, &time_drinking);

    if (time_drinking != 0) {
      printf("%d %d\n", num_burgers, time_drinking);
    } else {
      printf("%d\n", num_burgers);
    }
  }

  return 0;
}

int simple_recursion(int time_to_eat_burger_2, int time_to_eat_burger_1, int time_to_eat_burgers, int *time_drinking) {
  if (time_to_eat_burgers < 0) {
    return 0;
  }
  if (time_to_eat_burgers < time_to_eat_burger_2 && time_to_eat_burgers < time_to_eat_burger_1) {
    *time_drinking = time_to_eat_burgers;
    return 0;
  }

  int time_m = time_to_eat_burgers;
  int time_n = time_to_eat_burgers;

  int max_m = simple_recursion(time_to_eat_burger_2, time_to_eat_burger_1, time_to_eat_burgers - time_to_eat_burger_2, &time_m) + 1;
  int max_n = simple_recursion(time_to_eat_burger_2, time_to_eat_burger_1, time_to_eat_burgers - time_to_eat_burger_1, &time_n) + 1;

  if (max_m == max_n) {
    if (time_m < time_n) {
      *time_drinking = time_m;
    } else {
      *time_drinking = time_n;
    }
    return max_m;
  }

  if (time_m == time_n) {
    *time_drinking = time_m;
    if (max_m > max_n) {
      return max_m;
    } else {
      return max_n;
    }
  }

  if (time_m < time_n) {
    *time_drinking = time_m;
    return max_m;
  }

  *time_drinking = time_n;
  return max_n;
}