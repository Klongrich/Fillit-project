/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:29 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/12 16:29:18 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		validate_tetrimino(char *characters_read, int tetrimino_start)
{
	int count;
	int j;

	j = 0;
	count = 0;
	while (j + tetrimino_start < 20 + tetrimino_start)
	{
		if (characters_read[j + tetrimino_start] == '#')
		{
			//Check if the next character is within bounds && if it is a '#'
			if ((j + tetrimino_start + 1) < (20 + tetrimino_start) && characters_read[j + tetrimino_start + 1] == '#')
				count++;

			//Check if the previous chacters is within bounds && if that character is a '#'
			if ((j + tetrimino_start - 1) >= (0 + tetrimino_start) && characters_read[j + tetrimino_start - 1] == '#')
				count++;
			
			//Check if the next y-value is within bounds && if that value is a "#'
			if ((j + tetrimino_start + 5) < (20 + tetrimino_start) && characters_read[j + tetrimino_start + 5] == '#')
				count++;
			
			//Check if the pervious y-value is within bounds && if that value is a '#'
			if ((j + tetrimino_start - 5) >= (0 + tetrimino_start) && characters_read[j + tetrimino_start - 5] == '#')
				count++;
		}
		j++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int		count_valid_characters(char *characters_read, int j)
{
	int dash;
	int dot;
	int newline;
	int i;

	i = 0;
	dash = 0;
	dot = 0;
	newline = 0;
	while (i + j < 20 + j && characters_read[i + j] != '\0')
	{
		if (characters_read[i + j] == '#')
			dash++;
		if (characters_read[i + j] == '.')
			dot++;
		if (characters_read[i + j] == '\n')
			newline++;
		i++;
	}
	if (dash == 4 && dot == 12 && newline == 4)
		return (1);
	return (0);
}

int		check_str(char *characters_read)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (characters_read[i + j] != '\0')
	{
		if (!(validate_tetrimino(characters_read, j) && count_valid_characters(characters_read, j)))
			return (0);
		//Sets I to 19 to check the end of the tetrimino
		i = 19;
		//If the end of the file is reached return (1)
		if (characters_read[i + j] == '\n' && characters_read[i + j + 1] == '\0')
			return (1);
		//If there is another properly formatted tetrimino then increment j by 21 to start on the first character of the next tetrimino.
		if (characters_read[i + j] == '\n' && characters_read[i + j + 1] == '\n'
				&& (characters_read[i + j + 2] == '.' || characters_read[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}


int		check_tetri(char **map, t_tetri *tetri, int x, int y, int size)
{
	int i;
	int j;
	int t_x;
	int t_y;

	t_x = 0;
	t_y = 0;
	i = 0;
	j = 0;
	while (j < 4) {
			
		t_x = tetri->x[i];
		t_y = tetri->y[i];
		
		if (t_y + y > size - 1){
			return (0);
		}
		else if (map[y + t_y][x + t_x] != '.' && map[y + t_y][x + t_x]) {
			return (0);
		}
		else if (map[y + t_y][x + t_x] == '.' && map[y + t_y][x + t_x]) {
			i++;
		}
		j++;		
	}
	if (i == 4) {
		return (1);
	}
	return (0);
}
