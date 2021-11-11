/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:12:54 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/11 13:54:28 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	rtsleep(struct timeval start, u_int64_t goal, t_philo *philo)
{
	while (get_time(start) < goal)
	{
		if (philo->settings->extinct)
			return (1);
		usleep(100);
	}
	return (0);
}

int	smart_talk(t_philo *philo, char *msg)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->settings->voice);
	if (philo->settings->extinct)
	{
		pthread_mutex_unlock(&philo->settings->voice);
		return (1);
	}
	time = get_time(philo->settings->start);
	ft_putnbr_fd(time, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(philo->id + 1, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	pthread_mutex_unlock(&philo->settings->voice);
	return (0);
}

int	are_alive(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->philo_count)
	{
		if (get_time(settings->philo[i].last_eat) > (uint64_t)settings->life)
			return (0);
		i++;
	}
	return (1);
}

void	loop(t_settings *settings)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < settings->philo_count)
	{
		if (check_hunger(&settings->philo[i]) == -1)
			return ;
		usleep(20);
		i++;
		if (settings->loops > 0)
		{
			if (settings->philo[i].loop_count >= settings->loops)
				j++;
		}
		if (j >= settings->philo_count - 1 && settings->loops > 0
			&& settings->philo_count > 1)
			return ;
		if (i >= settings->philo_count - 1)
		{
			i = 0;
			j = 0;
		}
	}
}
