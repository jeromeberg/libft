/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:01:50 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_uint(unsigned int nb)
{
	int	digits;

	digits = 0;
	if (nb >= 10)
	{
		digits += ft_print_uint(nb / 10);
		digits += ft_print_uint(nb % 10);
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		digits++;
	}
	return (digits);
}
