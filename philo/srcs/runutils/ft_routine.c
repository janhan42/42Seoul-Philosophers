/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:30:49 by janhan            #+#    #+#             */
/*   Updated: 2024/03/10 07:45:54 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"
#include <unistd.h>

void	*ft_routine(void *philo)
{
	((t_philo *)philo)->last_eat_time
		= ft_current_time(((t_philo *)philo)->info);
	if (((t_philo *)philo)->philo_id % 2 == 1)
		usleep(((t_philo *)philo)->info->time_to_eat / 4 * 1000);
	while (TRUE)
	{
		if (ft_eat(philo) == FAILURE || ft_check_finish_eat(philo) == TRUE)
			break ;
		if (ft_sleep(philo) == FAILURE || ft_check_finish_eat(philo) == TRUE)
			break ;
		if (ft_think(philo) == FAILURE || ft_check_finish_eat(philo) == TRUE)
			break ;
	}
	return (SUCCESS);
}
