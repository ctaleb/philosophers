/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:07:53 by ctaleb            #+#    #+#             */
/*   Updated: 2021/11/11 12:40:00 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	struct timeval	last_eat;
}	t_philo;

typedef struct s_settings
{
	int				philo_count;
	int				life;
	int				eat;
	int				sleep;
	int				loops;
	sem_t			*forks;
	sem_t			*voice;
	sem_t			*sync;
	pid_t			*pids;
	struct timeval	start;
	t_philo			philo;
}	t_settings;

	//mem
void			free_exit(t_settings *settings, int code);

	//inits
t_settings		init_settings(void);
void			init_semaphore(t_settings *settings);

	//philos
void			gen_philos(t_settings *settings);
int				smart_talk(t_settings *settings, char *msg);
void			eating(t_settings *settings);
void			sleeping(t_settings *settings);

	//parsing
int				parser(int ac, char *av[], t_settings *settings);

	//checking
int				check_settings(int ac, t_settings *settings);

	//printing
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);

	//time
uint64_t		get_time(struct timeval start);
void			rtsleep(struct timeval start, u_int64_t goal);

	//misc
int				ft_atoi(const char *str);
int				ft_isdigit(char c);
char			*ft_itoa(int n);
int				ft_strncmp(const char *str1, const char *str2, size_t size);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *ptr, size_t size);

#endif