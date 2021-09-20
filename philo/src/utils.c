#include "philo.h"

uint64_t	get_time(struct timeval start)
{
	struct timeval	current;
	uint64_t		t1;
	uint64_t		t2;

	gettimeofday(&current, NULL);
	t1 = (uint64_t)(start.tv_sec * 1000) + (start.tv_usec / 1000);
	t2 = (uint64_t)(current.tv_sec * 1000) + (current.tv_usec / 1000);
	// printf ("%llu \t %llu \t %llu\n", t1, t2, t2 - t1);
	return (t2 - t1);
}

// int	print_action(t_data *data, char *msg, int id, int death)
// {
// 	uint64_t		time;

// 	time = get_time(data->start);
// 	pthread_mutex_lock(&data->output);
// 	printf("%llu %d %s\n", time, id + 1, msg);
// 	if (!death)
// 		pthread_mutex_unlock(&data->output);
// 	return (SUCCESS);
// }

int	check_hunger(t_philo *philo)
{
	uint64_t	time;

	if (get_time(philo->last_eat) > (uint64_t)philo->settings->life)
	{
		pthread_mutex_lock(&philo->settings->voice);
		time = get_time(philo->settings->start);
		printf("%llu: Philo %i died.\n", time, philo->id + 1);
		return (-1);
	}
	return (0);
}

int	check_sleep(t_philo *philo)
{
	if (get_time(philo->last_sleep) > (uint64_t)philo->settings->life)
		return (-1);
	return (0);
}

int	are_alive(t_settings *settings)
{
	int i;

	i = 0;
	while (i < settings->philo_count)
	{
		if (get_time(settings->philo[i].last_eat) > (uint64_t)settings->life)
			return (0);
		i++;
	}
	return (1);
}