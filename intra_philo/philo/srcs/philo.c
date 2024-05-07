/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:51:25 by janhan            #+#    #+#             */
/*   Updated: 2024/03/12 11:44:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (!(ac == 5 || ac == 6))
		return (ft_error("invaild arguments count", EXIT_FAILURE));
	if (ft_info_init(ac, av, &info) == FAILURE)
		return (ft_error("invaild arguments vector", EXIT_FAILURE));
	if (ft_fork_init(&info) == FAILURE)
		return (ft_error("fork_init() returns FAILURE", EXIT_FAILURE));
	if (ft_philo_init(&info) == FAILURE)
		return (ft_error("philo_init() returns FAILURE", EXIT_FAILURE));
	if (ft_time_init(&info) == FAILURE)
		return (ft_error("gettimeofday() returns -1(error)", EXIT_FAILURE));
	if (ft_start_logic(&info, (info.philos)) == FAILURE)
		return (ft_error("start_logic() returns FAILURE", EXIT_FAILURE));
	ft_finish(&info);
	return (EXIT_SUCCESS);
}
