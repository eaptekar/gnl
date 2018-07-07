/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:32:35 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/06 17:32:40 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*char	*get_line(char **mass)
{
	size_t	start;
	char	*result;

	if (!ft_strchr(*mass, '\n'))
		result = ft_strdup(*mass);
	else
	{
		start = ft_strlen(*mass) - ft_strlen(ft_strchr(*mass, '\n'));
		result = ft_strsub(*mass, 0, start);
	}
	return (result);
}*/

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

char	*ft_del_mem(char *mass)
{
	size_t	l;
	char	*arr;

	l = 0;
	if (ft_strchr(mass, '\n'))
	{
		while (mass[l] != '\n' && mass[l])
			l++;
		if (!mass[l + 1])
		{
			free(mass);
			return (NULL);
		}
		arr = ft_strdup(&mass[l + 1]);
		free(mass);
		mass = ft_strdup(arr);
		free(arr);
	}
	return (mass);
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
		temp->content = /*(!temp->content) ? ft_strdup(buffer) : */ft_strjoin(temp->content, buffer);
		*line = get_line(&(temp->content));
		if (ft_strchr(temp->content, '\n'))
			return ((temp->content = ft_del_mem(temp->content)) ? 1 : 1);
//		free(*line);
//		printf("line: %s\n", *line);  //!!!!!
//		printf("temp: %s\n", temp->content);  //!!!!!
//		printf("STATIC: %s\n", text->content);  //!!!!!
//		if (ft_strchr(buffer, '\n'))
//			break;
	}
//	if (temp->index < BUFF_SIZE && !ft_strlen(temp->content))
//		return (0);
//	if (!(*line = get_line(&(temp->content))))
//		return (-1);
	if (temp->content)
		*line = get_line(&(temp->content));
	else
		return (0);
	if (ft_strchr(temp->content, '\n'))
		return ((temp->content = ft_del_mem(temp->content)) ? 1 : 1);
//	printf("STATIC: %s\n", text->content);  //!!!!!
	// нужно исправить утечки памяти
	free(buffer);
	return (1);
}

/*char	*ft_line(char *mass)
{
	size_t	start;
	char	*result;

	if (!ft_strchr(mass, '\n'))
		result = ft_strdup(mass);
	else
	{
		start = ft_strlen(mass) - ft_strlen(ft_strchr(mass, '\n'));
		result = ft_strsub(mass, 0, start);
	}
	return (result);
}

char	*ft_del_mem(char *mass)
{
	size_t	l;
	char	*arr;

	l = 0;
	if (ft_strchr(mass, '\n'))
	{
		while (mass[l] != '\n' && mass[l])
			l++;
		if (!mass[l + 1])
		{
			free(mass);
			return (NULL);
		}
		arr = ft_strdup(&mass[l + 1]);
		free(mass);
		mass = ft_strdup(arr);
		free(arr);
	}
	return (mass);
}

char	*ft_strjoin_my(char const *s1, char const *s2)
{
	int		i;
	int		l;
	char	*qw;

	i = 0;
	l = 0;
	if ((char*)s1 == NULL || (char*)s2 == NULL)
		return (NULL);
	qw = (char*)malloc(sizeof(qw) * (ft_strlen((char*)s1)\
	+ ft_strlen((char*)s2)));
	if (!qw)
		return (NULL);
	while (((char*)s1)[i])
	{
		qw[i] = s1[i];
		i++;
	}
	while (((char*)s2)[l])
		qw[i++] = s2[l++];
	free((char*)s1);
	qw[i] = '\0';
	return (qw);
}

t_string	*ft_list_part(t_string **new, int fd)
{
	t_string	*two;

	if (*new == NULL)
	{
		*new = ft_lststringnew(NULL, 0);
		(*new)->filedesc = fd;
		return (*new);
	}
	if ((*new)->filedesc != fd)
	{
		two = *new;
		while (two->next)
		{
			if (two->filedesc == fd)
				return (two);
			two = two->next;
		}
		if (two->filedesc == fd)
			return (two);
		two->next = ft_lststringnew(NULL, 0);
		two->next->filedesc = fd;
		return (two->next);
	}
	return (*new);
}

int		get_next_line(int fd, char **line)
{
	static	t_string	*new = NULL;
	char			buff[BUFF_SIZE + 1];
	t_string			*save;

	if (line == NULL || fd < 0)
		return (-1);
	save = ft_list_part(&new, fd);
	while ((save->index = read(fd, buff, BUFF_SIZE)))
	{
		if (save->index == -1)
			return (-1);
		buff[save->index] = '\0';
		save->content = (!save->content) ? ft_strdup(buff) : ft_strjoin(save->content, buff);
		*line = ft_line(save->content);
		if (ft_strchr(save->content, '\n'))
			return ((save->content = ft_del_mem(save->content)) ? 1 : 1);
		free(*line);
	}
	if (save->content)
		*line = ft_line(save->content);
	else
		return (0);
	if (ft_strchr(save->content, '\n'))
		return ((save->content = ft_del_mem(save->content)) ? 1 : 1);
	return (1);
}*/
