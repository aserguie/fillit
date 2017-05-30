/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeposligncmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:14:22 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_condition_1(t_pos *position, t_file *tetri, int i)
{
	if (tetri->line[i + 5] == '#')
		ft_lign_position_1(position, 1);
	else
		ft_lign_position_1(position, 2);
}

static void		ft_condition_2(t_pos *position, t_file *tetri, int i)
{
	if (tetri->line[i + 9] == '#')
		ft_lign_position_4(position, 1);
	else
		ft_lign_position_4(position, 2);
}

static void		ft_condition_3(t_pos *position, t_file *tetri, int i)
{
	if (tetri->line[i + 4] == '#')
	{
		ft_lign_position_2(position, 2);
		return ;
	}
	if (tetri->line[i + 6] == '#')
	{
		ft_lign_position_2(position, 1);
		return ;
	}
	if (tetri->line[i + 9] == '#')
		ft_lign_position_3(position, 2);
	else
		ft_lign_position_3(position, 1);
}

void			ft_compact_lign_position(t_pos *position, t_file *tetri)
{
	int		i;

	i = 0;
	while (tetri->line[i])
	{
		if (tetri->line[i] == '#')
		{
			if (tetri->line[i + 1] == '#')
			{
				ft_condition_1(position, tetri, i);
				return ;
			}
			if (tetri->line[i + 10] == '.')
			{
				ft_condition_2(position, tetri, i);
				return ;
			}
			if (tetri->line[i + 5] == '#')
			{
				ft_condition_3(position, tetri, i);
				return ;
			}
		}
		i++;
	}
}
