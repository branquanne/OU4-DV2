#include <stdio.h>
#include <stdlib.h>

int homer_dynamic(int m, int n, int *t);

int main(void) {
  int m, n, t;

  while (scanf("%d %d %d", &m, &n, &t) != EOF) {
    int result = homer_dynamic(m, n, &t);
    if (t == 0) {
      printf("%d\n", result);
    } else {
      printf("%d %d\n", result, t);
    }
  }

  return 0;
}

int homer_dynamic(int m, int n, int *t) {
  int max_time = *t;

  int arr[max_time + 1];
  int remaining[max_time + 1];

  for (int i = 0; i <= max_time; i++) {
    arr[i] = 0;
    remaining[i] = i;
  }

  for (int time = 1; time <= max_time; time++) {
    if (time < m && time < n) {
      continue;
    }

    if (time >= m) {
      int prev_time = time - m;
      int burgers_with_m = arr[prev_time] + 1;
      int remaining_with_m = remaining[prev_time];

      arr[time] = burgers_with_m;
      remaining[time] = remaining_with_m;
    }

    if (time >= n) {
      int prev_time = time - n;
      int burgers_with_n = arr[prev_time] + 1;
      int remaining_with_n = remaining[prev_time];

      int mod_m = time % m;
      int mod_n = time % n;

      if (mod_m > mod_n) {
        arr[time] = burgers_with_n;
        remaining[time] = remaining_with_n;
      } else if (mod_m == mod_n && m >= n) {
        arr[time] = burgers_with_n;
        remaining[time] = remaining_with_n;
      }
    }
  }

  int result = arr[max_time];
  *t = remaining[max_time];

  return result;
}