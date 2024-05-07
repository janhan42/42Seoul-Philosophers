/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:43:51 by janhan            #+#    #+#             */
/*   Updated: 2024/03/02 08:05:44 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

static int	ft_getlen(long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(long n)
{
	int		len;
	char	*result;

	len = ft_getlen(n);
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	if (n == 0)
		result[0] = '0';
	result[len] = '\0';
	len--;
	while (n != 0)
	{
		result[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	return (result);
}
