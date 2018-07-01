/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:36:56 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/25 22:39:56 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = (char*)malloc(sizeof(char) * len + 1);
	if (sub && s)
	{
		while (len--)
		{
			sub[i] = s[start++];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
