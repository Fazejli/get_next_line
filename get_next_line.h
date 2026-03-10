/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:08:31 by fazejli           #+#    #+#             */
/*   Updated: 2025/09/22 13:49:55 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(const int fd);
char	*get_the_line(char *buffer);
char	*get_the_next(char *buffer);
int		ft_strlen(char *str);
int		check_newline(char *str);
void	ft_free(char *line, char *buffer);
void	ft_bzero(void *s, int n);
char	*ft_join_free(char *buffer, char *str);

#endif
