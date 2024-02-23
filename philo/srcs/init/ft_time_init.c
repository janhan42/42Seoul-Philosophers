/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:14:17 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:47:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * 시간정보 초기화 함수
 * @info->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
 * @param info
 * @return int 성공 여부 리턴
 */
int	ft_time_init(t_info *info)
{
	struct timeval	temp_time;

	if (gettimeofday(&temp_time, NULL) == -1)
		return (FAILURE);
	info->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
	return (SUCCESS);
}
