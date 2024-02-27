/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:04:49 by janhan            #+#    #+#             */
/*   Updated: 2024/02/27 19:24:37 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * 철학자의 변수 초기화
 * @if (info-philos[count]->philo_id == 1)
 * @첫번째 철학자 일때 오른쪽 포크를 마지막 철학자의 포크로 지정
 * @param info
 * @param count
 */
static void	ft_set_philo_vars(t_info *info, long count)
{
	info->philos[count]->philo_id = count + 1;
	info->philos[count]->info = info;
	info->philos[count]->left_fork = info->forks[count];
	if (info->philos[count]->philo_id == 1)
		info->philos[count]->right_fork = info->forks[info->num_of_philo -1];
	else
		info->philos[count]->right_fork = info->forks[count - 1];
	info->philos[count]->left_fork_up = FALSE;
	info->philos[count]->right_fork_up = FALSE;
	info->philos[count]->eat_count = 0;
	pthread_mutex_init(&(info->philos[count]->info->eat_enough_flag), NULL);
}

/**
 * @brief
 * 철학자 배열 생성
 * @param info
 * @return int
 */
int	ft_philo_init(t_info *info)
{
	long	count;

	count = 0;
	info->philos
		= (t_philo **)malloc(sizeof(t_philo *) * (info->num_of_philo + 1));
	if (info->philos == NULL)
		return (FAILURE);
	while (count < info->num_of_philo)
	{
		info->philos[count] = (t_philo *)malloc(sizeof(t_philo));
		if (info->philos[count] == NULL)
		{
			ft_free_philos(info->philos, count);
			ft_free_fork(info->forks, info->num_of_philo);
			free(info->eat_enough);
			return (FAILURE);
		}
		ft_set_philo_vars(info, count);
		count++;
	}
	info->philos[count] = NULL;
	return (SUCCESS);
}
