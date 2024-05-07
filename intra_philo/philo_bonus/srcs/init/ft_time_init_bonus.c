/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:56:29 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:18:48 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	ft_time_init(t_philo *philo)
{
	struct timeval	temp_time;

	if (gettimeofday(&temp_time, NULL) == -1)
		return (FAILURE);
	philo->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000;
	return (SUCCESS);
}
