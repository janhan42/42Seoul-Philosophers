/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:10:22 by janhan            #+#    #+#             */
/*   Updated: 2024/02/13 06:07:28 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1

typedef struct s_philo
{
	pthread_t		thread;
	long			philo_id;
	struct s_info	*info;
	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
	int				left_fork_up;
	int				right_fork_up;
	long			last_eat_time;
	long			eat_count;
}	t_philo;

typedef struct s_fork
{
	long		fork_id;
	int			pickable;
	struct s_info	*info;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_info
{
	int			ac;
	char		**av;
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
	pthread_mutex_t	finish_eat_mutex;
	pthread_mutex_t	print_mutex;
}	t_info;

typedef struct s_strtol
{
	const char		*str;
	unsigned int	acc;
	int				c;
	unsigned int	cutoff;
	int				neg;
	int				any;
	int				cutlim;
}	t_strtol;

#endif
