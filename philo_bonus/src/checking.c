/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:09:32 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 09:09:37 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
