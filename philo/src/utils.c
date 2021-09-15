#include "philo.h"

int	get_time(struct timeval start)
{
	struct timeval	current;

	if (gettimeofday(&current, NULL) == -1)
		return (-1);
	return (((current.tv_sec * 1000) + (current.tv_usec / 1000)) \
		- ((start.tv_sec * 1000) + (start.tv_usec / 1000)));
}
