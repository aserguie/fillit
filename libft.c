/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:40:48 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen(s1);
	j = 0;
	if (!(new = (char*)malloc(sizeof(*new) * i + 1)))
		return (NULL);
	while (s1[j])
	{
		new[j] = s1[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(strjoin = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
