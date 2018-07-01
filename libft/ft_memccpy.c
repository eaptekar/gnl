/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:46:06 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/06 16:19:00 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n-- != 0)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*(unsigned char*)dst = *(unsigned char*)src;
			return (++dst);
		}
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	}
	return (0);
}
