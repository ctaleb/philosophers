#include "philo.h"

uint64_t	get_time(struct timeval start)
{
	struct timeval	current;
	uint64_t		t1;
	uint64_t		t2;

	gettimeofday(&current, NULL);
	t1 = (uint64_t)(start.tv_sec * 1000) + (start.tv_usec / 1000);
	t2 = (uint64_t)(current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (t2 - t1);
}

void	rtsleep(struct timeval start, u_int64_t goal)
{
	while (get_time(start) < goal)
		usleep(100);
}

int	are_alive(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->philo_count)
	{
		if (get_time(settings->philo[i].last_eat) > (uint64_t)settings->life)
			return (0);
		i++;
	}
	return (1);
}

void	loop(t_settings *settings)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < settings->philo_count)
	{
		if (check_hunger(&settings->philo[i]) == -1)
			return ;
		usleep(20);
		i++;
		if (settings->loops > 0)
		{
			if (settings->philo[i].loop_count >= settings->loops)
				j++;
		}
		if (j >= settings->philo_count - 1)
			return ;
		if (i >= settings->philo_count - 1)
		{
			i = 0;
			j = 0;
		}
	}
}
