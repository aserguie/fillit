/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:44:29 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_436(t_file *tetri)
{
	int		i;

	i = -1;
	while (i++ <= 20)
	{
		if (tetri->line[i] == '#')
		{
			if (tetri->line[i + 6] == '#')
				return (436);
		}
	}
	return (0);
}

int			ft_check_nbl(t_file *file)
{
	int		i;

	i = 0;
	while (file->next)
	{
		i++;
		if (ft_strlen(file->line) != 5)
		{
			if (file->line[ft_strlen(file->line) - 1] != '\n')
				return (0);
		}
		if (i == 5)
		{
			if (file->line[0] != '\n')
				return (0);
			i = 0;
		}
		file = file->next;
	}
	return (1);
}

int			ft_check_nbp(t_file *file)
{
	int		i;
	int		j;

	j = 0;
	while (file->next)
	{
		i = 0;
		while (file->line[i])
		{
			if (i != 0 && file->line[i] == '\n' && file->line[i - 1] != '\n')
				j++;
			i++;
		}
		file = file->next;
	}
	j = j / 4;
	if (j > 26)
		return (0);
	return (j);
}

int			ft_nbligne(t_file *tetri)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 20)
	{
		if (tetri->line[i] == '#')
		{
			while (j < 4)
			{
				if (i == 20)
					return (5);
				if (tetri->line[i] == '#')
					j++;
				if (tetri->line[i] == '\n')
					k++;
				i++;
			}
		}
		i++;
	}
	return (k);
}
