/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:14:48 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 14:09:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <semaphore.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1
# define STRAVED 4
# define FINISH_EAT 0

typedef struct s_philo
{
	int				ac;
	char			**av;
	long			num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat_count;
	long			time_booted;
	long			philo_id;
	long			last_eat_time;
	long			eat_count;
	sem_t			*fork_holder;
	sem_t			*lock_philo;
	sem_t			*print;
	char			*lock_philo_id;
	pid_t			*child;
}	t_philo;

typedef struct s_strtol
{
	const char		*s;
	unsigned long	acc;
	int				c;
	unsigned long	cutoff;
	int				neg;
	int				any;
	int				cutlim;
}	t_strtol;

/* utils */
int	ft_error(char *msg, int error_code);
long	ft_atol(const char *str);
long	ft_strtol(const char *nptr, char **endptr, int base);
long	ft_current_time(t_philo *philo);
char	*ft_ltoa(long n);
void	ft_print(t_philo *philo, long id, char *msg);
int	ft_isspace(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
/* init */
int	ft_philo_init(int ac, char **av, t_philo *philo);
int	ft_sem_init(t_philo *philo);
int	ft_time_init(t_philo *philo);
/* run utils */
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_child_routine(t_philo *philo);
#endif
