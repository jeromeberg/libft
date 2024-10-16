/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:01:28 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_int(int nb)
{
	int	digits;

	digits = 0;
	if (nb == -2147483648)
	{
		return (ft_print_str("-2147483648"));
	}
	if (nb < 0)
	{
		digits++;
		ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		digits += ft_print_int(nb / 10);
		digits += ft_print_int(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		digits++;
	}
	return (digits);
}
