/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:53:45 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/06 18:45:00 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	size_t i;
	size_t j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char*)src);
	while (src[i])
	{
		j = 0;
		while (src[i + j] == to_find[j])
		{
			j++;
			if (!to_find[j])
				return ((char*)src + i);
		}
		i++;
	}
	return (0);
}
