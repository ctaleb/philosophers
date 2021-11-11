/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:10:26 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/11 13:44:41 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_end(t_settings *settings)
{
	int	status;
	int	pid;
	int	i;

	pid = waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 3)
	{
		i = 0;
		while (i < settings->philo_count)
		{
			kill(settings->pids[i], SIGKILL);
			i++;
		}
	}
	while (wait(NULL) != -1)
		continue ;
	free(settings->pids);
	free_exit(settings, 0);
}

int	main(int ac, char *av[])
{
	t_settings	settings;

	if (ac < 5 || ac > 6)
		return (-1);
	settings = init_settings();
	if (parser(ac, av, &settings) < 0)
		return (-1);
	if (settings.loops == 0)
		return (0);
	init_semaphore(&settings);
	gen_philos(&settings);
	wait_end(&settings);
}
