/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:17:28 by jeekpark          #+#    #+#             */
/*   Updated: 2024/02/22 14:02:59 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	ft_print(t_philo *philo, long id, char *msg)
{
	sem_wait(philo->print);
	printf("%ld %ld %s", ft_current_time(philo), id, msg);
	sem_post(philo->print);
}
