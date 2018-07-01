/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:40:06 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/05 20:47:17 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *temp;

	temp = s;
	while (*temp)
		temp++;
	while (temp >= s)
	{
		if (*temp == (char)c)
			return ((char*)temp);
		if (temp == '\0' && c == '\0')
			return (NULL);
		temp--;
	}
	return (0);
}
