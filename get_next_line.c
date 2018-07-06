/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:32:35 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/06 14:20:59 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_line(char **content)
{
	int		end;
	char	*result_line;

	if (ft_strchr(*content, '\n'))
	{
		end = ft_strchr(*content, '\n') - *content;
		result_line = ft_strsub(*content, 0, end);
	}
	else
		result_line = ft_strdup(*content);
	return (result_line);
}

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


t_string	*make_list(t_string **text, const int fd)
{
	t_string	*list;

	if (*text == NULL)
	{
		*text = ft_lststringnew("\0", 0);
		(*text)->filedesc = fd;
		return (*text);
	}
	if ((*text)->filedesc != fd)
	{
		list = *text;
		while (list->next)
		{
			if (list->filedesc == fd)
				return (list);
			list = list->next;
		}
		if (list->filedesc == fd)
			return (list);
		list->next = ft_lststringnew("\0", 0);
		list->next->filedesc = fd;
		return (list->next);
	}
	return (*text);
}

int				get_next_line(const int fd, char **line)
{
	static t_string	*text = NULL;
	char			*buffer;
	t_string		*temp;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	temp = make_list(&text, fd);
	if (!(buffer = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((temp->index = read(fd, buffer, BUFF_SIZE)))
	{
		if (temp->index < 0)
			return (-1);
		buffer[temp->index] = '\0';
//		printf("buf: %s\n", buffer);  //!!!!!!
		temp->content = NULL ? (temp->content = ft_strdup(buffer))\
		 : (temp->content = ft_strjoin(temp->content, buffer));
		 *line = get_line(&(temp->content));
//		printf("temp: %s\n", temp->content);  //!!!!!
		if (ft_strchr(buffer, '\n'))
			break;
	}
	if (temp->content)
	{
		if (!(*line = get_line(&(temp->content))))
			return (-1);
	}
	else
		return (0);
//	printf("STATIC: %s\n", text->content);  //!!!!!
	// нужно исправить утечки памяти
	free(buffer);
	return (1);
}
