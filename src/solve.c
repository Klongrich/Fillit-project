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


// return a boolen, not a char ** instead to let the function know 
// if it has all pecies placed. Also do not do integer comparisons
// in the while loop conditons use the terti_map that was passed
// to check if it is a null pointer or not at the row as well as row and column
// index. Do not pass size  instead pass the row and columon positions 
// of the tetri_map or board.
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
				//change remove_tetri to a void function that use the board
				//already allocated. Also update remove_tetri to not loop
				//through the entire board, instead pass the column and row
				//instead of the size
				tetri_map = remove_tetri(tetri_map, tetri, size);
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

	//get the smallest possible borad
	tetri_map = tetri_map_new(tetri_map, size);

	//get rid of  result, only pass the board that was allocated at first
	result = NULL;
	while (!(result = algo(tetri_map, tetri, size)))
	{
		size++;
		ft_memdel((void **)tetri_map);
		tetri_map = tetri_map_new(tetri_map, size);
	}
	print_map(result);
}
