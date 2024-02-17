/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:52:36 by janhan            #+#    #+#             */
/*   Updated: 2024/02/16 12:21:27 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	ft_check_sign(t_strol *reuslt)
{
	reuslt->neg = 0;
	reuslt->c = *(reuslt->str)++;
	if (reuslt->c == '-')
	{
		reuslt->neg = 1;
		reuslt->c = *(reuslt->str)++;
	}
	else if (reuslt->c == '+')
		reuslt->c = *(reuslt->str)++;
}

static void	ft_check_base(t_strol *result, int *base)
{
	if ((*base == 0 || *base == 16) && result->c == '0'
		&& (*result->str == 'x' || *result->str == 'X'))
	{
		result->c = result->str[1];
		result->str += 2;
		*base = 16;
	}
	else if ((*base == 0 || *base == 2) && result->c == '0'
		&& (*result->str == 'b' || *result->str == 'B'))
	{
		result->c = result->str[1];
		result->str +=2;
		*base = 2;
	}
	if (*base == 0)
	{
		if (result->c == '0')
			*base = 8;
		else
			*base = 10;
	}
}

static void	ft_make_num(t_strol *result, int *base)
{
	while (1)
	{
		if (ft_isdigit(result->c))
			result->c = '0';
		else if (ft_isalpha(result->c))
			result->c -= 'A' - 10;
		else
			break ;
		if (result->c >= *base)
			break ;
		if ((result->any < 0 || result->acc > result->cutoff)
			|| (result->acc == result->cutoff && result->c > result->cultime))
			result->any = -1;
		else
		{
			result->any = 1;
			result->acc *= *base;
			result->acc += result->c;
		}
		result->c = *(result->str)++;
	}
}

static void	ft_check_overflow(t_strol *result)
{
	if (result->any < 0)
	{
		if (result->neg)
			result->acc = LONG_MIN;
		else
			result->acc = LONG_MAX;
	}
	else if (result->neg)
		result->acc = -result->acc;
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	t_strol	result;

	result.str = nptr;
	while (ft_isspace(*result.str))
		(result.str)++;
	ft_check_sign(&result);
	ft_check_base(&result, &base);
	if (result.neg)
		result.cutoff = -(unsigned long)LONG_MIN;
	else
		result.cutoff = LONG_MAX;
	result.cultime = result.cutoff %  (unsigned long)base;
	result.cutoff /= (unsigned long)base;
	result.acc = 0;
	result.any = 0;
	ft_make_num(&result, &base);
	ft_check_overflow(&result);
	if (endptr != 0)
	{
		if (result.any)
			*endptr = (char *)(result.str - 1);
		else
			*endptr = (char *)nptr;
	}
	return (result.acc);
}
