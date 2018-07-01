/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:37:53 by eaptekar          #+#    #+#             */
/*   Updated: 2018/01/12 12:42:01 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	i = 1;
	if (min >= max)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (0);
	tab[0] = min;
	while (i < (max - min))
	{
		tab[i] = tab[i - 1] + 1;
		i++;
	}
	return (tab);
}
