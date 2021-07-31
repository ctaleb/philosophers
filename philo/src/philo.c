#include "philo.h"

void	*birth(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->tid = philo->settings->tid;
	printf("tid %d\tphilo number %i\n", philo->tid, philo->id + 1);
	return (0);
}