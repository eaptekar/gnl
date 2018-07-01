/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:40:03 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/27 19:24:36 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int n)
{
	size_t		len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	num;
	int		k;

	k = numlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		num = -n;
		k++;
	}
	else
		num = n;
	if (!(str = (char*)malloc(sizeof(char) * k + 1)))
		return (NULL);
	str[k] = '\0';
	str[--k] = num % 10 + '0';
	while (num /= 10)
		str[--k] = num % 10 + '0';
	if (n < 0)
		str[--k] = '-';
	return (str);
}
