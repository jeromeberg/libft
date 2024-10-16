/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:00:04 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
The	strcmp(void) and strncmp() functions lexicographically
compare the null-terminated strings s1 and s2.

The	strncmp(void) function compares not more than n characters.
Because	strncmp(void) is designed for comparing strings rather than binary
data, characters that appear after a ‘\0’ character are not compared.

The	strcmp(void) and strncmp() functions return an integer greater than,
equal to, or less than 0, according as the string s1 is greater
than, equal to,
or less than the string s2.  The comparison is done using unsigned characters,
so that ‘\200’ is greater than ‘\0’.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
