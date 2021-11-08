#include "philo_bonus.h"

uint64_t	get_time(struct timeval start)
{
	struct timeval	current;
	uint64_t		t1;
	uint64_t		t2;

	gettimeofday(&current, NULL);
	t1 = (uint64_t)(start.tv_sec * 1000) + (start.tv_usec / 1000);
	t2 = (uint64_t)(current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (t2 - t1);
}