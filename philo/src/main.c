#include "philo.h"

int	main(int ac, char *av[])
{
	int			i;
	pthread_t	tid;
	t_philo		*philo;
	t_settings	settings;

	if (ac < 5 || ac > 6)
		return (-1);
	settings = init_settings(&tid);
	if (parser(ac, av, &settings) < 0)
		return (-1);
	philo = ft_calloc(settings.philos + 1, sizeof(t_philo));
	i = 0;
	while (i < settings.philos)
	{
		philo[i] = init_philo(&settings, i);
		pthread_create(&tid, NULL, birth, &philo[i]);
		usleep(20);
		// printf("philo num %i\n", i + 1);
		i++;
	}
	// printf("settings are %i life\t%i eat\t%i sleep", settings.life, settings.eat, settings.sleep);
	// if (settings.loops > 0)
	// 	printf("\t%i loops", settings.loops);
	// printf("\n");
	return (0);
}