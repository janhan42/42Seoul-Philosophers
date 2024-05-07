/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:30:49 by janhan            #+#    #+#             */
/*   Updated: 2024/03/12 11:44:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_routine(void *philo)
{
	((t_philo *)philo)->last_eat_time
		= ft_current_time(((t_philo *)philo)->info);
	if (((t_philo *)philo)->philo_id % 2 == 1)
		usleep(((t_philo *)philo)->info->time_to_eat / 4 * 1000);
	while (TRUE)
	{
		if (ft_check_eat_flag(philo) == TRUE)
			break ;
		if (ft_eat(philo) == FAILURE)
			break ;
		if (ft_check_eat_flag(philo) == TRUE)
			break ;
		if (ft_sleep(philo) == FAILURE)
			break ;
		if (ft_check_eat_flag(philo) == TRUE)
			break ;
		if (ft_think(philo) == FAILURE)
			break ;
		if (ft_check_eat_flag(philo) == TRUE)
			break ;
	}
	return (SUCCESS);
}

void	*ft_monitoring(void	*info)
{
	t_info	*monitoring_info;

	monitoring_info = (t_info *)info;
	while (TRUE)
	{
		usleep(300);
		pthread_mutex_lock(&(monitoring_info)->die_mutex);
		if (monitoring_info->die_flag == TRUE)
		{
			pthread_mutex_unlock(&(monitoring_info)->die_mutex);
			break ;
		}
		pthread_mutex_unlock(&(monitoring_info)->die_mutex);
		if (ft_check_finish_eat(monitoring_info->philos[0]))
			break ;
	}
	return (NULL);
}
