/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:27 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 09:04:10 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_check_died(philo->info, philo) == TRUE) // 죽었는지 확인
		return (FAILURE);
	ft_print(philo->info, philo->philo_id, "is thinking\n"); // 출력
	return (SUCCESS);
}
