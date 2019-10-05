/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:04 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/05 16:54:45 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	to_check(char *last, char **line)
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
			free(last);
		}
		else
		{
			*line = ft_strdup(last);
			ft_strclr(last);
			free(last);
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
	char		*pointer_del;
	char		*pointer_f;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	pointer_f = to_check(last, line);
	if (last)
	{
		if ((pointer_f = ft_strchr(last, '\n')))
		{
			*pointer_f++ = '\0';
			*line = ft_strdup(last);
			ft_strcpy(last, pointer_f);
			free(last);
		}
		else
		{
			*line = ft_strdup(last);
			ft_strclr(last);
			free(last);
		}
	}
	else
		*line = ft_strnew(1);
		
	while((!pointer_f) &&(how_much = read(fd, buf, BUFF_SIZE)))
 	{
		buf[how_much] = '\0';
		if ((pointer_f = ft_strchr(buf, '\n')))
		{
			*pointer_f = '\0';
			pointer_f++;
			last = ft_strdup(pointer_f);
		}
		// pointer_del = *line;
		*line = ft_strjoinf(*line, buf);
		// free(pointer_del);
	}
	return ((how_much || ft_strlen(last) || ft_strlen(*line)) ? 1 : 0);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int i = 1;
	
	// if (argc == 2)
	// {
		fd = open(argv[1], O_RDONLY);
	// 	while (get_next_line(fd, &line))
	// 	{
	// 		printf("заходим в цикл %d\n", i);
	// 		printf("%s\n", line);
	// 		i++;
	// 		free(line);
	// 	}
	// }
	get_next_line(fd, &line);
		// {
			printf("заходим в цикл %d\n", i);
			printf("%s\n", line);
	return(0);
}
