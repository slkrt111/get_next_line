/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:31:35 by slebik            #+#    #+#             */
/*   Updated: 2024/11/29 11:59:03 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		is_nl(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	fline(char *line);
int		read_to_buffer(int fd, char *buffer);
char	*update_line(char *line, char *buffer);

#endif
