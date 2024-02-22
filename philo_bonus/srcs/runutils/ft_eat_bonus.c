/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:01:52 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 14:05:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"
#include <sys/semaphore.h>

static void	ft_eating(long start_time, t_philo *philo)
{
	ft_print(philo, philo->philo_id, "is eating\n");
	while (ft_current_time(philo) - start_time < philo->time_to_eat)
		usleep(300);
	philo->eat_count++;
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->fork_holder);
	ft_print(philo, philo->philo_id, "has taken a fork\n");
	sem_wait(philo->fork_holder);
	ft_print(philo, philo->philo_id, "has taken a fork\n");
	sem_wait(philo->lock_philo);
	philo->last_eat_time = ft_current_time(philo);
	sem_post(philo->lock_philo);
	ft_eating(ft_current_time(philo), philo);
	sem_post(philo->fork_holder);
	sem_post(philo->fork_holder);
}
