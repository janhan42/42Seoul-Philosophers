/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:14:17 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 07:42:43 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * 시간정보 초기화 함수
 * @param info
 * @return int 성공 여부 리턴
 */
int	ft_time_init(t_info *info)
{
	struct timeval	temp_time;

	if (gettimeofday(&temp_time, NULL) == -1) // temp_time에 시간정보 처리 | 예외처리
		return (FAILURE);
	info->time_booted = (temp_time.tv_sec) * 1000 + (temp_time.tv_usec) / 1000; //info->time_booted 프로글매 시작 시간 저장
	return (SUCCESS); // tv_sec은 초단위 tv_usec은 마이크로 초 단위 (tv_sec)-> 2 * 1000 = 2000 (tv_usec)-> 500,000 / 1000 = 500 -> 2500밀리초 형식
}
