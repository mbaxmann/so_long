/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:39:50 by user42            #+#    #+#             */
/*   Updated: 2021/09/19 17:20:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		ft_close(void *param)
{
	((t_data *)param)->map[0][0] = '1';
	exit(0);
	return (1);
}

void		ft_find_player(char **map, t_dim *pos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos->x = j;
				pos->y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void		ft_move_player(t_data *data, t_dim *pos, int d_y, int d_x)
{
	t_dim	stock;
	char	**map;
	char	*nb;

	stock.x = pos->x;
	stock.y = pos->y;
	map = data->map;
	if (d_y)
		pos->y += d_y;
	else
		pos->x += d_x;
	if (map[pos->y][pos->x] == '0' || map[pos->y][pos->x] == 'C')
	{
		map[pos->y][pos->x] = 'P';
		map[stock.y][stock.x] = '0';
	}
	else if (map[pos->y][pos->x] == 'E')
	{
		exit(0);
	}
	data->count++;
	nb = ft_itoa(data->count, 'd');
	write(1, nb, ft_strlen(nb));
}

int		ft_button_event(int keycode, void *param)
{
	t_dim	pos;

	ft_find_player(((t_data *)param)->map, &pos);
	if (keycode == ESC)
	{
		exit(0);
	}
	else if (keycode == LEFT)
		ft_move_player(((t_data *)param), &pos, 0, -1);
	else if (keycode == RIGHT)
		ft_move_player(((t_data *)param), &pos, 0, 1);
	else if (keycode == UP)
		ft_move_player(((t_data *)param), &pos, -1, 0);
	else if (keycode == DOWN)
		ft_move_player(((t_data *)param), &pos, 1, 0);
	return (0);
}

void	ft_event(t_data *data)
{
	mlx_hook(data->mlx->win, 2, 1L << 0, &ft_button_event, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, &ft_close, data);
}
