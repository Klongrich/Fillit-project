/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:15:46 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/12 17:43:47 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int			main(int argc, char **argv)
{
	char	*stock;
	int		fd;
	t_tetri	*tetri;

	if (argc != 2)
	{
		ft_putendl("usage [map]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
	{
		ft_putendl("error");
		return (0);
	}
	stock = stock_str(fd);
	if (!check_str(stock))
	{
		ft_putendl("error");
		return (0);
	}
	close(fd);
	tetri = extract_tetriminos(stock);
	solve(tetri);
	free(tetri);
	free(stock);
	return (0);
}
