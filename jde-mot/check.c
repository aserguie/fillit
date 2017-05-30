/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:29:31 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_caract(t_file *tetri)
{
	int			i;
	int			j;

	while (tetri)
	{
		j = 0;
		i = 0;
		while (i <= 20)
		{
			if (tetri->line[i] == '#')
			{
				while (tetri->line[i] == '#')
				{
					j++;
					i++;
				}
			}
			i++;
		}
		if (j != 4)
			return (0);
		tetri = tetri->next;
	}
	return (j);
}

static int		ft_check_null(t_file *tetri)
{
	t_file		*tmp;
	size_t		i;

	tmp = tetri;
	while (tmp->next)
	{
		i = 0;
		while (i < ft_strlen(tmp->line))
		{
			if ((tmp->line[i] != '.') && (tmp->line[i] != '#') &&
					(tmp->line[i] != '\n'))
				return (0);
			i++;
		}
		if ((tmp->line[0] == '\n') && (tmp->next->next == NULL))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		ft_len(t_file *tetri)
{
	t_file		*tmp;

	tmp = tetri;
	while (tmp)
	{
		if (ft_strlen(tmp->line) != 21)
		{
			if (ft_strlen(tmp->line) == 20 && tmp->next == NULL)
				return (1);
			else
			{
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int				ft_check_2(t_file *tetri)
{
	t_file		*tmp;

	tmp = tetri;
	if (ft_len(tmp) == 0)
		return (0);
	tmp = tetri;
	if (ft_check_3(tmp) <= 0)
		return (0);
	tmp = tetri;
	if (ft_check_caract(tmp) != 4)
		return (0);
	return (1);
}

int				ft_check_1(t_file *file)
{
	t_file		*tmp;

	tmp = file;
	if (ft_check_nbl(tmp) == 0)
		return (0);
	tmp = file;
	if (ft_check_nbp(tmp) == 0)
		return (0);
	tmp = file;
	if (ft_check_null(tmp) == 0)
		return (0);
	return (1);
}
