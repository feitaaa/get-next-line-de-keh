/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:51:45 by mcastrat          #+#    #+#             */
/*   Updated: 2024/12/02 07:11:00 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	inibuff(char **line)
{
	if (!(*line))
	{
		*line = malloc(1);
		if (!(*line))
			return ;
		(*line)[0] = '\0';
	}
}

void	getnext(char **buff)
{
	size_t	i;
	size_t	len;
	char	*newbuff;

	len = 0;
	i = 0;
	while ((*buff)[len] && (*buff)[len] != '\n')
		len++;
	if ((*buff)[len] == '\n')
		len++;
	if ((*buff)[len] == '\0')
	{
		free(*buff);
		*buff = NULL;
		return ;
	}
	newbuff = malloc((ft_strlen(*buff) - len) + 1);
	if (!newbuff)
		return ;
	while ((*buff)[len])
		newbuff[i++] = (*buff)[len++];
	newbuff[i] = '\0';
	free(*buff);
	*buff = newbuff;
}

void	getliine(char *buff, char **line)
{
	int	i;
	int	len;

	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	*line = malloc(sizeof(char) * (len + 1));
	if (!(*line))
		return ;
	i = 0;
	while (i < len)
	{
		(*line)[i] = buff[i];
		i++;
	}
	(*line)[i] = '\0';
}

void	readbuff(int fd, char **line)
{
	int		nbyte;
	char	*tempbuff;
	char	*newline;

	nbyte = 1;
	inibuff(line);
	while (!(ft_strchr(*line, '\n')) && nbyte > 0)
	{
		tempbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tempbuff)
			return ;
		nbyte = read(fd, tempbuff, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(tempbuff);
			free(*line);
			*line = NULL;
			return ;
		}
		tempbuff[nbyte] = '\0';
		newline = ft_strjoin(*line, tempbuff);
		free(*line);
		*line = newline;
		free(tempbuff);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buff;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbuff(fd, &buff);
	if (!buff || buff[0] == '\0')
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	getliine(buff, &line);
	getnext(&buff);
	return (line);
}
