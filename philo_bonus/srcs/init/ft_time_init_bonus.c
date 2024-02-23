/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:56:29 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:54:09 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * @brief
 * 시간정보 밀리초로 초기화 함수
 * @info->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
 * @param info
 * @return int 성공 여부 리턴
 */
int	ft_time_init(t_philo *philo)
{
	struct timeval	temp_time;

	if (gettimeofday(&temp_time, NULL) == -1)
		return (FAILURE);
	philo->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
	return (SUCCESS);
}
