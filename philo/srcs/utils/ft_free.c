/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:08:08 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 01:11:31 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * philos를 순회하며 메모리 해제
 * @param philos 시작주소
 * @param count info->num_of_philos;
 */
void	ft_free_philos(t_philo **philos, long count)
{
	long	i;

	i = 0;
	while (i < count)
		free(philos[i++]);
	free(philos);
}

/**
 * @brief
 * forks를 순회하며 메모리 해제
 * @param forks 시작주소
 * @param count info->num_of_philos;
 */
void	ft_free_fork(t_fork **forks, long count)
{
	long	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&(forks[i]->mutex));
		free(forks[i++]);
	}
	free(forks);
}
