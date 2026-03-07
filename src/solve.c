/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:22:06 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/12 15:37:40 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	xy_tetri(t_tetri **tetri, int x, int y)
{
	int	pos_x;
	int pos_y;
	int i;

	i = 0;
	pos_x = 100;
	pos_y = 100;
	while (i < 4)
	{
		if ((*tetri)->x[i] < pos_x)
			pos_x = (*tetri)->x[i];
		if ((*tetri)->y[i] < pos_y)
			pos_y = (*tetri)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tetri)->x[i] = (*tetri)->x[i] - pos_x + x;
		(*tetri)->y[i] = (*tetri)->y[i] - pos_y + y;
		i--;
	}
}

char	**algo(char **tetri_map, t_tetri *tetri, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tetri->next == NULL)
		return (tetri_map);
	map = tetri_map;
 	y = 0;
	while (y < size)
	{
		x = 0;
	//	printf("y in algo: %d\n", y);
	//	printf("size in algo: %d\n", size);
		while (x < size)
		{
			xy_tetri(&tetri, 0, 0);
			if (check_tetri(tetri_map, tetri, x ,y, size)) {
				if((map = algo(insert_tetri(tetri_map, tetri, y, x),
						tetri->next, size))) {
					return (map);
				} else {
				 	tetri_map = remove_tetri(tetri_map, tetri, size);
				}
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

void	solve(t_tetri *tetri)
{
	char	**result;
	char	**tetri_map;
	int		size;

	size = 2;
	tetri_map = NULL;
	tetri_map = tetri_map_new(tetri_map, size);
	result = NULL;
	while (!(result = algo(tetri_map, tetri, size)))
	{
		size++;
		ft_memdel((void **)tetri_map);
		tetri_map = tetri_map_new(tetri_map, size);
	}
	print_map(result);
}
