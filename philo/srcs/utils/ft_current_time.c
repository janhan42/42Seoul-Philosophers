/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:34:21 by janhan            #+#    #+#             */
/*   Updated: 2024/02/21 21:35:39 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long	ft_current_time(t_info *info)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (FAILURE);
	return (((time.tv_sec) * 1000 + (time.tv_usec) / 1000) - info->time_booted);
}
