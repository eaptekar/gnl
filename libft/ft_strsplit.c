/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaptekar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:27:34 by eaptekar          #+#    #+#             */
/*   Updated: 2017/11/27 16:28:07 by eaptekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *s, char c)
{
	size_t	i;
	int		words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		if (!s[i])
			break ;
		while ((s[i] != c) && s[i])
			i++;
		words++;
	}
	return (words);
}

static char	**dosplit(const char *s, char c, char **arr, size_t i)
{
	size_t	j;
	size_t	in;

	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		in = i;
		while (s[i] != c && s[i])
			i++;
		arr[j] = ft_strsub(s, in, i - in);
		if (!arr[j])
		{
			while (j-- > 0)
				free(arr[j]);
			free(arr);
			return (NULL);
		}
		j++;
	}
	return (arr);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**arr;
	int		words;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	words = wordcount(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	arr = dosplit(s, c, arr, i);
	if (!arr)
		return (NULL);
	arr[words] = NULL;
	return (arr);
}
