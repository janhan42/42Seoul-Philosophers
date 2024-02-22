/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sem_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:46:36 by janhan            #+#    #+#             */
/*   Updated: 2024/02/22 09:49:02 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"
#include <sys/fcntl.h>
#include <sys/semaphore.h>

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
