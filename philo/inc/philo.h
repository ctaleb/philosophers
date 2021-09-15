#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_settings
{
	int				philos;
	int				life;
	int				eat;
	int				sleep;
	int				loops;
	struct timeval	start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	voice;
	pthread_t	tid;
}	t_settings;

//forks?

typedef struct	s_philo
{
	int	id;
	int	loop_count;
	int	left_fork;
	int	right_fork;
	struct timeval	last_eat;
	struct timeval	last_sleep;
	pthread_t	tid;
	t_settings	*settings;
}	t_philo;

	//inits
t_settings		init_settings(pthread_t *tid);
t_philo			init_philo(t_settings *settings, int i);
int				init_mutex(t_settings *settings);

	//philos
void			*birth(void *data);

	//parsing
int				parser(int ac, char *av[], t_settings *settings);

	//time
int				get_time(struct timeval start);

	//misc
int				check_settings(int ac, t_settings *settings);
int				ft_atoi(const char *str);
int				ft_isdigit(char c);
char			*ft_itoa(int n);
int				ft_strncmp(const char *str1, const char *str2, size_t size);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *ptr, size_t size);

#endif