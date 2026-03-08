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



void 	insert_tetri2(char **map, t_tetri *tetri, int y, int x){
	int i;

	i = 0;
	while (i < 4) {
		map[y + tetri->y[i]][x + tetri->x[i]] = tetri->c;
		i++;
	}

}

char	**algo(char **tetri_map, t_tetri *tetri, int size)
{
	int		x;
	int		y;
	char	**map;

	if (tetri->next == NULL)
		return (tetri_map);
	map = NULL;
 	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (check_tetri(tetri_map, tetri, x ,y, size)) {
				
				insert_tetri2(tetri_map, tetri, y,x);

				if((map = algo(tetri_map,tetri->next, size))) {
					return (tetri_map);
				}
				tetri_map = remove_tetri(tetri_map, tetri, size);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

int smallest_board(t_tetri *tetri){

	int amount_of_tetri;
	int size;
	int j;
	t_tetri *tmp;
	
	amount_of_tetri = 0;
	j = 2;
	tmp = tetri;
	while (tmp->next) {
		amount_of_tetri++;
		tmp = tmp->next;
	}

	size = amount_of_tetri * 4;
	while (size > (j * j)) {
		j++;
	} 
	return (j);
}

void	solve(t_tetri *tetri)
{
	char	**result;
	char	**tetri_map;
	int		size;

	size = smallest_board(tetri);
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
