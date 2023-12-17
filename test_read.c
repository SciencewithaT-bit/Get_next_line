/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaboudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:33:07 by saaboudo          #+#    #+#             */
/*   Updated: 2023/12/17 20:37:49 by saaboudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>

/* size_t read(int fd, void *buf, size_t count) prototype of read() func */
char *try_get_next_line(int fd);
char *append_read(char *basin_buffer, char *read_buffer);

/* Function to read data from the file append it to partial content. */
static char	*read_from_file(char *basin_buffer, int fd)
{
	int byte_read;
	 char *char_buffer;
	//static int count = 1;

	//printf("calloc#[%d]---", count++);
	char_buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if(char_buffer == NULL)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd,char_buffer, BUFFER_SIZE);
		if(byte_read == -1)
		{
			free(char_buffer);
			return (NULL);
		}
		char_buffer[byte_read] = '\0';
		basin_buffer = append_read(basin_buffer, char_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	free(char_buffer);
	return (basin_buffer);
}

 /* the get_next_line function to get the next line from the file descriptor */

char	*try_get_next_line(int fd)
{
	static char *basin_buffer;
	char *line;

	if(fd < 0 || read (fd,NULL,0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!basin_buffer)
		basin_buffer = calloc(1, sizeof (char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (free(basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtainremaining(basin_buffer); // strdup, strchr de basin_buffer
	return (line);
}


/* append function to help read data to the partial content (line) the explorer (get_next_line) gracefully adds a  scoop of water (read buffer) to get the current cup (line) and returns the updated line for further examination. */

char *append_read(char *basin_buffer, char *read_buffer)
{
 	char *temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);

}


char	*extract_ine()

int main(void)
{

	int fd;
	/*
	char buff[100];

	fd = open("example.txt", O_RDONLY);
	read(fd, buff, 57);

	printf("\n\n%s\n\n", buff);
	return (0);
	*/

	//int byte_read;
	//char *char_buffer;

	// calloc char_buffer with 3 + 1
	// good practice is to return NULL if the if the calloc allocation failed  (if char_buffer == null return null)
	//byte_read = read(fd, char_buffer, 3);
	char *line;
	 int count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	while (1)
	{
		line = try_get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, line);
		free (line);
		line = NULL;
	}
	close(fd);
	// return(0);
}
