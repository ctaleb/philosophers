#include "philo_bonus.h"

void	free_exit(t_settings *settings)
{
	sem_close(settings->forks);
	sem_close(settings->voice);
	exit(-1);
}