/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:13:03 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 09:12:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <pthread.h>

void	ft_finish(t_info *info)
{
	pthread_mutex_destroy(&(info->die_mutex)); // 뮤텍스 삭제
	pthread_mutex_destroy(&(info->finish_eat_mutxt)); // 뮤텍스 삭제
	pthread_mutex_destroy(&(info->print_mutex)); // 뮤텍스 삭제
	ft_free_fork(info->forks, info->num_of_philo); // 메로리 해제
	ft_free_philos(info->philos, info->num_of_philo); // 메모리 해제
	free(info->eat_enough); // 메모리 해제
}
