/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:27 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:18:31 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * philo가 생각하는중
 * @param philo
 * @ft_check_died 중간에 죽었는지 확인
 * @ft_print(philo->info, philo->philo_id, "is thinking\n");
 * @return int 성공여부
 */
int	ft_think(t_philo *philo)
{
	if (ft_check_died(philo->info, philo) == TRUE)
		return (FAILURE);
	ft_print(philo->info, philo->philo_id, "is thinking\n");
	return (SUCCESS);
}
