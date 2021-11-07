#include "philo_bonus.h"

int	check_settings(int ac, t_settings *settings)
{
	if (settings->philo_count <= 0 || settings->life < 0 || settings->eat < 0
		|| settings->sleep < 0)
		return (-1);
	if (ac == 6)
		if (settings->loops < 0)
			return (-1);
	return (0);
}