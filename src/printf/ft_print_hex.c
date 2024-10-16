/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:01:24 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_hex_len(unsigned int hx)
{
	int	len;

	len = 0;
	while (hx != 0)
	{
		len++;
		hx = hx / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int hx, int uppercase)
{
	if (hx >= 16)
	{
		ft_put_hex(hx / 16, uppercase);
		ft_put_hex(hx % 16, uppercase);
	}
	else
	{
		if (hx < 10)
			ft_putchar_fd((hx + '0'), 1);
		else
		{
			if (uppercase)
				ft_putchar_fd((hx - 10 + 'A'), 1);
			if (!uppercase)
				ft_putchar_fd((hx - 10 + 'a'), 1);
		}
	}
}

int	ft_print_hex(unsigned int hx, int uppercase)
{
	if (hx == 0)
		return (ft_print_char('0'));
	else
		ft_put_hex(hx, uppercase);
	return (ft_hex_len(hx));
}
