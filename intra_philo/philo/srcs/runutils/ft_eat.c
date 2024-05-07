/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:37:17 by janhan            #+#    #+#             */
/*   Updated: 2024/03/12 09:57:23 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

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
