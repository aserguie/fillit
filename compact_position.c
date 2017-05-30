/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeposcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:14:14 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_compact_condition_1(t_pos *position, t_file *tetri, int i)
{
	if (tetri->line[i + 2] == '#')
	{
		if (tetri->line[i + 5] == '#')
			ft_compact_position_4(position, 1);
		if (tetri->line[i + 6] == '#')
			ft_compact_position_3(position, 2);
		if (tetri->line[i + 7] == '#')
			ft_compact_position_4(position, 2);
		return ;
	}
	if (tetri->line[i + 4] == '#')
		ft_compact_position_2(position, 2);
	if (tetri->line[i + 5] == '#' && tetri->line[i + 6] == '#')
		ft_compact_position_1(position);
	if (tetri->line[i + 6] == '#' && tetri->line[i + 7] == '#')
		ft_compact_position_2(position, 1);
}

void			ft_compact_position(t_pos *position, t_file *tetri)
{
	int			i;

	i = -1;
	while (tetri->line[++i])
	{
		if (tetri->line[i] == '#')
		{
			if (tetri->line[i + 1] == '#')
			{
				ft_compact_condition_1(position, tetri, i);
				return ;
			}
			if (tetri->line[i + 3] == '#')
			{
				ft_compact_position_5(position, 2);
				return ;
			}
			if (tetri->line[i + 4] == '#')
			{
				ft_compact_position_3(position, 1);
				return ;
			}
			ft_compact_position_5(position, 1);
		}
	}
}
