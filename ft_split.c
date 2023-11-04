/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolkman <mvolkman@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 02:07:25 by mvolkman          #+#    #+#             */
/*   Updated: 2023/11/04 11:28:26 by mvolkman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c_split)
{
	int	i;
	int	is_word;
	int	count;

	i = 0;
	is_word = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c_split)
		{
			if (is_word)
				is_word = 0;
		}
		else
		{
			if (!is_word)
			{
				is_word = 1;
				count++;
			}
		}
		i++;
	}
	return (count);
}

static char	**allocate_memory(int num_of_words)
{
	char	**answer;

	answer = (char **)malloc(sizeof(char *) * (num_of_words + 1));
	return (answer);
}

static int	pop_answer(char const *s, char c, char **answer, int num_of_words)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	while (i < num_of_words)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		answer[i] = ft_substr(s, start, end - start);
		if (!answer[i])
			return (0);
		i++;
		start = end;
	}
	answer[i] = NULL;
	return (1);
}

static void	free_mem(char **answer)
{
	int	i;

	i = 0;
	while (answer[i])
		free(answer[i++]);
	free(answer);
}

char	**ft_split(char const *s, char c)
{
	int		num_of_words;
	char	**answer;

	num_of_words = ft_count_words(s, c);
	answer = allocate_memory(num_of_words);
	if (!answer)
		return (NULL);
	if (!pop_answer(s, c, answer, num_of_words))
	{
		free_mem(answer);
		return (NULL);
	}
	return (answer);
}
