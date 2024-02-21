/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:51:41 by janhan            #+#    #+#             */
/*   Updated: 2024/02/21 23:08:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/_pthread/_pthread_t.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1

typedef struct s_fork
{
	long				fork_id;
	int					pickable;
	struct s_info		*info;
	pthread_mutex_t 	mutex;
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread;
	long		philo_id;
	struct s_info	*info;
	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
	int				left_fork_up;
	int				right_fork_up;
	long			last_eat_time;
	long			eat_count;
}	t_philo;

typedef struct s_info
{
	int	ac;
	char **av;
	struct s_philo	**philos;
	struct s_fork	**forks;
	long			num_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			must_eat_count;
	long			time_booted;
	int				die_flag;
	int				finish_eat_flag;
	long			first_die_time;
	long			*eat_enough;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	finish_eat_mutxt;
	pthread_mutex_t	print_mutex;
}	t_info;

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
int		ft_error(char *massege, int error_code);
int		ft_isspace(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
long	ft_atol(const char *str);
long	ft_strtol(const char *nptr, char **endptr, int base);
void	ft_free_philos(t_philo **philos, long count);
void	ft_free_fork(t_fork **forks, long count);
long	ft_current_time(t_info *info);
void	ft_print(t_info *info, long id, char *msg);

/* init */
int	ft_info_init(int ac, char **av, t_info *info);
int	ft_fork_init(t_info *info);
int	ft_philo_init(t_info *info);
int	ft_time_init(t_info *info);

/* run */
void	*ft_routine(void *philo);
int	ft_check_died(t_info *info, t_philo *philo);
int	ft_is_other_died(t_info *info);
int	ft_check_finish_eat(t_philo *philo);
int	ft_eat(t_philo *philo);
int	ft_sleep(t_philo *philo);
int	ft_think(t_philo *philo);
int	ft_start_logic(t_info *info, t_philo **philos);
void	ft_finish(t_info *info);

#endif
