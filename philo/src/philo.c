#include "philo.h"

void	*birth(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->tid = philo->settings->tid;
	// printf("tid %d\tphilo number %i\n", (int)philo->tid, philo->id + 1);
	// printf("rtid %i\n", (int)philo->settings->tid);
	return (0);
}