/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:12:43 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 09:12:44 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_settings	settings;

	if (ac < 5 || ac > 6)
		return (-1);
	settings = init_settings();
	if (parser(ac, av, &settings) < 0)
		return (-1);
	settings.philo = ft_calloc(settings.philo_count + 1, sizeof(t_philo));
	if (init_mutex(&settings))
		return (free_exit(&settings, -1));
	if (settings.loops == 0)
		return (free_exit(&settings, 0));
	if (gen_philo(&settings) < 0)
		return (free_exit(&settings, -1));
	gettimeofday(&settings.start, NULL);
	settings.sync = 1;
	loop(&settings);
	while (settings.philo_count--)
		pthread_join(settings.philo[settings.philo_count].tid, NULL);
	return (free_exit(&settings, 0));
}
