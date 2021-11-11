/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:11:36 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/11 13:54:22 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

int	smart_talk(t_settings *settings, char *msg)
{
	u_int64_t	time;

	sem_wait(settings->voice);
	time = get_time(settings->start);
	ft_putnbr_fd(time, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(settings->philo.id + 1, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(msg, 1);
	ft_putchar_fd('\n', 1);
	if (ft_strncmp(msg, "died", 4))
		sem_post(settings->voice);
	return (0);
}

void	rtsleep(struct timeval start, u_int64_t goal)
{
	while (get_time(start) < goal)
		usleep(100);
}
