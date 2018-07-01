/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:40:07 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/05 16:14:04 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n != 0)
	{
		if (src < dst)
		{
			while (n-- != 0)
				((unsigned char*)dst)[n] = ((unsigned char*)src)[n];
		}
		else
			ft_memcpy(dst, src, n);
	}
	return (dst);
}
