/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:13:03 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:13:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_finish(t_info *info)
{
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->finish_eat_mutxt));
	pthread_mutex_destroy(&(info->print_mutex));
	ft_free_fork(info->forks, info->num_of_philo);
	ft_free_philos(info->philos, info->num_of_philo);
	free(info->eat_enough);
}
