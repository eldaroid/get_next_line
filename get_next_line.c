/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldaroid <eldaroid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:04 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/05 13:53:55 by eldaroid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)// 1 0 -1
{
	static char	*last;
	char		buf[BUFF_SIZE + 1];
	int			how_much;
	char		*pointer_find;
	char		*pointer_del;

	pointer_find = NULL;
	if (last)
	{
		//  printf("%s\n", last);
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
			//ft_strdel(&last);
		}
	}
	else
		*line = ft_strnew(1);
		
	while((!pointer_find) &&(how_much = read(fd, buf, BUFF_SIZE))) // pointer_find в строчку 41 становится не нулевым, в случае если он стал
 	{
		// ft_strdel(&last);
		// printf("%d", how_much);
		buf[how_much] = '\0';
		if ((pointer_find = ft_strchr(buf, '\n')))
		{
			// pointer_find--;
			// printf("%c\n", *pointer_find);
			// pointer_find++;
			*pointer_find = '\0';
			pointer_find++;
			last = ft_strdup(pointer_find);
			//  printf("AAAA%s\n\n", last);
			// printf("%d\n", 5);
		}
		// printf("%d\n", 54);
		// pointer_del = *line;
		*line = ft_strjoin(*line, buf);
		// free(pointer_del);
	}
	return ((how_much || ft_strlen(last) || ft_strlen(*line)) ? 1 : 0);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int i = 1;
	
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			printf("заходим в цикл %d\n", i);
			printf("%s\n", line);
			// ft_putendl(line);
			i++;
			free(line);
		}
	}
	// get_next_line(fd, &line);
	// printf("заходим в цикл %d\n", i);
	// printf("%s\n", line);
	// i++; // 2
	// get_next_line(fd, &line);
	// printf("заходим в цикл %d\n", i);
	// printf("%s\n", line);
	// i++; // 3
	// get_next_line(fd, &line);
	// printf("заходим в цикл %d\n", i);
	// printf("%s\n", line);
	// i++; // 4
	// get_next_line(fd, &line);
	// printf("заходим в цикл %d\n", i);
	// printf("%s\n", line);
	// i++;
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
