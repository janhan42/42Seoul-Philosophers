/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:25:40 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 07:42:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_set_fork_vars(t_info *info, long count)
{
	info->forks[count]->fork_id = count + 1; // 각 포크의 아이디 지정
	info->forks[count]->info = info; // 포크에 info지정
	info->forks[count]->pickable = TRUE; // 사용가능한지 상태 지정 TRUE=사용가능 FALSE=사용불가
	pthread_mutex_init(&(info->forks[count]->mutex), NULL); // info에서 forks의 mutex 초기화
}
/**
 * @brief
 * 포크를 초기화 시키는 함수,
 * @param info
 * @return int 성공여부 리턴
 */
int	ft_fork_init(t_info *info)
{
	long	count;

	count = 0;
	info->forks // info->forks에 필로의 인원수 만큼 메모리 할당
		= (t_fork **)malloc(sizeof(t_fork *) * (info->num_of_philo + 1));
	if (info->forks == NULL) // 말록 예외처리
		return (FAILURE);
	while (count < info->num_of_philo)
	{
		info->forks[count] = (t_fork *)malloc(sizeof(t_fork)); // 각 배열에 말록
		if (info->forks[count] == NULL) // 각 할당 예외처리
		{
			ft_free_fork(info->forks, count);
			free(info->eat_enough);
			return (FAILURE);
		}
		ft_set_fork_vars(info, count); // 포크의 Info 초기화
		count++;
	}
	info->forks[count] = NULL; // 마지막 널가드
	return (SUCCESS);
}
