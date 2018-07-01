/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:32:35 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/01 21:09:35 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*search_newline(char *newline, char *static_string)
{
	int		start;
	int		stop;

	start = 0;
	//need check the errors
	if (static_string)
	{
		while (static_string[start])
			start++;
	}
	printf("START: %d\n", start);
	stop = start + 1;
	while (newline[stop] != '\n' && newline[stop] != '\0')
		stop++;
	printf("STOP: %d\n", stop);
	if (newline[stop] == '\0')
		return (NULL);
	newline = ft_strsub(newline, start, stop);
	return (newline);
}

int		get_next_line(const int fd, char **line)
{
	static char	*static_string = NULL;
	char		*buffer;
	char		*temp;
	int			bytes;
	
	temp = ft_strnew(1);
	if (!(buffer = ft_strnew(BUF_SIZE + 1)))
		return (-1);
	while ((bytes = read(fd, buffer, BUF_SIZE)))
	{
		buffer[bytes] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	printf("----------------\n");
	printf("TEXT: %s\n", temp);
	printf("----------------\n");
	if (!(*line = search_newline(temp, static_string)))
		return (-1);
	static_string = ft_strnew(1);
	static_string = ft_strjoin(static_string, *line);
	printf("STATIC: %s\n", static_string);
	return (1);
}
