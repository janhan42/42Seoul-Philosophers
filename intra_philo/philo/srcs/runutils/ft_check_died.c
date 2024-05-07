/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:46:23 by janhan            #+#    #+#             */
/*   Updated: 2024/03/12 11:45:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_is_died(t_info *info, t_philo *philo)
{
	long	die_time;

	usleep(100);
	pthread_mutex_lock(&(info->die_mutex));
	if (info->die_flag == TRUE)
	{
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	if (info->time_to_die <= ft_current_time(info) - philo->last_eat_time)
	{
		die_time = ft_current_time(info);
		info->die_flag = TRUE;
		while (ft_current_time(info) - die_time < 10)
			;
		if (info->first_die_time == -1)
		{
			ft_print(info, philo->philo_id, "died\n");
			info->first_die_time = die_time;
		}
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->die_mutex));
	return (FALSE);
}

int	ft_is_other_died(t_info *info)
{
	usleep(100);
	pthread_mutex_lock(&(info->die_mutex));
	if (info->die_flag == TRUE)
	{
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->die_mutex));
	return (FALSE);
}

int	ft_check_died(t_info *info, t_philo *philo)
{
	if (ft_is_died(info, philo) == TRUE || ft_is_other_died(info) == TRUE)
		return (TRUE);
	return (FALSE);
}
