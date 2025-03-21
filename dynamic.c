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
  // Create dynamic programming table
  int max_time = *t;
  int *dp = (int *)malloc((max_time + 1) * sizeof(int));
  int *leftover = (int *)malloc((max_time + 1) * sizeof(int));

  // Initialize the base cases
  for (int i = 0; i <= max_time; i++) {
    dp[i] = 0;       // No burgers eaten yet
    leftover[i] = i; // All time is leftover initially
  }

  // Fill the dp table
  for (int time = 1; time <= max_time; time++) {
    // Can't eat a burger with this time
    if (time < m && time < n) {
      continue; // Keep the default values
    }

    // Try eating with time m
    if (time >= m) {
      int prev_time = time - m;
      int burgers_with_m = dp[prev_time] + 1;
      int leftover_with_m = leftover[prev_time];

      dp[time] = burgers_with_m;
      leftover[time] = leftover_with_m;
    }

    // Try eating with time n
    if (time >= n) {
      int prev_time = time - n;
      int burgers_with_n = dp[prev_time] + 1;
      int leftover_with_n = leftover[prev_time];

      // Apply the same logic as in the original code
      int mod_m = time % m;
      int mod_n = time % n;

      if (mod_m > mod_n) {
        dp[time] = burgers_with_n;
        leftover[time] = leftover_with_n;
      } else if (mod_m == mod_n && m >= n) {
        dp[time] = burgers_with_n;
        leftover[time] = leftover_with_n;
      }
    }
  }

  // Set the result
  int result = dp[max_time];
  *t = leftover[max_time];

  // Free memory
  free(dp);
  free(leftover);

  return result;
}