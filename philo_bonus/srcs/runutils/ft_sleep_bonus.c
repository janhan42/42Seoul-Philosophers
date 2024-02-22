/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:06:28 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 14:07:51 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"
#include <sys/_types/_ucontext.h>
#include <unistd.h>

static void	ft_sleeping(long start_time, t_philo *philo)
{
	ft_print(philo, philo->philo_id, "is sleeping\n");
	while (ft_current_time(philo) - start_time < philo->time_to_sleep)
		usleep(300);
}

void	ft_sleep(t_philo *philo)
{
	ft_sleeping(ft_current_time(philo), philo);
}
