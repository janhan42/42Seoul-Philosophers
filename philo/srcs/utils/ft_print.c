/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:43:18 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:12:39 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	ft_print(t_info *info, long id, char *msg)
{
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %ld %s", ft_current_time(info), id, msg);
	pthread_mutex_unlock(&(info->print_mutex));
}
