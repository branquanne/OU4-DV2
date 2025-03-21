#include <stdio.h>

int dynamic(int time_to_eat_burger_1, int time_to_eat_burger_2, int *total_time);

int main(void)
{

  int time_to_eat_burger_1, time_to_eat_burger_2, total_time, burgers_eaten;

  while (scanf("%d %d %d", &time_to_eat_burger_1, &time_to_eat_burger_2, &total_time) != EOF)
  {

    burgers_eaten = dynamic(time_to_eat_burger_1, time_to_eat_burger_2, &total_time);

    if (total_time > 0)
    {
      printf("%d %d\n", burgers_eaten, total_time);
    }
    else
    {
      printf("%d\n", burgers_eaten);
    }
  }

  return 0;
}

int dynamic(int time_to_eat_burger_1, int time_to_eat_burger_2, int *total_time)
{
  int arr[10000];
  int tot_burgers = 0;
  arr[0] = tot_burgers;

  for (int i = 1; *total_time >= time_to_eat_burger_2 || *total_time >= time_to_eat_burger_1; i++)
  {
    if ((*total_time % time_to_eat_burger_2) < (*total_time % time_to_eat_burger_1))
    {
      arr[i] = arr[i - 1] + 1;
      *total_time -= time_to_eat_burger_2;
    }

    else if ((*total_time % time_to_eat_burger_1) < (*total_time % time_to_eat_burger_2))
    {
      arr[i] = arr[i - 1] + 1;
      *total_time -= time_to_eat_burger_1;
    }

    else
    {
      if (time_to_eat_burger_2 < time_to_eat_burger_1)
      {
        arr[i] = arr[i - 1] + 1;
        *total_time -= time_to_eat_burger_2;
      }
      else
      {
        arr[i] = arr[i - 1] + 1;
        *total_time -= time_to_eat_burger_1;
      }
    }
    tot_burgers = arr[i];
  }
  return tot_burgers;
}