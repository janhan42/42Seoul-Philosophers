/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:00:16 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 09:03:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_sleeping(long start_time, t_philo *philo)
{
	ft_print(philo->info, philo->philo_id, "is sleeping\n"); // 출력
	while (ft_current_time(philo->info) - start_time // current_time - start_time < time_to_sleep 보다 작을때
		< philo->info->time_to_sleep)
	{
		if (ft_check_died(philo->info, philo) == TRUE) // 중간에 죽는지 확인
			return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_sleeping(ft_current_time(philo->info), philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
