/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:57:57 by janhan            #+#    #+#             */
/*   Updated: 2024/03/12 11:31:01 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_check_finish_eat(t_philo *philo)
{
	long	count;

	count = 0;
	while (count < philo->info->num_of_philo)
	{
		pthread_mutex_lock(&(philo->info->eat_enough_flag));
		if (philo->info->eat_enough[count] == FALSE)
		{
			pthread_mutex_unlock(&(philo->info->eat_enough_flag));
			return (FALSE);
		}
		pthread_mutex_unlock(&(philo->info->eat_enough_flag));
		count++;
	}
	pthread_mutex_lock(&(philo->info->finish_eat_mutxt));
	philo->info->finish_eat_flag = TRUE;
	pthread_mutex_unlock(&(philo->info->finish_eat_mutxt));
	return (TRUE);
}

int	ft_check_eat_flag(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&(philo->info->finish_eat_mutxt));
	flag = philo->info->finish_eat_flag;
	pthread_mutex_unlock(&(philo->info->finish_eat_mutxt));
	return (flag);
}
