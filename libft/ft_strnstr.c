/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:35:15 by eaptekar          #+#    #+#             */
/*   Updated: 2018/01/12 13:11:08 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = (char*)src;
	i = 0;
	if (to_find[0] == '\0')
		return (tmp);
	while (src[i])
	{
		j = 0;
		while (src[i + j] == to_find[j] && (i + j) < len)
		{
			j++;
			if (to_find[j] == '\0')
				return (tmp + i);
		}
		i++;
	}
	return (0);
}
