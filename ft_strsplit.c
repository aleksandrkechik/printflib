/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hturkatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:19:33 by hturkatr          #+#    #+#             */
/*   Updated: 2019/09/20 14:23:47 by hturkatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_char(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		c_words(char const *s, char c)
{
	int		started;
	int		words;
	int		i;

	i = 0;
	words = 0;
	started = 0;
	while (s[i])
	{
		if ((s[i] != c && started != 1 && s[i] != 0))
		{
			words++;
			started = 1;
		}
		if ((s[i] == c || s[i] == '\0') && started == 1)
			started = 0;
		i++;
	}
	return (words);
}

static int		fill_arr(char **ret, const char *s, char c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	l;

	i = 0;
	k = 0;
	l = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = len_char(&(s[i]), c);
		ret[l] = ft_strsub(s, i, k);
		if (!ret[l])
		{
			while (l-- > 0)
			{
				free(ret[l]);
			}
			return (0);
		}
		l++;
		i += k;
	}
	return (1);
}

char			**ft_strsplit(const char *s, char c)
{
	char			**ret;

	if (s)
	{
		if (!(ret = (char **)malloc(sizeof(char *) * (c_words(s, c) + 1))))
			return (NULL);
		if (fill_arr(ret, s, c) == 0)
		{
			free(ret);
			return (NULL);
		}
		ret[c_words(s, c)] = 0;
		return (ret);
	}
	return (NULL);
}
