/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:08:08 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:12:45 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_free_philos(t_philo **philos, long count)
{
	long	i;

	i = 0;
	while (i < count)
		free(philos[i++]);
	free(philos);
}

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
