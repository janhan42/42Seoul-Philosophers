/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:11:12 by janhan            #+#    #+#             */
/*   Updated: 2024/02/16 11:12:40 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

/**
 * @brief 
 * 메세지와 에러 코드를 받아서
 * 메시지 출력후 에러코드로 return;
 * @param massege 출력할 메세지
 * @param error_code 리턴 벨류
 * @return int 
 */
int	ft_error(char *massege, int error_code)
{
	printf("Error\n%s\n", massege);
	return (error_code);
}
