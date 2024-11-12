/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastrat <mcastrat@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:20:21 by mcastrat          #+#    #+#             */
/*   Updated: 2024/11/12 14:44:50 by mcastrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *str;
	int fd;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);ls

	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return 0;
}