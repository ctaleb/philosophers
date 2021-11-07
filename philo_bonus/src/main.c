#include "philo_bonus.h"

void	wait_end(t_settings *settings)
{
	int	status;
	int	pid;

	pid = waitpid(-1, &status, 0);
	(void)settings;
	printf("end\n");
}

int	main(int ac, char *av[])
{
	t_settings	settings;

	if (ac < 5 || ac > 6)
		return (-1);
	settings = init_settings();
	if (parser(ac, av, &settings) < 0)
		return (-1);
	init_semaphore(&settings);
	gen_philos(&settings);
	wait_end(&settings);
}
