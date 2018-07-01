/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:19:13 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/18 22:02:48 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t n)
{
	char		*d;
	const char	*s;
	size_t		free;
	size_t		size;

	d = s1;
	s = s2;
	free = n;
	while (*d && free-- != 0)
		d++;
	size = d - s1;
	free = n - size;
	if (free == 0)
		return (size + ft_strlen(s));
	while (*s)
	{
		if (free != 1)
		{
			*d++ = *s;
			free--;
		}
		s++;
	}
	*d = '\0';
	return (size + (s - s2));
}
