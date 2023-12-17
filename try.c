/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaboudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:03:59 by saaboudo          #+#    #+#             */
/*   Updated: 2023/12/17 17:38:45 by saaboudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *append(char *pool_buffer, char *read_buffer);


static char *read_from_fd(char *pool_buffer, int fd)
{
	int byte_read; 
	char *scoop_buffer; 

	scoop_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (scoop_buffer == NULL)
		return (NULL);
	byte_read = 1;
	
	while (byte_read > 0)
	{
		byte_read = read(fd, scoop_buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(scoop_buffer);
			return (NULL);
		}
		scoop_buffer[byte_read] = '\0';
		pool_buffer = append(pool_buffer, scoop_buffer);
		if (ft_strchr(pool_buffer, '\n'))
			break ;

		
	}
	free(scoop_buffer);
	return (pool_buffer);

}


static char *append(char *pool_buffer, char *read_buffer)
{
	char *temp;
	
	temp = ft_strjoin(pool_buffer, read_buffer);
	free(pool_buffer);
	return (temp);
}
