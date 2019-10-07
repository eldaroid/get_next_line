/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:04 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/07 23:21:15 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_check(char **last, char **line)
{
	char		*pointer_find;

	pointer_find = NULL;
	if (*last)
	{
		if ((pointer_find = ft_strchr(*last, '\n')))
		{
			*pointer_find = '\0';
			pointer_find++;
			*line = ft_strdup(*last);
			ft_strcpy(*last, pointer_find);
		}
		else
		{
			*line = ft_strdup(*last);
			ft_strclr(*last);
		}
	}
	else
		*line = ft_strnew(0);
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
	pointer_f = to_check(&last, line);
	if (pointer_f)
		if (!(*pointer_f))
			return (1);
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
	return (how_much || ft_strlen(last) || ft_strlen(*line) ? 1 : 0);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	// int i = 1;
	int rd;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while ((rd = get_next_line(fd, &line)) > 0)
	{
		// printf("заходим в цикл %d\n", i);
		printf("%d ", rd);
		printf("%s\n", line);
		// i++;
		free(line);
	}
	printf("%d ", rd);
	printf("%s\n", line);
	close(fd);
	// get_next_line(fd, &line);
	// 	// {
	// 		printf("заходим в цикл %d\n", i);
	// 		printf("%s\n", line);
	return(0);
}