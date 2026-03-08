/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:12:48 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/12 15:35:23 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_tetri
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_tetri	*next;
}					t_tetri;

int					count_tetri(char *str);
void				set_tetri(t_tetri **tmp, char *str);
t_tetri				*extract_tetriminos(char *vaildated_characters_read);
char				*stock_str(int fd);
void				xy_tetri(t_tetri **tetri, int x, int y);
char				**algo(char **tetri_map, t_tetri *tetri, int size);
void				solve(t_tetri *tetri);
char				**tetri_map_new(char **map, int size);
char				**tetri_map_dot(char **map, int size);
void				print_map(char **map);
char				**remove_tetri(char **map, t_tetri *tetri, int size);
void				insert_tetri(char **map, t_tetri *tetri, int y, int x);
int					check_link(char *stock, int j);
int					count_valid_char(char *stock, int j);
int					check_str(char *stock);
int					check_tetri(char **map, t_tetri *tetri, int x, int y, int size);

#endif
