/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:04 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/01 17:02:30 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)// 1 0 -1
{
	static char	*last;
	char		buf[BUFF_SIZE + 1];
	int			how_much;
	char		*pointer_find;
	int			flag;

	flag = 1;
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
			// printf("%d\n", 1);
			free(last);
		}
	}
	else
		*line = ft_strnew(1);
	while((flag != 0) &&(how_much = read(fd, buf, BUFF_SIZE))) ///director,\0 film 
	{
		buf[how_much] = '\0';
		if ((pointer_find = ft_strchr(buf, '\n')))
		{
			*pointer_find++ = '\0';
			flag = 0;
			last = ft_strdup(pointer_find);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s\n", line);
		get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}

// int            main(int argc, char **argv)
// {
//      int fd;
//      char *line;
//      //int count = 1;
//       if (argc <= 2)
//            {
//             fd = open(argv[1], O_RDONLY);
//             //while(count >= 1)
//             //{
//                 gnl(fd, &line);
//                 printf("%s ", "\x1B[1;31;43mGNL\x1B[0;37;40m");
//                 printf("%s", line);
//             //    count--;
//             //}
//            }
//        if (argc > 2)
//              write(2, "Too many arguments.\n", 20);
//         return (0);
