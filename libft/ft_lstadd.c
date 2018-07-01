/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:56:19 by eaptekar          #+#    #+#             */
/*   Updated: 2017/12/04 21:08:43 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*head;

	head = *alst;
	if (!alst || !new)
		return ;
	if (!head)
		*alst = new;
	else
	{
		new->next = head;
		*alst = new;
	}
}
