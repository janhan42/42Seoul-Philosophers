/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:30:49 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 07:42:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_routine(void *philo) // 철학자의 반복 행동 함수
{
	((t_philo *)philo)->last_eat_time
		= ft_current_time(((t_philo *)philo)->info); // 마지막으로 먹은 시간 저장
	if (((t_philo *)philo)->philo_id % 2 == 1) // 포크를 동시에 못집게 홀수 철학자들에게 딜레이 적용 데드락 방지 ㄹㅇ ㅋㅋ
		usleep(((t_philo *)philo)->info->time_to_sleep / 4 * 1000);
	while (TRUE)
	{
		if (ft_eat(philo) == FAILURE) // 먹기
			break ;
		if (ft_check_finish_eat(philo) == TRUE) // 먹기 체크
			break ;
		if (ft_sleep(philo) == FAILURE) // 잠자기
			break ;
		if (ft_think(philo) == FAILURE) // 생각하기
			break ;
	}
	return (SUCCESS);
}
