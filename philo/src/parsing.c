/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:12:50 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/09 09:12:51 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_value(char *str)
{
	int		nb;
	char	*nbr;

	nb = ft_atoi(str);
	nbr = ft_itoa(nb);
	if (ft_strncmp(str, nbr, ft_strlen(str)))
	{
		free (nbr);
		return (-1);
	}
	else
	{
		free (nbr);
		return (nb);
	}
}

int	parser(int ac, char *av[], t_settings *settings)
{
	int	i;

	i = 1;
	settings->philo_count = get_value(av[i++]);
	settings->life = get_value(av[i++]);
	settings->eat = get_value(av[i++]);
	settings->sleep = get_value(av[i++]);
	if (i < ac)
		settings->loops = get_value(av[i]);
	return (check_settings(ac, settings));
}
