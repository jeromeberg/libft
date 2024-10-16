/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:01:54 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be out in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign
*/

static int	ft_formats(va_list args, const char format)
{
	int	out;

	out = 0;
	if (format == 'c')
		out += ft_print_char(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		out += ft_print_int(va_arg(args, int));
	else if (format == 's')
		out += ft_print_str(va_arg(args, char *));
	else if (format == 'u')
		out += ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'X')
		out += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		out += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'p')
		out += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == '%')
		out += ft_print_char('%');
	return (out);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		out;
	va_list	args;

	i = 0;
	out = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			out += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			out += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (out);
}
