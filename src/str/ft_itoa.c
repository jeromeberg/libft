/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 02:59:15 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	digits_count(int n);

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

RETURNS

The string representing the integer.
NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	int		neg;
	int		dcount;
	char	*res;

	neg = 0;
	if (n < 0)
		neg = 1;
	dcount = digits_count(n) + neg;
	res = (char *)malloc(sizeof(char) * (dcount + 1));
	if (!res)
		return (NULL);
	res[dcount] = '\0';
	if (neg)
	{
		*res = '-';
		res[--dcount] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (dcount-- - neg)
	{
		res[dcount] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

static int	digits_count(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		digits = 1;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
