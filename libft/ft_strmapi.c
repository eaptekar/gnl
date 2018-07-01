/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:49:27 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/18 22:05:31 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	j;
	size_t			i;
	char			*out;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	out = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = f(j++, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
