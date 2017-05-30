/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lignpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 09:33:19 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lign_position_1(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][0] = 1;
		position->pos[0][1] = 1;
		position->pos[1][0] = 1;
		position->pos[2][0] = 1;
	}
	if (i == 2)
	{
		position->pos[0][0] = 1;
		position->pos[0][1] = 1;
		position->pos[1][1] = 1;
		position->pos[2][1] = 1;
	}
}

void	ft_lign_position_2(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][0] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
		position->pos[2][0] = 1;
	}
	if (i == 2)
	{
		position->pos[0][1] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
		position->pos[2][1] = 1;
	}
}

void	ft_lign_position_3(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][0] = 1;
		position->pos[1][0] = 1;
		position->pos[2][0] = 1;
		position->pos[2][1] = 1;
	}
	if (i == 2)
	{
		position->pos[0][1] = 1;
		position->pos[1][1] = 1;
		position->pos[2][1] = 1;
		position->pos[2][0] = 1;
	}
}

void	ft_lign_position_4(t_pos *position, int i)
{
	if (i == 1)
	{
		position->pos[0][1] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
		position->pos[2][0] = 1;
	}
	if (i == 2)
	{
		position->pos[0][0] = 1;
		position->pos[1][0] = 1;
		position->pos[1][1] = 1;
		position->pos[2][1] = 1;
	}
}

void	ft_lign_position_h_v(t_pos *position, int i)
{
	if (i == 0)
	{
		position->pos[0][0] = 1;
		position->pos[0][1] = 1;
		position->pos[0][2] = 1;
		position->pos[0][3] = 1;
	}
	if (i == 3)
	{
		position->pos[0][0] = 1;
		position->pos[1][0] = 1;
		position->pos[2][0] = 1;
		position->pos[3][0] = 1;
	}
}
