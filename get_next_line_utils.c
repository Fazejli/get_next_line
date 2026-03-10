/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:25:03 by fazejli           #+#    #+#             */
/*   Updated: 2025/07/20 11:51:55 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join_free(char *buffer, char *str)
{
	char	*res;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(str) + 1));
	if (!res)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer && buffer[i])
	{
		res[i] = buffer[i];
		i++;
	}
	j = 0;
	while (str[j])
		res[i++] = str[j++];
	res[i] = '\0';
	free(buffer);
	return (res);
}
