/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:32:35 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/06 19:37:57 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_line(char *content)
{
	int		end;
	char	*result_line;

	if (ft_strchr(content, '\n'))
	{
		end = ft_strchr(content, '\n') - content;
		result_line = ft_strsub(content, 0, end);
	}
	else
		result_line = ft_strdup(content);
	return (result_line);
}

char	*join_free(char *content, char *buffer)
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	j = 0;
	if (!content || !buffer)
		return (NULL);
	if (!(concat = (char*)malloc(sizeof(char) * (ft_strlen(content) + ft_strlen(buffer) + 1))))
		return (NULL);
	while (content[i])
	{
		concat[i] = content[i];
		i++;
	}
	while (buffer[j])
		concat[i++] = buffer[j++];
	free(content);
	concat[i] = '\0';
	return (concat);
}

char		*ft_del_mem(char *content)
{
	size_t	l;
	char	*arr;

	l = 0;
	if (ft_strchr(content, '\n'))
	{
		while (content[l] != '\n' && content[l])
			l++;
		if (!content[l + 1])
		{
			free(content);
			return (NULL);
		}
		arr = ft_strdup(&content[l + 1]);
		free(content);
		content = ft_strdup(arr);
		free(arr);
	}
	return (content);
}

t_string	*make_list(t_string **text, const int fd)
{
	t_string	*list;

	if (*text == NULL)
	{
		*text = (t_string*)ft_lstnew(NULL, 0);
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
		list->next = (t_string*)ft_lstnew(NULL, 0);
		list->next->filedesc = fd;
		return (list->next);
	}
	return (*text);
}

int			get_next_line(const int fd, char **line)
{
	static t_string	*text = NULL;
	char			buffer[BUFF_SIZE + 1];
	t_string		*temp;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	temp = make_list(&text, fd);
	while ((temp->index = read(fd, buffer, BUFF_SIZE)))
	{
		if (temp->index < 0)
			return (-1);
		buffer[temp->index] = '\0';
		temp->content = !temp->content ? ft_strdup(buffer) : join_free(temp->content, buffer);
		*line = get_line(temp->content);
		if (ft_strchr(temp->content, '\n'))
			return ((temp->content = ft_del_mem(temp->content)) ? 1 : 1);
		free(*line);
	}
	if (temp->content)
		*line = get_line(temp->content);
	else
		return (0);
	if (ft_strchr(temp->content, '\n'))
		return ((temp->content = ft_del_mem(temp->content)) ? 1 : 1);
	return ((temp->content = NULL) ? 1 : 1);
}
