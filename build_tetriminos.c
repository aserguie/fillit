/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:32:40 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos		*ft_update_pos(t_pos *tetri, int x, int y)
{
	int		left;
	int		top;
	int		i;

	left = 150;
	top = 150;
	i = 0;
	while (i != 4)
	{
		if (tetri->x[i] < left)
			left = tetri->x[i];
		if (tetri->y[i] < top)
			top = tetri->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		tetri->x[i] = tetri->x[i] - left + x;
		tetri->y[i] = tetri->y[i] - top + y;
		i++;
	}
	return (tetri);
}

char		**ft_set_map(char **map, int size)
{
	int		y;
	int		x;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (y < size)
	{
		map[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	map[y] = NULL;
	return (map);
}

void		ft_make_coord(t_pos *tetri)
{
	int		i;
	int		j;
	int		k;

	while (tetri)
	{
		i = 0;
		k = 0;
		while (k < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (tetri->pos[i][j] == 1)
				{
					tetri->x[k] = j;
					tetri->y[k] = i;
					k++;
				}
				j++;
			}
			i++;
		}
		tetri = tetri->next;
	}
}

t_file		*ft_make_lst_end(t_file *file)
{
	t_file	*pieces;
	t_file	*tmp;
	int		i;

	i = 1;
	tmp = (t_file *)malloc(sizeof(t_file));
	tmp->line = file->line;
	pieces = tmp;
	file = file->next;
	while (file->next)
	{
		tmp->line = ft_strjoin(tmp->line, file->line);
		if (i == 4)
		{
			tmp->next = (t_file *)malloc(sizeof(t_file));
			tmp = tmp->next;
			file = file->next;
			tmp->line = file->line;
			i = 0;
		}
		i++;
		file = file->next;
	}
	tmp->next = NULL;
	return (pieces);
}

t_file		*ft_make_lst_begin(char *file_name, t_file *file)
{
	int		fd;
	char	*line;
	int		ret;
	t_file	*tmp;

	file = (t_file *)malloc(sizeof(t_file));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	tmp = file;
	while ((ret = get_next_line((int const)fd, &line)) > 0)
	{
		file->line = ft_strdup(line);
		file->line = ft_strjoin(file->line, "\n");
		file->next = (t_file *)malloc(sizeof(t_file));
		file = file->next;
	}
	file->next = NULL;
	close(fd);
	return (tmp);
}
