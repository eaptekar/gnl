/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:48:59 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/06 14:18:08 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	int i = 0;
	int ret;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (i < 6)
	{
		ret = get_next_line(fd, &line);
		ft_putendl(line);
		free(line);
		i++;
	}
	close (fd);
	return (0);
}
