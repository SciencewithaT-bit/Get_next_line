/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saaboudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:14:43 by saaboudo          #+#    #+#             */
/*   Updated: 2023/12/20 18:51:40 by saaboudo         ###   ########.fr       */
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
	result = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (size != 0 && size * nmemb / size != nmemb)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab)
	{
		ft_memset(tab, 0, nmemb * size);
		return (tab);
	}
	return (NULL);
}


void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*tab;

	tab = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		tab[i] = c;
		i++;
	}
	return (tab);
}
