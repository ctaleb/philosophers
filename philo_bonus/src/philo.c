/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:11:14 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 10:06:30 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*thanatos(void *data)
{
	t_settings	*settings;

	settings = (t_settings *)data;
	while (1)
	{
		if (get_time(settings->philo.last_eat) > (uint64_t)settings->life)
		{
			smart_talk(settings, "died");
			exit(3);
		}
		usleep(50);
	}
}

void	launch_philos(t_settings *settings)
{
	int	i;

	i = 0;
	while (i < settings->philo_count)
	{
		sem_post(settings->sync);
		i++;
	}
}

int	birth(t_settings *settings)
{
	pthread_t		tid;

	sem_wait(settings->sync);
	gettimeofday(&settings->start, NULL);
	settings->philo.last_eat = settings->start;
	if (pthread_create(&tid, NULL, thanatos, settings))
		exit (-1);
	if (settings->philo.id % 2)
		sleeping(settings);
	else
	{
		eating(settings);
		sleeping(settings);
	}
	while (1)
	{
		eating(settings);
		sleeping(settings);
	}
	exit (0);
}

void	gen_philos(t_settings *settings)
{
	int	i;

	settings->pids = ft_calloc(settings->philo_count, sizeof(pid_t));
	if (settings->pids == NULL)
		free_exit(settings, -1);
	i = 0;
	while (i < settings->philo_count)
	{
		settings->pids[i] = fork();
		if (settings->pids[i] == -1)
			free_exit(settings, -1);
		else if (settings->pids[i] == 0)
		{
			settings->philo.id = i;
			birth(settings);
		}
		i++;
	}
	usleep(200);
	launch_philos(settings);
}
