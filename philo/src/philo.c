#include "philo.h"

void	sleeping(t_philo *philo)
{
	u_int64_t	time;

	smart_talk(philo, "is sleeping");
	time = get_time(philo->settings->start) + philo->settings->sleep;
	rtsleep(philo->settings->start, time);
	smart_talk(philo, "is thinking");
}

void	eating(t_philo	*philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->settings->forks[philo->left_fork]);
	smart_talk(philo, "has taken a fork");
	pthread_mutex_lock(&philo->settings->forks[philo->right_fork]);
	smart_talk(philo, "has taken a fork");
	smart_talk(philo, "is eating");
	gettimeofday(&philo->last_eat, NULL);
	time = get_time(philo->settings->start) + philo->settings->eat;
	rtsleep(philo->settings->start, time);
	pthread_mutex_unlock(&philo->settings->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->settings->forks[philo->right_fork]);
	if (philo->settings->loops > 0)
		philo->loop_count++;
	if (philo->settings->loops > 0
		&& philo->loop_count >= philo->settings->loops)
		return ;
	sleeping(philo);
}

void	*birth(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->settings->sync)
		usleep(5);
	philo->last_eat = philo->settings->start;
	if (philo->id % 2)
		sleeping(philo);
	else
	{
		eating(philo);
		usleep(50);
	}
	while (are_alive(philo->settings) && !philo->settings->extinct)
	{
		if (philo->settings->loops > 0
			&& philo->loop_count >= philo->settings->loops)
			break ;
		eating(philo);
		usleep(50);
	}
	return (0);
}
