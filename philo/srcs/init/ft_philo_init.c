/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:04:49 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 07:42:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_set_philo_vars(t_info *info, long count)
{
	info->philos[count]->philo_id = count + 1; // 철학자 ID지정
	info->philos[count]->info = info; // 정보 저장
	info->philos[count]->left_fork = info->forks[count]; // 철학자의 좌 포크 지정
	if (info->philos[count]->philo_id == 1) // 첫번째 철학자일때 마지막 철학자의 포크로 지정
		info->philos[count]->right_fork = info->forks[info->num_of_philo -1];
	else
		info->philos[count]->right_fork = info->forks[count - 1];
	info->philos[count]->left_fork_up = FALSE; // 포크를 잡았는지 설정 TRUE=잡았음 FALSE=못잡았음
	info->philos[count]->right_fork_up = FALSE;
	info->philos[count]->eat_count = 0; // 철학자의 식사 카운트 초기화
}

int	ft_philo_init(t_info *info)
{
	long	count;

	count = 0;
	info->philos // 철학자 메모리 할당
		= (t_philo **)malloc(sizeof(t_philo *) * (info->num_of_philo + 1));
	if (info->philos == NULL) // 메모리 예외처리
		return (FAILURE);
	while (count < info->num_of_philo)
	{
		info->philos[count] = (t_philo *)malloc(sizeof(t_philo)); // 각 철학자 메모리 할당
		if (info->philos[count] == NULL) // 메로리 예외처리
		{
			ft_free_philos(info->philos, count);
			ft_free_fork(info->forks, info->num_of_philo);
			free(info->eat_enough);
			return (FAILURE);
		}
		ft_set_philo_vars(info, count); // 철학자 정보 초기화
		count++;
	}
	info->philos[count] = NULL; // 마지막 널가드
	return (SUCCESS);
}
