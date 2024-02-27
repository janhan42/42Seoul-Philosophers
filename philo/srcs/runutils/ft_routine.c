/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:30:49 by janhan            #+#    #+#             */
/*   Updated: 2024/02/27 19:04:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * pthraed_create시 부여할 루틴 함수
 * 먹기->다먹었는지->잠자기->생각하기
 * @param philo
 * @return void*
 */
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
