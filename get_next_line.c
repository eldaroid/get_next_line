/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:47:04 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/01 13:39:20 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

#include <stdio.h>
int	get_next_line(const int fd, char **line)// 1 0 -1
{
	char	line2[BUFF_SIZE + 1];
	int		i;
	
	read(fd, line2, BUFF_SIZE);
	line2[BUFF_SIZE] = '\0';
	printf("%s\n", line2);
	printf("%d\n", 8);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line1;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	get_next_line(fd, &line1);
	printf("%d", 4);
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
