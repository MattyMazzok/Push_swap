/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmazzocc <mmazzocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:25:19 by mmazzocc          #+#    #+#             */
/*   Updated: 2023/02/08 02:06:05 by mmazzocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*ft_strjoin_gnl(char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *) malloc (sizeof(char) * (ft_strlen(s) + 2));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(s);
	return (new);
}

char	*ft_read_line_gnl(int fd, char *dst)
{
	int		len;
	char	buf;

	len = 1;
	while (len != 0 && buf != '\n')
	{
		len = read(fd, &buf, 1);
		if (len == -1)
			return (NULL);
		dst = ft_strjoin_gnl(dst, buf);
	}
	if (dst[0] == '\n')
		return ("\n");
	if (!dst[1])
		return (NULL);
	return (dst);
}

char	*ft_get_next_line(int fd)
{
	char	*dst;

	if (fd < 0)
		return (NULL);
	dst = (char *) malloc (sizeof(char) * 1);
	if (!dst)
		return (NULL);
	dst[0] = '\0';
	dst = ft_read_line_gnl(fd, dst);
	if (!dst)
		return (NULL);
	return (dst);
}
