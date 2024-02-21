/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:25:40 by janhan            #+#    #+#             */
/*   Updated: 2024/02/21 21:29:32 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_set_fork_vars(t_info *info, long count)
{
	info->forks[count]->fork_id = count + 1;
	info->forks[count]->info = info;
	info->forks[count]->pickable = TRUE;
	pthread_mutex_init(&(info->forks[count]->mutex), NULL);
}

int	ft_fork_init(t_info *info)
{
	long	count;

	count = 0;
	info->forks
		= (t_fork **)malloc(sizeof(t_fork *) * (info->num_of_philo + 1));
	if (info->forks == NULL)
		return (FAILURE);
	while (count < info->num_of_philo)
	{
		info->forks[count] = (t_fork *)malloc(sizeof(t_fork));
		if (info->forks[count] == NULL)
		{
			ft_free_fork(info->forks, count);
			free(info->eat_enough);
			return (FAILURE);
		}
		ft_set_fork_vars(info, count);
		count++;
	}
	info->forks[count] = NULL;
	return (SUCCESS);
}
