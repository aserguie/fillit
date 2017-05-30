/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-mot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:47:30 by jde-mot           #+#    #+#             */
/*   Updated: 2017/01/04 11:42:37 by jde-mot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_file
{
	char			*line;
	struct s_file	*next;
}					t_file;

typedef struct		s_pos
{
	char			**pos;
	char			name;
	int				x[4];
	int				y[4];
	struct s_pos	*next;
}					t_pos;

int					get_next_line(int const fd, char **line);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *s1);
void				ft_putchar(char c);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
t_file				*ft_make_lst_begin(char *file_name, t_file *file);
t_file				*ft_make_lst_end(t_file *file);
t_pos				*ft_make_lst_final(t_file *tetri);
int					ft_check_1(t_file *file);
int					ft_check_2(t_file *tetri);
int					ft_check_3(t_file *tetri);
int					ft_check_436(t_file *tetri);
int					ft_nbligne(t_file *tetri);
int					ft_check_nbp(t_file *file);
int					ft_check_nbl(t_file *file);
void				ft_compact_position(t_pos *position, t_file *tetri);
void				ft_compact_position_5(t_pos *position, int i);
void				ft_compact_position_4(t_pos *position, int i);
void				ft_compact_position_3(t_pos *position, int i);
void				ft_compact_position_2(t_pos *position, int i);
void				ft_compact_position_1(t_pos *position);
void				ft_compact_lign_position(t_pos *position, t_file *tetri);
void				ft_lign_position_h_v(t_pos *position, int i);
void				ft_lign_position_4(t_pos *position, int i);
void				ft_lign_position_3(t_pos *position, int i);
void				ft_lign_position_2(t_pos *position, int i);
void				ft_lign_position_1(t_pos *position, int i);
void				ft_listdel(t_file *alst);
void				ft_make_coord(t_pos *tetri);
t_pos				*ft_update_pos(t_pos *tetri, int x, int y);
char				**ft_set_map(char **map, int size);
char				**ft_result(t_pos *tetri, int size);
#endif
