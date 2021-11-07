#include "philo_bonus.h"

void	launch_philos(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->philo_count)
	{
		sem_post(settings->sync);
		i++;
	}
}

int		birth(t_settings *settings)
{
	printf("Bonjour, %i\n", settings->philo.id);
	sem_wait(settings->sync);
	printf("Au revoir, %i\n", settings->philo.id);
	exit (0);
}

void	gen_philos(t_settings *settings)
{
	int	i;

	settings->pids = malloc(sizeof(pid_t) * settings->philo_count);
	if (settings->pids == NULL)
		free_exit(settings);
	sem_wait(settings->sync);
	i = 0;
	while (i < settings->philo_count)
	{
		settings->pids[i] = fork();
		if (settings->pids[i] == -1)
			free_exit(settings);
		else if (settings->pids[i] == 0)
		{
			settings->philo.id = i;
			printf("entering\n");
			birth(settings);
		}
		i++;
	}
	usleep(200);
	launch_philos(settings);
}
