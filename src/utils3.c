/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:18:20 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/07 17:29:33 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*stack_check(int size, char **tmp, char **argv, int check)
{
	t_stack	*tmp2;

	tmp = 0;
	if (check == 0)
	{
		size = 0;
		tmp = ft_split(argv[1], ' ');
		while (tmp[size])
			size++;
		if (!input_check(tmp))
			exit_error(NULL, NULL);
		tmp2 = fill_stack_values(size, tmp);
	}
	else
	{
		if (!input_check(argv))
			exit_error(NULL, NULL);
		tmp2 = fill_stack_values(size, argv);
	}
	return (tmp2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		start = ft_strlen(s);
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	i = 0;
	dest = (char *) malloc (sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (len--)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

int	nb_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if ((*s != c) && (j == 0))
		{
			j = 1;
			i++;
		}
		if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

static char	**wds_assign(const char *s, char c, char **dest, size_t len)
{
	size_t	i;
	size_t	x;
	int		j;

	i = 0;
	x = 0;
	j = -1;
	while (i <= len)
	{
		if (s[i] != c && j < 0)
			j = i;
		else if ((s[i] == c || i == len) && j >= 0)
		{
			dest[x++] = ft_substr(s, j, (i - j));
			j = -1;
		}
		i++;
	}
	dest[x] = 0;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;
	size_t	len;
	int		i;

	i = 0;
	if (s[0] == '\0')
		exit(0);
	while (s[i] <= 32 && s[i] != '\0')
	{
		i++;
		if (s[i] == '\0')
			exit(0);
	}
	len = (ft_strlen(s));
	dest = (char **) malloc ((nb_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	wds_assign(s, c, dest, len);
	return (dest);
}
