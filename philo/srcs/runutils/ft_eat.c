/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:37:17 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:02:54 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <pthread.h>

/**
 * @brief
 * 오른쪽 포크 집는 함수
 * @pick 뮤텍스 락 시도->philo->right_fork->pickable == TRUE면 상태 변경
 * @nopickable 이면 뮤텍스 언락후 FAILURE 리턴
 * @param philo
 * @return int 성공 여부를 리턴
 */
static int	ft_pick_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex));
	if (philo->right_fork->pickable == TRUE)
	{
		philo->right_fork->pickable = FALSE;
		philo->right_fork_up = TRUE;
		ft_print(philo->info, philo->philo_id, "has taken a fork\n");
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		return (SUCCESS);
	}
	else
	{
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		return (FAILURE);
	}
}

/**
 * @brief
 * 왼쪽 포크 집는 함수
 * @pick 뮤텍스 락 시도->philo->right_fork->pickable == TRUE면 상태 변경
 * @nopickable 이면 뮤텍스 언락후 FAILURE 리턴
 * @param philo
 * @return int 성공 여부를 리턴
 */
static int	ft_pick_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex));
	if (philo->left_fork->pickable == TRUE)
	{
		philo->left_fork->pickable = FALSE;
		philo->left_fork_up = TRUE;
		ft_print(philo->info, philo->philo_id, "has taken a fork\n");
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return (SUCCESS);
	}
	else
	{
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return (FAILURE);
	}
}

/**
 * @brief
 * 좌우 포크를 뮤텍스 후 내려두었다고 정보 변경을 한다
 * @param philo
 * @return int
 */
static int	ft_put_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex));
	philo->right_fork_up = FALSE;
	philo->right_fork->pickable = TRUE;
	pthread_mutex_unlock(&(philo->right_fork->mutex));
	pthread_mutex_lock(&(philo->left_fork->mutex));
	philo->left_fork_up = FALSE;
	philo->left_fork->pickable = TRUE;
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	return (SUCCESS);
}

/**
 * @brief
 * 실질적으로 먹는 함수
 * info->time_to_eat 즉 먹는데 걸리는 시간동안 돌아감
 * must_eat_count 옵션이 있을시 다 먹었다면 eat_enough를 TRUE로 바꿔서 다 먹었다고 정보변경
 * @param start_time
 * @param philo
 * @return int
 */
static int	ft_eating(long start_time, t_philo *philo)
{
	ft_print(philo->info, philo->philo_id, "is eating\n");
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_eat)
	{
		if (ft_is_other_died(philo->info) == TRUE)
			return (FAILURE);
	}
	philo->eat_count++;
	if (philo->eat_count >= philo->info->must_eat_count
		&& philo->info->must_eat_count != 0)
	{
		pthread_mutex_lock(&(philo->info->eat_enough_flag));
		philo->info->eat_enough[philo->philo_id - 1] = TRUE;
		pthread_mutex_unlock(&(philo->info->eat_enough_flag));
	}
	return (SUCCESS);
}

/**
 * @brief
 * 철학자가 밥을 먹는 함수
 * 오른쪽 포크집기->왼쪽 포크집기->last_eat_time = ft_current_time->먹기->포크 내려두기
 * @param philo
 * @return int
 */
int	ft_eat(t_philo *philo)
{
	while (ft_pick_right_fork(philo) == FAILURE)
	{
		if (ft_check_died(philo->info, philo) == TRUE)
			return (FAILURE);
	}
	while (ft_pick_left_fork(philo) == FAILURE)
	{
		if (ft_check_died(philo->info, philo) == TRUE)
			return (FAILURE);
	}
	philo->last_eat_time = ft_current_time(philo->info);
	if (ft_eating(ft_current_time(philo->info), philo) == FAILURE)
		return (FAILURE);
	ft_put_fork(philo);
	return (SUCCESS);
}
