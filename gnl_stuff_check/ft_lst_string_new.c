/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_string_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 18:21:06 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/06 18:21:19 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_string	*ft_lststringnew(char *content, int filedesc)
{
	t_string	*tmp;

	if (!(tmp = (t_string*)malloc(sizeof(t_string))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->filedesc = 0;
	}
	else
	{
		if (!(tmp->content = malloc(filedesc)))
		{
			free(tmp);
			return (NULL);
		}
		ft_memmove(tmp->content, content, filedesc);
		tmp->filedesc = filedesc;
	}
	tmp->next = NULL;
	return (tmp);
}