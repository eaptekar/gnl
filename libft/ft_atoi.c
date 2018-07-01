/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:48:32 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/18 17:48:43 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	n;
	int					i;
	int					sign;

	i = 0;
	n = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' \
			|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f')
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '+')
			sign = 1;
		else
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	if (i > 19 || n > 9223372036854775807)
		return ((sign == 1) ? -1 : 0);
	return (n * sign);
}
