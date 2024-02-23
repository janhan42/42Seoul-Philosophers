/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:13:03 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:34:08 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * 최종함수로 메모리 릭 방지를 위해 모든 뮤텍스 및 메모리 해제
 * @param info
 */
void	ft_finish(t_info *info)
{
	pthread_mutex_destroy(&(info->die_mutex));
	pthread_mutex_destroy(&(info->finish_eat_mutxt));
	pthread_mutex_destroy(&(info->print_mutex));
	ft_free_fork(info->forks, info->num_of_philo);
	ft_free_philos(info->philos, info->num_of_philo);
	free(info->eat_enough);
}
