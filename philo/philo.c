/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:51:25 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 14:23:20 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

/*
	매개인자 개수 확인 -> info 초기화 -> fork 초기화 -> philos 초기화 -> 시작시간 초기화 -> 먹고 자고 생각하고 시작 -> 끝나면 ft_finish 로 메모리 해제
*/
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
