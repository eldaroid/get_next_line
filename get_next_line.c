/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:04 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/05 18:17:41 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_check(char *last, char **line)
{
	char		*pointer_find;

	pointer_find = NULL;
	if (last)
	{
		if ((pointer_find = ft_strchr(last, '\n')))
		{
			*pointer_find++ = '\0';
			*line = ft_strdup(last);
			ft_strcpy(last, pointer_find);
		}
		else
		{
			*line = ft_strdup(last);
			ft_strclr(last);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (pointer_find);
}

char	*ft_strjoinf(char *s1, char *s2)
{
	char			*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*last;
	char		buf[BUFF_SIZE + 1];
	int			how_much;
	char		*pointer_f;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	pointer_f = to_check(last, line);
	while ((!pointer_f) && (how_much = read(fd, buf, BUFF_SIZE)))
	{
		buf[how_much] = '\0';
		if ((pointer_f = ft_strchr(buf, '\n')))
		{
			*pointer_f = '\0';
			pointer_f++;
			last = ft_strdup(pointer_f);
		}
		*line = ft_strjoinf(*line, buf);
	}
	if (how_much == 0 && !(ft_strlen(*line)))
		return (0);
	return (1);
}
