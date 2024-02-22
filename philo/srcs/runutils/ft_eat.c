/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:37:17 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 08:16:46 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_pick_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex)); // 오른쪽 포크 뮤텍스에 락 시도 | 누가 쓰고있으면 대기 상태
	if (philo->right_fork->pickable == TRUE) // 포크를 집을수 있으면
	{
		philo->right_fork->pickable = FALSE; // 못집게 상태 변환
		philo->right_fork_up = TRUE; // 철학자 정보 변경 오른쪽 포크 집었음
		ft_print(philo->info, philo->philo_id, "has taken a fork\n"); // 출력
		pthread_mutex_unlock(&(philo->right_fork->mutex)); // 언락
		return (SUCCESS);
	}
	else // 포크를 못집으면 대기상태 해제 후 나가기
	{
		pthread_mutex_unlock(&(philo->right_fork->mutex));
		return (FAILURE);
	}
}

static int	ft_pick_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork->mutex)); // 왼쪽 포크 뮤텍스에 락 시도 | 누가 쓰고있으면 대기 상태
	if (philo->left_fork->pickable == TRUE) // 포크를 집을수 있으면
	{
		philo->left_fork->pickable = FALSE; // 못집게 변환
		philo->left_fork_up = TRUE; // 철학자 정보 변경 왼쪽 포크 잡았음
		ft_print(philo->info, philo->philo_id, "has taken a fork\n"); // 출력
		pthread_mutex_unlock(&(philo->left_fork->mutex)); // 언락
		return (SUCCESS);
	}
	else // 포크를 못집으면 대기상태 해제 후 나가기
	{
		pthread_mutex_unlock(&(philo->left_fork->mutex));
		return (FAILURE);
	}
}

static int	ft_put_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork->mutex)); // 포크에 뮤텍스
	philo->right_fork_up = FALSE; // 철학자 정보 변경
	philo->right_fork->pickable = TRUE; // 포크 정보 변경
	pthread_mutex_unlock(&(philo->right_fork->mutex)); // 뮤텍스 해제
	pthread_mutex_lock(&(philo->left_fork->mutex)); // 포크에 뮤텍스
	philo->left_fork_up = FALSE; // 철학자 정보 변경
	philo->left_fork->pickable = TRUE; // 포크 정보 변경
	pthread_mutex_unlock(&(philo->left_fork->mutex)); // 뮤텍스 해제
	return (SUCCESS);
}

static int	ft_eating(long start_time, t_philo *philo)
{
	ft_print(philo->info, philo->philo_id, "is eating\n"); // 먹는다고 출력
	while (ft_current_time(philo->info) - start_time
		< philo->info->time_to_eat) // current_time - start_time이 time_to_eat시간보다 적을때 까지 반복
	{
		if (ft_is_other_died(philo->info) == TRUE) // 그동안 다른 애들이 죽으면 나가기
			return (FAILURE);
	}
	philo->eat_count++; // 아니면 먹은 카운트 올리기
	if (philo->eat_count >= philo->info->must_eat_count //eat_count가 최소먹어야하는 횟수보다 크거나 같고
		&& philo->info->must_eat_count != 0) // must_eat_count옵션이 있으면
		philo->info->eat_enough[philo->philo_id - 1] = TRUE; // eat_enough를 TRUE
	return (SUCCESS);
}

int	ft_eat(t_philo *philo)
{
	while (ft_pick_right_fork(philo) == FAILURE) // 오른쪽 포크 집기 시도 | 못잡았으면 반복
	{
		if (ft_check_died(philo->info, philo) == TRUE) // 만약 죽었으면
			return (FAILURE);
	}
	while (ft_pick_left_fork(philo) == FAILURE) // 왼쪽 포크 집기 시도 | 못잡았으면 반복
	{
		if (ft_check_died(philo->info, philo) == TRUE) // 만약 죽어씅면
			return (FAILURE);
	}
	philo->last_eat_time = ft_current_time(philo->info); // 위에 두개다 집었다면
	if (ft_eating(ft_current_time(philo->info), philo) == FAILURE) // 먹기
		return (FAILURE);
	ft_put_fork(philo); // 포크 내려놓기
	return (SUCCESS);
}
