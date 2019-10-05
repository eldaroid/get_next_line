/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:52:26 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/05 14:35:19 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include <stdio.h>
# include <fcntl.h> // open
# include <unistd.h> //read write
# include "libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
