#include "philo.h"

t_settings	init_settings(pthread_t *tid)
{
	t_settings	settings;

	settings.philos = -1;
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
	philo.settings = settings;
	return (philo);
}