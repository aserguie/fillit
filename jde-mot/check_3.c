/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form_lign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:40:19 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_form_lign_v(t_file *tetri)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	while (k++ <= 20)
	{
		if (tetri->line[i] == '#')
		{
			if ((tetri->line[i + 5] == '#') && (tetri->line[i + 10] == '#') &&
					(tetri->line[i + 15] == '#'))
				j = 4;
		}
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

static int			ft_form_lign_compact(t_file *tetri)
{
	int				i;
	int				k;
	int				l;

	i = -1;
	k = 0;
	l = 0;
	while (i++ <= 20)
	{
		if (tetri->line[i] == '#')
		{
			while (l < 4)
			{
				if (tetri->line[i] == '#')
					l++;
				k = k + (unsigned char)tetri->line[i];
				i++;
			}
		}
	}
	if (k == 436)
		k = ft_check_436(tetri);
	if ((k == 344 || k == 390 || k == 436) && l == 4)
		return (1);
	return (0);
}

static int			ft_lign_h(t_file *tetri)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 20)
	{
		if (tetri->line[i] == '#')
		{
			while (j < 4)
			{
				if (tetri->line[i] == '#')
					j++;
				k = k + (unsigned char)tetri->line[i];
				i++;
			}
		}
		i++;
	}
	if ((k == 140) && (j == 4))
		return (1);
	return (0);
}

static int			ft_form_compact(t_file *tetri)
{
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 20)
	{
		if (tetri->line[i] == '#')
		{
			while (j < 4)
			{
				if (tetri->line[i] == '#')
					j++;
				k = k + (unsigned char)tetri->line[i];
				i++;
			}
		}
		i++;
	}
	if ((k == 196 || k == 242 || k == 288) && (j == 4))
		return (1);
	return (0);
}

int					ft_check_3(t_file *tetri)
{
	int				i;
	int				k;

	i = 0;
	k = 1;
	while (tetri)
	{
		if (ft_nbligne(tetri) != 1 && ft_nbligne(tetri) != 2
				&& ft_nbligne(tetri) != 3 && ft_nbligne(tetri) != 0)
			k--;
		if (ft_nbligne(tetri) == 1)
			if (ft_form_compact(tetri) == 0)
				k--;
		if (ft_nbligne(tetri) == 2)
			if (ft_form_lign_compact(tetri) == 0)
				k--;
		if (ft_nbligne(tetri) == 3)
			if (ft_form_lign_v(tetri) == 0)
				k--;
		if (ft_nbligne(tetri) == 0)
			if (ft_lign_h(tetri) == 0)
				k--;
		tetri = tetri->next;
	}
	return (k);
}
