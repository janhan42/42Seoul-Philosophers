/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:43:18 by janhan            #+#    #+#             */
/*   Updated: 2024/02/23 01:10:24 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief
 * print_mutex를 pthread_mutex_lock 한후 출력->언락
 * @fn print("%ld %ld %s", ft_current_time(info), id, msg);
 * @param info ft_current_time();
 * @param id philo->id
 * @param msg 출력할 메세지
 */
void	ft_print(t_info *info, long id, char *msg)
{
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %ld %s", ft_current_time(info), id, msg);
	pthread_mutex_unlock(&(info->print_mutex));
}
