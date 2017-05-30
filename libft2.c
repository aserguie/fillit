/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:43:22 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_bzero(void *s, size_t n)
{
	char	*src;
	size_t	i;

	src = s;
	i = 0;
	while (i < n)
	{
		src[i] = '\0';
		i++;
	}
}

static char		*ft_strchr(const char *s, int c)
{
	char		*str;

	str = (char *)s;
	while (*str != c && *str)
		str++;
	if (*str != c)
		return (NULL);
	return (str);
}

char			*ft_strnew(size_t size)
{
	char		*fresh;
	size_t		i;

	if (!(fresh = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size + 1;
	ft_bzero(fresh, i);
	return (fresh);
}

static int		ft_search_and_copy(char *buff, char **cache, char **line, int i)
{
	char		*tmp;

	if (i == 1)
		if ((tmp = ft_strchr(buff, '\n')) != NULL)
		{
			*tmp = '\0';
			*line = ft_strjoin(*cache, buff);
			ft_memdel((void*)cache);
			*cache = ft_strdup(tmp + 1);
			tmp = NULL;
			ft_bzero(buff, sizeof(buff));
			return (1);
		}
	if (i == 0)
		if (((tmp = ft_strchr(*cache, '\n')) != NULL))
		{
			*tmp = '\0';
			*line = ft_strdup(*cache);
			ft_memdel((void*)cache);
			*cache = ft_strdup(tmp + 1);
			tmp = NULL;
			return (1);
		}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*cache;
	char		buff[BUFF_SIZE + 1];
	int			i;

	if (cache != NULL)
		if (ft_search_and_copy(buff, &cache, line, 0) == 1)
			return (1);
	if (cache == NULL)
		cache = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (ft_search_and_copy(buff, &cache, line, 1) == 1)
			return (1);
		cache = ft_strjoin(cache, buff);
		ft_bzero(buff, sizeof(buff));
	}
	if (i == -1)
		return (-1);
	if (ft_strlen(cache) != 0)
		*line = ft_strdup(cache);
	if (ft_strlen(cache) == 0)
		return (0);
	ft_memdel((void*)&cache);
	return (1);
}
