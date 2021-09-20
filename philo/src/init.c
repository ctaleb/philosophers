#include "philo.h"

void	set_forks(t_philo *philo)
{
	philo->left_fork = philo->id;
	if (philo->id == philo->settings->philo_count - 1)
		philo->right_fork = 0;
	else
		philo->right_fork = philo->id + 1;
}

t_settings	init_settings(pthread_t *tid)
{
	t_settings	settings;

	settings.philo_count = -1;
	settings.life = -1;
	settings.eat = -1;
	settings.sleep = -1;
	settings.loops = -1;
	settings.tid = *tid;
	return (settings);
}

t_philo	init_philo(t_settings *settings, int i)
{
	t_philo	philo;

	philo.id = i;
	philo.loop_count = 0;
	philo.left_fork = 0;
	philo.right_fork = 0;
	philo.settings = settings;
	set_forks(&philo);
	return (philo);
}

int	init_mutex(t_settings *settings)
{
	int	i;

	i = 0;
	settings->forks = malloc(sizeof(pthread_mutex_t) * settings->philo_count);
	while (i < settings->philo_count)
	{
		if (pthread_mutex_init(&settings->forks[i], NULL))
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&settings->voice, NULL))
		return (-1);
	return (0);
}