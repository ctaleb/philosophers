#include "philo.h"

int	main(int ac, char *av[])
{
	int			i;
	pthread_t	tid;
	// t_philo		*philo;
	t_settings	settings;

	if (ac < 5 || ac > 6)
		return (-1);
	settings = init_settings(&tid);
	if (parser(ac, av, &settings) < 0)
		return (-1);
	settings.philo = ft_calloc(settings.philo_count + 1, sizeof(t_philo));
	gettimeofday(&settings.start, NULL);
	if (init_mutex(&settings))
	{
		// free_exit(settings);
		return (-1);
	}
	i = 0;
	while (i < settings.philo_count)
	{
		settings.philo[i] = init_philo(&settings, i);
		pthread_create(&tid, NULL, birth, &settings.philo[i]);
		settings.tid = tid;
		usleep(20);
		i++;
	}

	while (1)
	{
		i = 0;
		while (i < settings.philo_count)
		{
			if (check_hunger(&settings.philo[i]) == -1)
				break ;
			usleep(20);
			i++;
		}
	}
	
	return (0);
}