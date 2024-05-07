/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_time_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:47:15 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:05:25 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

long	ft_current_time(t_philo *philo)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (FAILURE);
	return (((time.tv_sec) * 1000
			+ (time.tv_usec) / 1000) - philo->time_booted);
}
