/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:09:53 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 10:04:55 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphore(t_settings *settings)
{
	sem_unlink("forks");
	sem_unlink("voice");
	sem_unlink("sync");
	settings->forks = sem_open("forks", O_CREAT | O_EXCL, \
			S_IRWXU, settings->philo_count);
	settings->voice = sem_open("voice", O_CREAT | O_EXCL, \
			S_IRWXU, 1);
	settings->sync = sem_open("sync", O_CREAT | O_EXCL, \
			S_IRWXU, 0);
	if (settings->forks == SEM_FAILED
		|| settings->voice == SEM_FAILED
		|| settings->sync == SEM_FAILED)
		free_exit(settings, -1);
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
	return (settings);
}
