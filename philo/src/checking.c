/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:12:35 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 09:12:36 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_settings(int ac, t_settings *settings)
{
	if (settings->philo_count <= 0 || settings->life < 0 || settings->eat < 0
		|| settings->sleep < 0)
		return (-1);
	if (ac == 6)
		if (settings->loops < 0)
			return (-1);
	return (0);
}

int	check_hunger(t_philo *philo)
{
	usleep(50);
	if (get_time(philo->last_eat) > (uint64_t)philo->settings->life)
	{
		if (philo->settings->loops > 0
			&& philo->loop_count >= philo->settings->loops)
			return (0);
		smart_talk(philo, "died");
		philo->settings->extinct = 1;
		return (-1);
	}
	return (0);
}
