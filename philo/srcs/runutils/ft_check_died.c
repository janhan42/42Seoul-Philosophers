/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:46:23 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 09:11:53 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <pthread.h>

int	ft_is_died(t_info *info, t_philo *philo) // 이색죽음?
{
	long	die_time;

	usleep(100); // 충돌방지
	pthread_mutex_lock(&(info->die_mutex)); // 뮤텍스락
	if (info->die_flag == TRUE) // 만약에 info->die_flag가 TRUE면
	{
		pthread_mutex_unlock(&(info->die_mutex)); // 언락
		return (TRUE); // 뒤짐 ㅋㅋ
	}
	if (info->time_to_die <= ft_current_time(info) - philo->last_eat_time) // time_to_die <= 지금 시간  - philo->last_eat_time(마지막 식사 시간)
	{
		die_time = ft_current_time(info);
		info->die_flag = TRUE;
		while (ft_current_time(info) - die_time < 10)
			;
		if (info->first_die_time == -1) // 첫 사망만 감지하기위함
		{
			printf("%ld %ld died\n", die_time, philo->philo_id); // 사망 출력
			info->first_die_time = die_time; // 이후 사망 감지 안하게 first_die_time 변경
		}
		pthread_mutex_unlock(&(info->die_mutex)); // 언락
		return (TRUE); // 뒤짐
	}
	pthread_mutex_unlock(&(info->die_mutex)); // 언락
	return (FALSE); // 안뒤짐
}

int	ft_is_other_died(t_info *info)
{
	usleep(100); // 충돌방지
	pthread_mutex_lock(&(info->die_mutex)); // 뮤텍스 락
	if (info->die_flag == TRUE) // 만약 info->die_flag가 다른 철학자에 의해 TRUE일때
	{
		pthread_mutex_unlock(&(info->die_mutex)); // 뮤택스 언락
		return (TRUE); // 뒤짐 ㅋㅋ
	}
	pthread_mutex_unlock(&(info->die_mutex)); // 아님말고 ㅋ
	return (FALSE);
}

int	ft_check_died(t_info *info, t_philo *philo)
{
	if (ft_is_died(info, philo) == TRUE || ft_is_other_died(info) == TRUE) // 내가 죽었는지 다른 애가 뒤졌는지
		return (TRUE);
	return (FALSE);
}
