/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:34:21 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:10:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * ft_current_time을 호출한 시간을 밀리세컨드로 리턴
 * @param info
 * @return long 호출한 시간
 */
long	ft_current_time(t_info *info)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (FAILURE);
	return (((time.tv_sec) * 1000 + (time.tv_usec) / 1000) - info->time_booted);
}
