/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:29:10 by jde-mot           #+#    #+#             */
/*   Updated: 2017/02/17 17:21:48 by jde-mot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_reset(char **map, t_pos *tetri, int size)
{
	int		x;
	int		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[y][x] == tetri->name)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

static char		**ft_save_map(char **map, t_pos *tetri, int size)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tetri->x[i] == x && tetri->y[i] == y)
			{
				map[y][x] = tetri->name;
				i++;
			}
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

static int		ft_valid(char **map, t_pos *tetri, int size)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < size && i < 4)
	{
		x = 0;
		while (x < size && i < 4)
		{
			if (map[y][x] != '.' && tetri->x[i] == x && tetri->y[i] == y)
				return (0);
			else if (tetri->x[i] == x && tetri->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char		**ft_solve(char **map, t_pos *tetri, int size)
{
	int		x;
	int		y;
	char	**tmp;

	if (!tetri)
		return (map);
	tmp = NULL;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			tetri = ft_update_pos(tetri, x, y);
			if (ft_valid(map, tetri, size))
				tmp = ft_solve(ft_save_map(map, tetri, size),
						tetri->next, size);
			if (tmp)
				return (tmp);
			map = ft_reset(map, tetri, size);
			++x;
		}
		++y;
	}
	return (NULL);
}

char			**ft_result(t_pos *tetri, int size)
{
	char	**map;

	map = NULL;
	while (!map)
	{
		map = ft_set_map(map, size);
		map = ft_solve(map, tetri, size);
		size++;
	}
	return (map);
}
