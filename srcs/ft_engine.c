/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:54:43 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/20 17:17:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_img_2(t_data *data, t_dim squar)
{
	t_dim	loop;
	int		n;

	loop.x = 0;
	loop.y = 0;
	while (data->map[loop.y])
	{
		while (data->map[loop.y][loop.x])
		{
			n = ft_choose_textur(data->map[loop.y][loop.x]);
			if (n != 0 && n != 1)
				ft_put_textur(data->img[1], loop, squar, data->textur[0]);
			ft_put_textur(data->img[1], loop, squar, data->textur[n]);
			loop.x++;
		}
		loop.y++;
		loop.x = 0;
	}	
}

void	ft_load_img(t_mlx *mlx, t_img **img, char **map, t_data *data)
{
	t_dim	loop;
	t_dim	squar;

	loop.x = 0;
	loop.y = 0;
	if (!data->textur)
	{
		data->textur = (t_textur **)malloc(sizeof(t_textur *) * 5);
		ft_load_textur(mlx, data->textur);
	}
	while (map[loop.y])
		loop.y++;
	squar.y = ft_supp(img[1]->height, loop.y);
	squar.x = ft_supp(img[1]->width, ft_strlen(map[0]));
	loop.y = 0;
	ft_load_img_2(data, squar);
}

int	ft_loop(t_data *data)
{
	t_img	*tmp;

	if (!data->img)
	{
		data->img = (t_img **)malloc(sizeof(t_img *) * 2);
		ft_setup_img(data->mlx, data->img);
	}
	ft_load_img(data->mlx, data->img, data->map, data);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win,
		data->img[1]->img, 0, 0);
	tmp = data->img[1];
	data->img[1] = data->img[0];
	data->img[0] = tmp;
	return (0);
}

void	ft_setup_data(t_data *data, char **map)
{
	data->img = NULL;
	data->mlx = ft_open_window(map);
	data->map = map;
	data->count = 0;
	data->textur = NULL;
}

void	ft_engine(char **map)
{
	t_data	data;

	ft_setup_data(&data, map);
	ft_event(&data);
	mlx_loop_hook(data.mlx->ptr, &ft_loop, &data);
	mlx_loop(data.mlx->ptr);
}
