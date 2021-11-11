/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:10:15 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 09:10:19 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_settings *settings)
{
	sem_wait(settings->forks);
	smart_talk(settings, "has taken a fork");
	sem_wait(settings->forks);
	smart_talk(settings, "has taken a fork");
	smart_talk(settings, "is eating");
	gettimeofday(&settings->philo.last_eat, NULL);
	rtsleep(settings->start, \
		get_time(settings->start) + settings->eat);
	sem_post(settings->forks);
	sem_post(settings->forks);
	if (settings->loops > 0)
	{
		settings->loops--;
		if (!settings->loops)
			exit (0);
	}
}

void	sleeping(t_settings *settings)
{
	smart_talk(settings, "is sleeping");
	rtsleep(settings->start, \
		get_time(settings->start) + settings->sleep);
	smart_talk(settings, "is thinking");
}
