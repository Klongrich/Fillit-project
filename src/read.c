/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:58:01 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/12 17:38:29 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"
#include <stdlib.h>

int			count_tetriminos(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	return (result / 4);
}

void	convert_then_store_xy_coordinates(t_tetri **tmp, char *trimmed_validated_characters_read)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (trimmed_validated_characters_read[i] != '\0')
	{
		if (trimmed_validated_characters_read[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_tetri		*extract_tetriminos(char *vaildated_characters_read)
{
	int		amount_of_tetriminos;
	int		tetrimino_start;
	char	tetrimino_character;
	t_tetri *extracted_tetriminos;
	t_tetri *tmp;

	tetrimino_start = 0;
	tetrimino_character = 'A';
	amount_of_tetriminos = count_tetriminos(vaildated_characters_read);
	if (!(extracted_tetriminos = (t_tetri *)malloc(sizeof(t_tetri) * amount_of_tetriminos + 1)))
		return (NULL);
	tmp = extracted_tetriminos;
	while (amount_of_tetriminos > 0)
	{
		tmp->c = tetrimino_character;
		convert_then_store_xy_coordinates(&tmp, ft_strsub(vaildated_characters_read, 0 + tetrimino_start, 20));
		if (!(tmp->next = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		amount_of_tetriminos--;
		tetrimino_character++;
		tetrimino_start += 21;
	}
	tmp->next = NULL;
	return (extracted_tetriminos);
}

char		*stock_str(int fd)
{
	int		read_status;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	read_status = read(fd, &c, 1);
	if (read_status < 0)
		return (NULL);
	if (read_status == 1)
	{
		str = (char *)malloc(sizeof(char) * 600);
		while (read_status != '\0')
		{
			str[i] = c;
			i++;
			read_status = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
