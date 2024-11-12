/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:09:28 by mcastrat          #+#    #+#             */
/*   Updated: 2024/11/11 16:16:11 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < (count * size))
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
char *ft_strjoin(char *oldbuff, char *newbuff)
{
	int i;
	int j;
	char *ct;
	int tot;
	
	tot = ft_strlen(oldbuff) + ft_strlen(newbuff) + 1;
	ct = malloc(sizeof(char) * tot);
	if (!ct)
		return (NULL);
	i = 0;
	j = 0;
	while (oldbuff[i])
	{
		ct[i] = oldbuff[i];
		i++;
	}
	while (newbuff[j])
	{
		ct[j + i] = newbuff[j];
		j++;
	}
	ct[j + i] = '\0';
	return (ct);
}
char	*ft_strchr(char *buff, int c)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == (char)c)
			return ((char *)&buff[i]);
		i++;
	}
	if (buff[i] == (char)c)
		return ((char *)&buff[i]);
	return (NULL);
}