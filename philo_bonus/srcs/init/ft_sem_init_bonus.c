/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:46:36 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 11:53:03 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

/**
 * @brief
 * sem_unlink로 만약 생성하려던 이름의 세마포어가 있으면 없애고 시작
 * @fork_holder라는 세마포어에 철학자수 만큼으로 초기화
 * @출력을 담당할 print세마포어 또한 동일하게 언링크후 1 개 생성
 * @param philo
 * @return int
 */
int	ft_sem_init(t_philo *philo)
{
	sem_unlink("/fork_holder");
	philo->fork_holder
		= sem_open("/fork_holder", O_CREAT | O_EXCL, 0, philo->num_of_philo);
	if (philo->fork_holder == SEM_FAILED)
		return (FAILURE);
	sem_unlink("/print");
	philo->print
		= sem_open("/print", O_CREAT | O_EXCL, 0, 1);
	if (philo->print == SEM_FAILED)
		return (FAILURE);
	return (SUCCESS);
}
