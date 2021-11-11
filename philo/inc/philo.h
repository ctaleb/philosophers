/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:12:32 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/11 13:54:43 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_settings
{
	int				philo_count;
	t_philo			*philo;
	int				life;
	int				eat;
	int				sleep;
	int				loops;
	int				sync;
	int				extinct;
	struct timeval	start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	voice;
}	t_settings;

struct s_philo
{
	int				id;
	int				loop_count;
	int				left_fork;
	int				right_fork;
	struct timeval	last_eat;
	pthread_t		tid;
	t_settings		*settings;
};

	//inits
t_settings		init_settings(void);
t_philo			init_philo(t_settings *settings, int i);
int				init_mutex(t_settings *settings);

	//philos
int				smart_talk(t_philo *philo, char *msg);
int				gen_philo(t_settings *settings);
void			*birth(void *data);
int				are_alive(t_settings *settings);
void			sleeping(t_philo *philo);
void			eating(t_philo	*philo);
void			loop(t_settings *settings);

	//parsing
int				parser(int ac, char *av[], t_settings *settings);

	//checking
int				check_settings(int ac, t_settings *settings);
int				check_hunger(t_philo *philo);

	//time
uint64_t		get_time(struct timeval start);
int				rtsleep(struct timeval start, u_int64_t goal, t_philo *philo);

	//memory
int				free_exit(t_settings *settings, int code);

	//printing
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);

	//misc
int				ft_atoi(const char *str);
int				ft_isdigit(char c);
char			*ft_itoa(int n);
int				ft_strncmp(const char *str1, const char *str2, size_t size);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *ptr, size_t size);

#endif