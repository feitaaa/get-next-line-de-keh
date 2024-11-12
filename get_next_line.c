/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:51:02 by mcastrat          #+#    #+#             */
/*   Updated: 2024/11/12 14:24:29 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *oldbuff, char *newbuff)
{
	char	*temp;

	temp = ft_strjoin(oldbuff, newbuff);
	free(oldbuff);
	return (temp);
}

char	*getnext(char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i])
		line[j++] = buff[i++];
	free(buff);
	return (line);
}

char	*getlinee(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i] || buff[0] == '\0')
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	return (line);
}
char	*readf(int fd, char *res)
{
	char	*buff;
	int		nbyte;

	if (!res)
		res = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
    	return (NULL);
	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, buff, BUFFER_SIZE);
		if (nbyte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbyte] = '\0';
		res = ft_free(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = readf(fd, buff);
	if (!buff)
		return (NULL);
	line = getlinee(buff);
	buff = getnext(buff);
	return (line);
}