/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:58:52 by janhan            #+#    #+#             */
/*   Updated: 2024/02/16 12:17:16 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_isspace(int c)
{
	return
	(c == ' '|| c == '\t'|| c == '\n'||\
	c == '\v'|| c == '\f'|| c == '\r');
}

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (TRUE);
	else
		return (FALSE);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}
