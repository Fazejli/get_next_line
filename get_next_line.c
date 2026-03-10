/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:25:18 by fazejli           #+#    #+#             */
/*   Updated: 2025/07/20 11:51:48 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

void	ft_free(char *line, char *buffer)
{
	free(line);
	ft_bzero(buffer, ft_strlen(buffer));
}

char	*get_the_next(char *buffer)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || !buffer[i + 1])
	{
		free(buffer);
		return (NULL);
	}
	next = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!next)
		return (NULL);
	j = 0;
	while (buffer[++i])
		next[j++] = buffer[i];
	next[j] = '\0';
	free(buffer);
	return (next);
}

char	*get_the_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (check_newline(buffer))
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(const int fd)
{
	static char	*buffer;
	char		*line;
	int			temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	temp = 1;
	while (temp > 0 && !check_newline(buffer))
	{
		temp = read(fd, line, BUFFER_SIZE);
		if (temp < 0)
		{
			ft_free(line, buffer);
			return (NULL);
		}
		line[temp] = '\0';
		buffer = ft_join_free(buffer, line);
	}
	free(line);
	line = get_the_line(buffer);
	buffer = get_the_next(buffer);
	return (line);
}
/*int	main(void)
{
	int		fd;
	char	*line;
	int		n;

	n = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	if (line)
		printf("%s", line);
	free(line);
	close(fd);
	*/
