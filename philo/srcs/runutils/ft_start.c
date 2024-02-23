/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:16:34 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 10:52:14 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * ft_routine을 실행하는 쓰레드를 생성
 * @param info
 * @param philos
 * @if (pthread_create != 0) 쓰레드 생성 실패 예외처리
 * @return int 성공여부
 */
static int	ft_create_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo)
	{
		if (pthread_create(&philos[philo_count]->thread, NULL,
				ft_routine, philos[philo_count]) != 0)
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

/**
 * @brief
 * 생성된 philos쓰레드들을 종료될때 까지 대기 시키는 함수
 * @param info
 * @param philos
 * @if (pthread_join) != 0 대기실패시 예외처리
 * @return int 성공여부
 */
static int	ft_join_thread(t_info *info, t_philo **philos)
{
	long	philo_count;

	philo_count = 0;
	while (philo_count < info->num_of_philo)
	{
		if (pthread_join(philos[philo_count]->thread, NULL) != 0)
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

/**
 * @brief
 * 쓰레드 생성 및 대기
 * @param info
 * @param philos
 * @return int
 */
int	ft_start_logic(t_info *info, t_philo **philos)
{
	if (pthread_mutex_init(&(info->die_mutex), NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&(info->finish_eat_mutxt), NULL) != 0)
		return (FAILURE);
	if (pthread_mutex_init(&(info->print_mutex), NULL) != 0)
		return (FAILURE);
	if (ft_create_thread(info, philos) == FAILURE)
		return (FAILURE);
	if (ft_join_thread(info, philos) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
