/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 07:32:16 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_min_size(t_file *file)
{
	int			i;
	int			j;

	i = 0;
	j = ft_check_nbp(file);
	while (i * i < j)
		i++;
	return (i);
}

static void		ft_display(char **map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

static void		ft_prog(t_file *tetri, int size)
{
	t_pos		*tetri_final;
	t_pos		*tmp;
	char		**map;

	tetri_final = ft_make_lst_final(tetri);
	tmp = tetri_final;
	ft_make_coord(tmp);
	map = ft_result(tetri_final, size);
	ft_display(map);
}

static int		ft_error(t_file *file, t_file *tetri, int i)
{
	if (i == -1)
	{
		write(1, "usage: fillit file\n", 19);
		return (0);
	}
	if (i == 0)
	{
		write(1, "error\n", 7);
		return (0);
	}
	if (i == 1 && ft_check_1(file) == 0)
	{
		write(1, "error\n", 7);
		return (0);
	}
	if (i == 2 && ft_check_2(tetri) == 0)
	{
		write(1, "error\n", 7);
		return (0);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_file		*tetri;
	t_file		*file;
	int			size;

	file = NULL;
	tetri = NULL;
	if (argc != 2)
	{
		ft_error(file, tetri, -1);
		return (0);
	}
	if (!(file = ft_make_lst_begin(argv[1], file)))
	{
		ft_error(file, tetri, 0);
		return (0);
	}
	if (ft_error(file, tetri, 1) == 0)
		return (0);
	size = ft_min_size(file);
	tetri = ft_make_lst_end(file);
	ft_listdel(file);
	if (ft_error(file, tetri, 2) == 0)
		return (0);
	ft_prog(tetri, size);
	return (0);
}
