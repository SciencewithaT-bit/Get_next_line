/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaboudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:33:07 by saaboudo          #+#    #+#             */
/*   Updated: 2023/12/15 21:09:06 by saaboudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/* size_t read(int fd, void *buf, size_t count) prototype of read() func */
char *try_get_next_line(int fd);
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
	char *next_line; 
	 int count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	while (1)
	{
		next_line = try_get_next_line(fd);
		if (next_line == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free (next_line);
		next_line = NULL;
	}
	close(fd);
	// return(0);	
}

static char	*read_from_file(int fd)
{
	int byte_read;
	 char *char_buffer;
	static int count = 1;

	printf("calloc#[%d]---", count++);
	char_buffer = calloc(3 + 1, sizeof(char));
	if(char_buffer == NULL)
		return (NULL);
	byte_read = read(fd, char_buffer,3);
	if(byte_read <= 0)
	{
		free(char_buffer);
		return (NULL);
	}
	return (char_buffer);
}
// 
char	*try_get_next_line(int fd)
{
	char	*basin_buffer;

	basin_buffer = read_from_file(fd);
	return (basin_buffer);
}


size_t ft_strlen(char *str)
{

}
