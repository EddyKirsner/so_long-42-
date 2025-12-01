/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:05:53 by ekirsner          #+#    #+#             */
/*   Updated: 2024/06/26 13:47:29 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, int sd, char **sdd, char *buffer)
{
	size_t	i;
	char	*temp;

	if (!sd)
	{
		i = 0;
		while (s && s[i])
			i++;
		return (i);
	}
	if (!(*sdd))
			*sdd = ft_strdup("");
	temp = *sdd;
	*sdd = ft_strjoin(*sdd, buffer);
	free (temp);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	superc;

	superc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == superc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == superc)
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s, 0, NULL, NULL);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1, 0, NULL, NULL);
	str = malloc(i + ft_strlen(s2, 0, NULL, NULL) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*str;

	i = 0;
	len_s = ft_strlen((char *)s, 0, NULL, NULL);
	if (start >= len_s)
	{
		return (ft_strdup(""));
	}
	if (len > len_s - start)
		len = len_s - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
