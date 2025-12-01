/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekirsner <ekirsner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:58:51 by ekirsner          #+#    #+#             */
/*   Updated: 2024/10/28 12:10:17 by ekirsner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *tempfull, int i)
{
	char	*line;
	int		j;

	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = tempfull[j];
		j++;
	}
	if (tempfull[i] == '\n')
		line[i] = '\n';
	else
	{
		line[i] = '\0';
		return (line);
	}
	line[i + 1] = '\0';
	return (line);
}

static int	update_full(char **full, int i)
{
	char	*tempfull;

	tempfull = *full;
	*full = ft_substr(tempfull, i + 1, ft_strlen(tempfull, 0, NULL, NULL) - i);
	if (!*full)
	{
		*full = tempfull;
		return (0);
	}
	free(tempfull);
	return (1);
}

static char	*read_line(char **full)
{
	int		i;
	char	*line;

	i = 0;
	if ((*full)[0] == '\0')
		return (NULL);
	while ((*full)[i] && (*full)[i] != '\n')
		i++;
	line = extract_line(*full, i);
	if (!line)
		return (NULL);
	if (!update_full(full, i))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*superdispenser(int fd, char *buffer, char **full)
{
	int		isread;

	isread = 1;
	while (isread != 0)
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (isread == 0)
			break ;
		buffer[isread] = '\0';
		ft_strlen(0, 1, full, buffer);
		if (!*full)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (*full);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*full = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!superdispenser(fd, buffer, &full))
	{
		free(full);
		full = (NULL);
		return (NULL);
	}
	line = read_line(&full);
	if (full && full[0] == '\0')
	{
		free(full);
		full = NULL;
	}
	return (line);
}

// int main()
// {
// 	char *path = "test.txt";
// 	int fd = open(path, O_RDONLY);
// 	if (fd == -1) {
// 		perror("Erreur d'ouverture du fichier");
// 		return 1;
// 	}
// 	char *str;
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	// Uncomment these lines if you want to read more lines
// 	/*  str = get_next_line(fd);
// 	 printf("%s", str);
// 	 free(str); */
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	// str = get_next_line(fd);
// 	// printf("%s", str);
// 	// free(str);
// 	close(fd);
// 	return 0;
// }
