/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <eaptekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 17:30:54 by eaptekar          #+#    #+#             */
/*   Updated: 2018/07/06 19:37:58 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 1

typedef struct	s_string
{
	char			*content;
	int				index;
	int				filedesc;
	struct s_string	*next;
}				t_string;

int				get_next_line(const int fd, char **line);

#endif
