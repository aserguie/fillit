/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:16:49 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/25 16:19:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_listdel(t_file *alst)
{
	t_file		*listdel;
	t_file		*save;

	listdel = alst;
	while (listdel)
	{
		save = listdel->next;
		ft_memdel((void*)&alst->line);
		free(alst);
		alst = NULL;
		listdel = save;
	}
	alst = NULL;
	save = NULL;
}

static int		ft_lstsize(t_file *begin_list)
{
	int			i;
	t_file		*elem;

	i = 0;
	elem = begin_list;
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}

static t_pos	*ft_lst_transform(t_file *tetri)
{
	int			i;
	char		name;
	t_pos		*position;
	t_pos		*save;

	i = ft_lstsize(tetri) - 1;
	name = 'A';
	position = (t_pos *)malloc(sizeof(t_pos));
	position->name = name;
	save = position;
	while (i-- > 0)
	{
		name = name + 1;
		position->next = (t_pos *)malloc(sizeof(t_pos));
		position = position->next;
		position->name = name;
	}
	position->next = NULL;
	return (save);
}

static t_pos	*ft_set_lst(t_file *tetri)
{
	t_pos		*save;
	t_pos		*position;
	int			j;
	int			k;

	position = ft_lst_transform(tetri);
	save = position;
	while (position)
	{
		j = -1;
		position->pos = (char **)malloc(sizeof(char *) * 4);
		while (j++ < 3)
		{
			k = -1;
			while (k++ < 4)
			{
				position->pos[j] = (char *)malloc(sizeof(char) * 3);
				position->pos[j][k] = '.';
			}
			position->pos[j][k] = '\0';
		}
		position->pos[j] = 0;
		position = position->next;
	}
	return (save);
}

t_pos			*ft_make_lst_final(t_file *tetri)
{
	t_pos		*position;
	t_pos		*tmp;

	tmp = ft_set_lst(tetri);
	position = tmp;
	while (tetri)
	{
		if (ft_nbligne(tetri) == 0)
			ft_lign_position_h_v(tmp, 0);
		if (ft_nbligne(tetri) == 3)
			ft_lign_position_h_v(tmp, 3);
		if (ft_nbligne(tetri) == 2)
			ft_compact_lign_position(tmp, tetri);
		if (ft_nbligne(tetri) == 1)
			ft_compact_position(tmp, tetri);
		tmp = tmp->next;
		tetri = tetri->next;
	}
	tmp = position;
	ft_make_coord(tmp);
	ft_listdel(tetri);
	return (position);
}
