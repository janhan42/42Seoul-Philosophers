/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:57:57 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:15:52 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
/**
 * @brief
 * must_eat_count 즉 최소 식사 수가 정해져있을때 전체 철학자가 다 먹었는지 체크
 * @param philo
 * @return int TRUE or FALSE
 */
int	ft_check_finish_eat(t_philo *philo)
{
	long	count;

	usleep(100);
	pthread_mutex_lock(&(philo->info->finish_eat_mutxt));
	count = 0;
	while (count < philo->info->num_of_philo)
	{
		if (philo->info->eat_enough[count] == FALSE)
		{
			pthread_mutex_unlock(&(philo->info->finish_eat_mutxt));
			return (FALSE);
		}
		count++;
	}
	pthread_mutex_unlock(&(philo->info->finish_eat_mutxt));
	return (TRUE);
}
