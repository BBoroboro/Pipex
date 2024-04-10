/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamoulin <mamoulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:43:50 by mamoulin          #+#    #+#             */
/*   Updated: 2024/03/26 15:19:10 by mamoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) != c)
		{
			count++;
			while (*(str + i) && *(str + i) != c)
				i++;
		}
		else if (*(str + i) == c)
			i++;
	}
	return (count);
}

static size_t	word_len(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	return (i);
}

static void	free_tab(size_t i, char **tab)
{
	while (i > 0)
	{
		i--;
		free(*(tab + i));
	}
	free(tab);
}

static char	**split(char const *s, char c, char **tab, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(tab + i) = ft_substr(s, j, word_len(&*(s + j), c));
		if (!*(tab + i))
		{
			free_tab(i, tab);
			return (NULL);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(tab + i) = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strs)
		return (NULL);
	strs = split(s, c, strs, words);
	return (strs);
}

// int	ft_isspace(char c)
// {
// 	return (c == ' ' || c == '\t');
// }

// int	ft_countword(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		while (ft_isspace(str[i]))
// 			i++;
// 		if (!ft_isspace(str[i]))
// 			count++;
// 		while (!ft_isspace(str[i]) && str[i])
// 			i++;
// 	}
// 	return (count);
// }

// char	*ft_malloc_word(char *str)
// {
// 	int		i;
// 	char	*word;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	word = malloc(sizeof(char) * (i + 1));
// 	if (!word)
// 		return (NULL);
// 	i = 0;
// 	while (!ft_isspace(str[i]) && str[i])
// 	{
// 		word[i] = str[i];
// 		i++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char *str)
// {
// 	int		i;
// 	char	**strs;

// 	i = 0;
// 	strs = malloc(sizeof(char *) * (ft_countword(str) + 1));
// 	if (!strs)
// 		return (NULL);
// 	while (*str)
// 	{
// 		while (ft_isspace(*str) && *str)
// 			str++;
// 		if (!ft_isspace(*str) && *str)
// 		{
// 			strs[i] = ft_malloc_word(str);
// 			if (strs[i] == NULL)
// 			{
// 				ft_free_tab(strs);
// 				return (NULL);
// 			}
// 			i++;
// 		}
// 		while (!ft_isspace(*str) && *str)
// 			str++;
// 	}
// 	return (strs[i] = NULL, strs);
// }

/*
int	main(void)
{
	char	**strs;
	char	*str;
	char	c;

	c = ' ';
	str = " tripoulle 42 ";

	strs = ft_split(str, c);

	printf("%s\n", strs[2]);
	return (0);
}*/
