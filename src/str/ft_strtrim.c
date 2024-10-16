/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergero <jbergero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 02:58:26 by jbergero          #+#    #+#             */
/*   Updated: 2024/10/16 03:00:16 by jbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string

s1:  The string to be trimmed.
set:  The reference set of characters to trim.


Return value
The trimmed string.
NULL if the allocation fails.
*/
static int	is_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	end = ft_strlen(s1);
	start = 0;
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end - 1], set))
		end--;
	if (start == end)
		res = ft_substr(s1, start, 1);
	else if (start > end)
		res = ft_strdup("");
	else
		res = ft_substr(s1, start, (end - start));
	return (res);
}
