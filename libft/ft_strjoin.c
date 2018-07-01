/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:49:57 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/25 15:21:29 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*concat;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	concat = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (concat)
	{
		ft_strcpy(concat, s1);
		ft_strcat(concat, s2);
		return (concat);
	}
	return (NULL);
}
