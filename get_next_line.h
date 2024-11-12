/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:48:18 by mcastrat          #+#    #+#             */
/*   Updated: 2024/11/12 14:38:20 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*readf(int fd, char *res);
char	*getlinee(char *buff);
char	*getnext(char *buff);
char	*ft_free(char *oldbuff, char *newbuff);
int		ft_strlen(char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *oldbuff, char *newbuff);
char	*ft_strchr(char *buff, int c);

#endif