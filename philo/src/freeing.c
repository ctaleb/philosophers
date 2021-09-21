#include "philo.h"

int	free_exit(t_settings *settings, int code)
{
	int	i;

	i = 0;
	while (i < settings->philo_count)
	{
		pthread_mutex_destroy(&settings->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&settings->voice);
	free(settings->philo);
	free(settings->forks);
	return (code);
}
