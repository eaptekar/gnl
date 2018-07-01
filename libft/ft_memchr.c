/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:52:46 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/05 16:14:23 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n != 0)
	{
		while (n-- != 0)
		{
			if (*(unsigned char*)s == (unsigned char)c)
				return ((void*)s);
			s++;
			i++;
		}
	}
	return (0);
}
