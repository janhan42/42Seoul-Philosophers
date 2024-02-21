/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:15:15 by janhan            #+#    #+#             */
/*   Updated: 2024/02/21 23:52:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * philosopher의 기본적인 정보를 초기화 시키는 함수.
 * @param ac
 * @param av
 * @param info
 * @return int 성공 여부를 리턴
 */
int	ft_info_init(int ac, char **av, t_info *info)
{
	info->ac = ac;
	info->av = av;
	info->num_of_philo = ft_atol(av[1]); // 철학자의 인원수 입력
	info->time_to_die = ft_atol(av[2]); // 철학자의 수명 입력
	info->time_to_eat = ft_atol(av[3]); // 철학자의 밥 먹는 시간 입력
	info->time_to_sleep = ft_atol(av[4]); // 철학자가 자는 시간 입력
	if (ac == 5) // 최소 식사 인자가 없으면
		info->must_eat_count = 0; // must_eat_count를 0
	else if (ac == 6) // 최소 식사 인자가 들어오면
		info->must_eat_count = ft_atol(av[5]); // 최소 식사수 입력
	info->die_flag = FALSE; // 사망 플래그 입력
	info->finish_eat_flag = FALSE; // 다 먹었는지 플래그 입력
	info->first_die_time = -1; // 언제 죽었는지 초기화
	if (info->num_of_philo <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->must_eat_count < 0
		|| (info->ac == 6 && info->must_eat_count == 0))
		return (FAILURE);
	info->eat_enough = (long *)malloc(sizeof(long) * info->num_of_philo);
	memset(info->eat_enough, 0, info->num_of_philo);
	return (SUCCESS);
}
