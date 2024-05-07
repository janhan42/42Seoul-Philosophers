/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:02:27 by janhan            #+#    #+#             */
/*   Updated: 2024/03/12 07:59:26 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_think(t_philo *philo)
{
	if (ft_check_died(philo->info, philo) == TRUE)
		return (FAILURE);
	ft_print(philo->info, philo->philo_id, "is thinking\n");
	return (SUCCESS);
}
