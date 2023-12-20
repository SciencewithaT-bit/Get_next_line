/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaboudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:03:59 by saaboudo          #+#    #+#             */
/*   Updated: 2023/12/20 19:27:19 by saaboudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

static char *append_str(char *pool_buffer, char *read_buffer);

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
		byte_read = read(fd, scoop_buffer,BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(scoop_buffer);
			return (NULL);
		}
		scoop_buffer[byte_read] = '\0';
		pool_buffer = append_str(pool_buffer, scoop_buffer);
		if (ft_strchr(pool_buffer, '\n'))
			break ;

	}
	free(scoop_buffer);
	return (pool_buffer);
}

static char *append_str(char *pool_buffer,char *read_buffer)
{
	char *tmp; 

	tmp = ft_strjoin(pool_buffer, read_buffer);
	free(pool_buffer);
	return (tmp);
}

char *extract_line (char *buffer)
{
	char *new_line_pos;
	size_t line_length;
	char *line;

	if(buffer == NULL || *buffer == '\0')
	{
		return (NULL);
	}


	// buffer have is value 0 or NULL, so the malloc is behaving weirdly need to find a way to only malloc when its valid
	new_line_pos = ft_strchr(buffer, '\n');
	line_length = new_line_pos - buffer + 1;
	line =(char*) malloc((line_length + 1) * sizeof(char));
	strncpy(line, buffer, line_length);
	line[line_length] = '\0';

	return (line);
}


char *obtainremaining(char *buffer)
{
	if (buffer == NULL || *buffer == '\0')
	{
		return (NULL);
	}

	char *new_pos = ft_strchr(buffer, '\n');

	if (new_pos == NULL)
	{
		 return (NULL);
	}	
	size_t remaining_length = ft_strlen(new_pos + 1);

	memmove(buffer, new_pos + 1, remaining_length + 1);

	return (buffer);
}



char	*get_next_line(int fd)
{
	static char *basin_buffer = NULL;
	char *line;

	line = NULL;
	if(fd < 0 || read (fd,NULL,0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof (char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_fd(basin_buffer, fd);
	if (!basin_buffer || basin_buffer[0] == '\0')
	{
		free(line);
		free(basin_buffer);
		return (NULL);
	}
	line = extract_line(basin_buffer);
	basin_buffer = obtainremaining(basin_buffer);
	return (line);
}



int main(void)
{

	
	int fd; 

	char *line;
	 int count;

	count = 0;
	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("%s", line);
		free (line);
	}
	close(fd);
	 return(0);
}

/*
int    main(void)
{
    int    fd;
    int    i;
    char *str;

    i = 0;
    fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
		while (i < 4)
    {
        str =  get_next_line(fd);
        printf("%s", str);
        //free(str);
        i++;
    }
    close (fd);
}
*/
