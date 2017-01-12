/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprovorn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:30:49 by dprovorn          #+#    #+#             */
/*   Updated: 2017/01/10 16:32:31 by dprovorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"
#define READ_MAX 5

int		my_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*my_realloc(char *old, int size)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = malloc(sizeof(*new) * (my_len(old) + size))) == NULL)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	free(old);
	return (new);
}

char	*get_next_line(const int fd)
{
	static int	last = 1;
	static int	rd = 0;
	static int	i = 0;
	static char	*r = NULL;
	static char	buf[READ_MAX];

	if (buf[my_len(buf) - rd] == '\0')
	{
		if ((rd = read(fd, buf, READ_MAX)) <= 0)
			return (r = (last-- && buf[my_len(buf) - rd - 1] != 10) ? r : NULL);
		buf[rd] = '\0';
	}
	if ((r = (i == 0) ? malloc(sizeof(*r) * READ_MAX + 1) :
				my_realloc(r, sizeof(*r) * READ_MAX + 1)) == NULL)
		return (NULL);
	while (buf[my_len(buf) - rd] && buf[my_len(buf) - rd] != '\n')
		r[i++] = buf[my_len(buf) - rd--];
	r[i] = '\0';
	if (buf[my_len(buf) - rd] == '\n')
	{
		i = 0;
		rd--;
		return (r);
	}
	return (get_next_line(fd));
}
