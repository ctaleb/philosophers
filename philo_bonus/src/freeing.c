/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:09:45 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 10:03:18 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_exit(t_settings *settings, int code)
{
	sem_close(settings->forks);
	sem_close(settings->voice);
	sem_close(settings->sync);
	exit(code);
}
