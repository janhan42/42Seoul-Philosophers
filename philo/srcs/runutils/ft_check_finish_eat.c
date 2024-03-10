/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:57:57 by janhan            #+#    #+#             */
/*   Updated: 2024/03/07 13:30:03 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_check_finish_eat(t_philo *philo)
{
	long	count;

	usleep(100);
	pthread_mutex_lock(&(philo->info->finish_eat_mutxt));
	count = 0;
	while (count < philo->info->num_of_philo)
	{
		pthread_mutex_lock(&(philo->info->eat_enough_flag));
		if (philo->info->eat_enough[count] == FALSE)
		{
			pthread_mutex_unlock(&(philo->info->finish_eat_mutxt));
			pthread_mutex_unlock(&(philo->info->eat_enough_flag));
			return (FALSE);
		}
		pthread_mutex_unlock(&(philo->info->eat_enough_flag));
		count++;
	}
	pthread_mutex_unlock(&(philo->info->finish_eat_mutxt));
	return (TRUE);
}
