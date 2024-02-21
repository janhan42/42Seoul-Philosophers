/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:16:34 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 07:42:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_create_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo) // 각 필로에 대응하는 쓰레드 생성
	{
		if (pthread_create(&philos[philo_count]->thread, NULL, // ft_routine을 기반으로 하는 쓰레드 생성
			ft_routine, philos[philo_count]) != 0) // pthread_create 성공값인 0 이 아니면 예외처리
		{
			ft_free_philos(philos, info->num_of_philo);
			ft_free_fork(info->forks, info->num_of_philo);
			free(info->eat_enough);
			return (FAILURE);
		}
		philo_count++;
	}
	return (SUCCESS);
}

static int	ft_join_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo)
	{
		if (pthread_join(philos[philo_count]->thread, NULL) != 0) // pthread_join으로 각 철학자의 쓰레드 종료를 대기 | 대기 실패시 프리후 FAILURE
		{
			ft_free_philos(philos, info->num_of_philo);
			ft_free_fork(info->forks, info->num_of_philo);
			free(info->eat_enough);
			return (FAILURE);
		}
		philo_count++;
	}
	return (SUCCESS);
}

int	ft_start_logic(t_info *info, t_philo **philos)
{
	if (pthread_mutex_init(&(info->die_mutex), NULL) != 0) // die_mutex 초기화
		return (FAILURE);
	if (pthread_mutex_init(&(info->finish_eat_mutxt), NULL) != 0) // finish_eat_mutex 초기화
		return (FAILURE);
	if (pthread_mutex_init(&(info->print_mutex), NULL) != 0) // 출력 mutex 초기화
		return (FAILURE);
	if (ft_create_thread(info, philos) == FAILURE) // 쓰레드 생성 함수
		return (FAILURE);
	if (ft_join_thread(info, philos) == FAILURE) // 대기 함수
		return (FAILURE);
	return (SUCCESS);
}
