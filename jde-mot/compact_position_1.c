/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmppos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:33:02 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_compact_position_1(t_pos *position)
{
	position->pos[0][0] = 1;
	position->pos[0][1] = 1;
	position->pos[1][0] = 1;
	position->pos[1][1] = 1;
}

void	ft_compact_position_2(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][0] = 1;
		position->pos[0][1] = 1;
		position->pos[1][1] = 1;
		position->pos[1][2] = 1;
	}
	if (i == 2)
	{
		position->pos[0][1] = 1;
		position->pos[0][2] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
	}
}

void	ft_compact_position_3(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][1] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
		position->pos[1][2] = 1;
	}
	if (i == 2)
	{
		position->pos[0][0] = 1;
		position->pos[0][1] = 1;
		position->pos[0][2] = 1;
		position->pos[1][1] = 1;
	}
}

void	ft_compact_position_4(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][0] = 1;
		position->pos[0][1] = 1;
		position->pos[0][2] = 1;
		position->pos[1][0] = 1;
	}
	if (i == 2)
	{
		position->pos[0][0] = 1;
		position->pos[0][1] = 1;
		position->pos[0][2] = 1;
		position->pos[1][2] = 1;
	}
}

void	ft_compact_position_5(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][0] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
		position->pos[1][2] = 1;
	}
	if (i == 2)
	{
		position->pos[0][2] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
		position->pos[1][2] = 1;
	}
}
