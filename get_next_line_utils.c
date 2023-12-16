/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaboudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:14:43 by saaboudo          #+#    #+#             */
/*   Updated: 2023/12/16 15:52:46 by saaboudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*tab;
	int				i;

	i = 0;
	tab = (unsigned char *) s;
	while (tab[i] != '\0')
	{
		if (tab[i] == (char) c)
		{
			return ((char *)&tab[i]);
		}
		i++;
	}
	if (tab[i] == c)
		return ((char *)&tab[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *extract_line(char *basin_buffer)
{
	size_t i;

	i = 0; 
	while (basin_buffer[i] != '\n')
	{
		i++; 
	}
}
