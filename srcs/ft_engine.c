/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:54:43 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/19 18:12:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_mlx	*ft_open_window(char **map)
{
	t_mlx	*mlx;
	int	x_max;
	int	y_max;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		ft_error("mlx", 0, map);
	mlx_get_screen_size(mlx->ptr, &x_max, &y_max);
	mlx->win = mlx_new_window(mlx->ptr, x_max, y_max, "so_long");
	if (!mlx->win)
		ft_error("mlx", 0, map);
	return (mlx);
}

void	ft_setup_img(t_mlx *mlx, t_img **img)
{
	t_dim	window_s;
	int	i;

	i = 0;
	mlx_get_screen_size(mlx->ptr, &(window_s.x), &(window_s.y));
	while (i < 2)
	{
		img[i] =  (t_img *)malloc(sizeof(t_img));
		img[i]->img = mlx_new_image(mlx->ptr, window_s.x, window_s.y);
		img[i]->bpp = 32;
		img[i]->endian = 0;
		img[i]->line = window_s.x * 4;
		img[i]->pt = mlx_get_data_addr(img[i]->img, &img[i]->bpp,
		&img[i]->line, &img[i]->endian);
		img[i]->height = window_s.y;
		img[i]->width = window_s.x;
		i++;
	}
}

void	ft_load_textur(t_mlx *mlx, t_textur **textur)
{
	int	i;
	int	util[3];
	char	*filename;

	i = 0;
	util[0] = 32;
	util[1] = 0;
	while (i < 5)
	{
		if (i == 0)
			filename = "./textur/floor.xpm";
		else if (i == 1)
			filename = "./textur/wall.xpm";
		else if (i == 2)
			filename = "./textur/chest.xpm";
		else if (i == 3)
			filename = "./textur/exit.xpm";
		else if (i == 4)
			filename = "./textur/player.xpm";
		textur[i] = (t_textur *)malloc(sizeof(t_textur));
		textur[i]->img = mlx_xpm_file_to_image(mlx->ptr, filename, &textur[i]->width,
				&textur[i]->height);
		util[2] = textur[i]->width * 4;
		textur[i]->addr = mlx_get_data_addr(textur[i]->img, &util[0], &util[2], &util[1]);
		i++;
	}
}

int	ft_limitx(t_img *img, char *offset, int x)
{
	int tmp;

	tmp = offset - img->pt;
	tmp %= img->line;
	if ((tmp + 4 * x) > img->line)
		return (1);
	return (0);
}

int     ft_limity(t_img *img, char *offset, int y)
{
        int	tmp;

        tmp = offset - img->pt;
        tmp += img->line * y;
        if (tmp > img->line * img->height)
                return (1);
        return (0);
}

void	ft_put_textur(t_img *img, t_dim coord, t_dim squar, t_textur *textur)
{
	int	i;
	int	j;
	unsigned int	pixel;
	t_dim	ratio;
	char	*offset;

	i = 0;
	j = 0;
	offset = img->pt + (coord.y * img->line * squar.y) + (coord.x * 4 * squar.x);
	while (i < squar.y && !ft_limity(img, offset, i))
	{
		offset += i * img->line;
		ratio.y = (i * textur->height) / squar.y;
		while (j < squar.x && !ft_limitx(img, offset, j))
		{
			ratio.x = (j * textur->height) / squar.x;
			offset += j * 4;
			pixel = *((unsigned int *)(textur->addr
			+ (ratio.y * textur->height * 4) + (4 * ratio.x)));
			if (pixel)
				*(unsigned int *)offset = pixel;
			offset -= j * 4;
			j++;
		}
		j = 0;
		offset -= i * img->line;
		i++;
	}
}

int	ft_choose_textur(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'C')
                return (2);
	else if (c == 'E')
                return (3);
	else if (c == 'P')
                return (4);
	return (0);
}

int	ft_supp(int big, int small)
{
	double i;
	int	j;

	i = (double)big / (double)small;
	j = big / small;
	if (i != j)
	{
		return (j + 1);
	}
	else
		return (j);
}

void	ft_load_img(t_mlx *mlx, t_img **img, char **map, t_data *data)
{
	t_dim	loop;
	t_dim	squar;
	int	n;

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
	while (map[loop.y])
	{
		while (map[loop.y][loop.x])
		{
			n = ft_choose_textur(map[loop.y][loop.x]);
			if (n != 0 && n != 1)
				ft_put_textur(img[1], loop, squar, data->textur[0]);
			ft_put_textur(img[1], loop, squar, data->textur[n]);
			loop.x++;
		}
		loop.y++;
		loop.x = 0;
	}
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
        mlx_put_image_to_window(data->mlx->ptr, data->mlx->win, data->img[1]->img, 0, 0);
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
