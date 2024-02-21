/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:30:49 by janhan            #+#    #+#             */
/*   Updated: 2024/02/21 21:33:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_routine(void *philo)
{
	((t_philo *)philo)->last_eat_time
		= ft_current_time(((t_philo *)philo)->info);
	if (((t_philo *)philo)->philo_id % 2 == 1)
		usleep(((t_philo *)philo)->info->time_to_sleep / 4 * 1000);
	while (TRUE)
	{
		if (ft_eat(philo) == FAILURE)
			break ;
		if (ft_check_finish_eat(philo) == TRUE)
			break ;
		if (ft_sleep(philo) == FAILURE)
			break ;
		if (ft_think(philo) == FAILURE)
			break ;
	}
	return (SUCCESS);
}
