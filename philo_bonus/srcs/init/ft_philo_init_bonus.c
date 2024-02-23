/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:21:31 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 16:24:02 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	ft_philo_init(int ac, char **av, t_philo *philo)
{
	philo->ac = ac;
	philo->av = av;
	philo->num_of_philo = ft_atol(av[1]);
	philo->time_to_die = ft_atol(av[2]);
	philo->time_to_eat = ft_atol(av[3]);
	philo->time_to_sleep = ft_atol(av[4]);
	philo->last_eat_time = 0;
	philo->eat_count = 0;
	if (ac == 5)
		philo->must_eat_count = 0;
	else if (ac == 6)
		philo->must_eat_count = ft_atol(av[5]);
	if (philo->num_of_philo <= 0 || philo->time_to_die <= 0
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0
		|| philo->must_eat_count < 0
		|| (philo->ac == 6 && philo->must_eat_count == 0))
		return (FAILURE);
	return (SUCCESS);
}
