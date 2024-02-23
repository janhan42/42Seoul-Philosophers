/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:00:16 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:18:33 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * ft_print로 "is sleeping\n" 출력
 * ft_current_time - start_time < philo->info->time_to_sleep동안 유지하며
 * 중간에 죽는지 확인
 * @param start_time
 * @param philo
 * @return int
 */
static int	ft_sleeping(long start_time, t_philo *philo)
{
	ft_print(philo->info, philo->philo_id, "is sleeping\n");
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_sleep)
	{
		if (ft_check_died(philo->info, philo) == TRUE)
			return (FAILURE);
	}
	return (SUCCESS);
}

/**
 * @brief
 * 잠자는 함수
 * @param philo
 * @return int
 */
int	ft_sleep(t_philo *philo)
{
	if (ft_sleeping(ft_current_time(philo->info), philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
