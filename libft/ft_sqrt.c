/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:41:40 by eaptekar          #+#    #+#             */
/*   Updated: 2018/01/12 12:41:53 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int a;

	a = 2;
	if (nb < 4)
		return (0);
	while (a <= nb / 2)
	{
		if (nb == a * a)
			return (a);
		a++;
	}
	return (0);
}
