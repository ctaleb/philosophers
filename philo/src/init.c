/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:12:40 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 09:12:41 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks(t_philo *philo)
{
	philo->left_fork = philo->id;
	if (philo->id == philo->settings->philo_count - 1)
		philo->right_fork = 0;
	else
		philo->right_fork = philo->id + 1;
}

t_settings	init_settings(void)
{
	t_settings	settings;

	settings.philo_count = -1;
	settings.life = -1;
	settings.eat = -1;
	settings.sleep = -1;
	settings.loops = -1;
	settings.sync = 0;
	settings.extinct = 0;
	return (settings);
}

t_philo	init_philo(t_settings *settings, int i)
{
	t_philo	philo;

	philo.id = i;
	philo.loop_count = 0;
	philo.left_fork = 0;
	philo.right_fork = 0;
	philo.settings = settings;
	set_forks(&philo);
	return (philo);
}

int	init_mutex(t_settings *settings)
{
	int	i;

	i = 0;
	settings->forks = ft_calloc(settings->philo_count + 1,
			sizeof(pthread_mutex_t));
	while (i < settings->philo_count)
	{
		if (pthread_mutex_init(&settings->forks[i], NULL))
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&settings->voice, NULL))
		return (-1);
	return (0);
}

int	gen_philo(t_settings *settings)
{
	int			i;

	i = 0;
	while (i < settings->philo_count)
	{
		settings->philo[i] = init_philo(settings, i);
		if (pthread_create(&settings->philo[i].tid, NULL,
				birth, &settings->philo[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}
