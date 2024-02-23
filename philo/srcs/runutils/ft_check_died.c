/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:46:23 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:42:57 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <pthread.h>

/**
 * @brief
 * 내가 죽었는지 확인하는 함수
 * @if (info->first_die_time == -1) 첫 사망이후 값 변경
 * @param info
 * @param philo
 * @return int
 */
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
			printf("%ld %ld died\n", die_time, philo->philo_id);
			info->first_die_time = die_time;
		}
		pthread_mutex_unlock(&(info->die_mutex));
		return (TRUE);
	}
	pthread_mutex_unlock(&(info->die_mutex));
	return (FALSE);
}

/**
 * @brief
 * info->die_flag가 다른 철학자에 의해 TRUE일떄 어떠한 철학자가 죽었다고 판단
 * @param info
 * @return int
 */
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

/**
 * @brief
 * 내가 죽었는지 다른애가 죽었는지 동시 체크하는 함수
 * @param info
 * @param philo
 * @return int
 */
int	ft_check_died(t_info *info, t_philo *philo)
{
	if (ft_is_died(info, philo) == TRUE || ft_is_other_died(info) == TRUE)
		return (TRUE);
	return (FALSE);
}
