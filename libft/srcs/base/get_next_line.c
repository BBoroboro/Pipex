/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:31:57 by mamoulin          #+#    #+#             */
/*   Updated: 2023/12/13 15:38:04 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_stash(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		rd;

	buffer = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd <= 0 && !stash)
		{
			(free(stash), free(buffer));
			return (NULL);
		}
		buffer[rd] = '\0';
		temp = ft_strjoin(stash, buffer);
		(free(stash), stash = temp);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			i;
	static char	*stash;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_get_stash(fd, stash);
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	line[i] = '\0';
	stash = ft_clean_stash(stash);
	return (line);
}

// int     main(void)
// {
//         int     file;
//         char    *line;
//         int     i;

//         file = open("test.txt", O_RDONLY);
//         if (file == -1)
//         {
//                 printf("Error opening file");
//                 return (1);
//         }
//         i = 0;
//         while (i < 4)
//         {
//                 line = get_next_line(file);
//                 printf("%s", line);
//                 free(line);
//                 i++;
//         }
//         close(file);
// 		return (0);
// }
