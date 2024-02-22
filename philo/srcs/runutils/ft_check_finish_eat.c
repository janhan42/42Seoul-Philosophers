/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_finish_eat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:57:57 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 08:40:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
/**
 * @brief
 * must_eat_count 즉 최소 식사 수가 정해져있을때 체크하는 함수
 * @param philo
 * @return int TRUE or FALSE
 */
int	ft_check_finish_eat(t_philo *philo)
{
	long	count;

	usleep(100); // 충돌 방지 및 업데이트 시간 주기용
	pthread_mutex_lock(&(philo->info->finish_eat_mutxt)); // 뮤텍스 락
	count = 0;
	while (count < philo->info->num_of_philo) // 모든 철학자를 돌면서 한명이라도 다 먹지 못했으면 FALSE
	{
		if (philo->info->eat_enough[count] == FALSE)
		{
			pthread_mutex_unlock(&(philo->info->finish_eat_mutxt));
			return (FALSE);
		}
		count++;
	}
	pthread_mutex_unlock(&(philo->info->finish_eat_mutxt)); // 다먹었을때 뮤텍스 언락
	return (TRUE); // 애들 다 먹음 ㅋㅋ
}
