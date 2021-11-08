#include "philo_bonus.h"

void	*thanatos(void *data)
{
	t_settings	*settings;

	settings = (t_settings *)data;
	while (1)
	{
		if (get_time(settings->philo.last_eat) > (uint64_t)settings->life)
		{
			// if (settings->loops <)
			// sem_wait(settings->voice);
			printf("ded");
			exit(3);
		}
		usleep(50);
	}
}

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
	pthread_t		tid;

	printf("Bonjour, %i\n", settings->philo.id);
	sem_wait(settings->sync);
	gettimeofday(&settings->start, NULL);
	settings->philo.last_eat = settings->start;
	if (pthread_create(&tid, NULL, thanatos, &settings))
	printf("Au revoir, %i\n", settings->philo.id);
	exit (0);
}

void	gen_philos(t_settings *settings)
{
	int	i;

	settings->pids = malloc(sizeof(pid_t) * settings->philo_count);
	if (settings->pids == NULL)
		free_exit(settings);
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
