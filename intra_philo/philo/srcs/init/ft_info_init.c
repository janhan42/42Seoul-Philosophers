/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:15 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:14:15 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_info_init(int ac, char **av, t_info *info)
{
	info->ac = ac;
	info->av = av;
	info->num_of_philo = ft_atol(av[1]);
	info->time_to_die = ft_atol(av[2]);
	info->time_to_eat = ft_atol(av[3]);
	info->time_to_sleep = ft_atol(av[4]);
	if (ac == 5)
		info->must_eat_count = 0;
	else if (ac == 6)
		info->must_eat_count = ft_atol(av[5]);
	info->die_flag = FALSE;
	info->finish_eat_flag = FALSE;
	info->first_die_time = -1;
	if (info->num_of_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->must_eat_count < 0
		|| (info->ac == 6 && info->must_eat_count == 0))
		return (FAILURE);
	info->eat_enough = (long *)malloc(sizeof(long) * info->num_of_philo);
	memset(info->eat_enough, 0, info->num_of_philo);
	return (SUCCESS);
}
