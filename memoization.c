#include <stdio.h>

struct memo_table
{
  int burgers_eaten;
  int time_left;
};

int memoization(int time_to_eat_burger_1, int time_to_eat_burger_2, int time_left, struct memo_table mtable[]);

int main(void)
{

  int time_to_eat_burger_1, time_to_eat_burger_2, total_time;

  while (scanf("%d %d %d", &time_to_eat_burger_1, &time_to_eat_burger_2, &total_time) != EOF)
  {

    struct memo_table memo_table[total_time + 1];

    for (int i = 0; i <= total_time; i++)
    {
      memo_table[i].burgers_eaten = -1;
      memo_table[i].time_left = -1;
    }

    memoization(time_to_eat_burger_1, time_to_eat_burger_2, total_time, memo_table);

    if (memo_table[total_time].time_left > 0)
    {
      printf("%d %d\n", memo_table[total_time].burgers_eaten, memo_table[total_time].time_left);
    }
    else
    {
      printf("%d\n", memo_table[total_time].burgers_eaten);
    }
  }

  return 0;
}

int memoization(int time_to_eat_burger_1, int time_to_eat_burger_2, int time_left, struct memo_table mtable[])
{

  if (time_left < time_to_eat_burger_1 && time_left < time_to_eat_burger_2)
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

  if (time_left >= time_to_eat_burger_1)
  {
    result_burger_1 = 1 + memoization(time_to_eat_burger_1, time_to_eat_burger_2, time_left - time_to_eat_burger_1, mtable);
    remaining_time_1 = mtable[time_left - time_to_eat_burger_1].time_left;
  }

  if (time_left >= time_to_eat_burger_2)
  {
    result_burger_2 = 1 + memoization(time_to_eat_burger_1, time_to_eat_burger_2, time_left - time_to_eat_burger_2, mtable);
    remaining_time_2 = mtable[time_left - time_to_eat_burger_2].time_left;
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