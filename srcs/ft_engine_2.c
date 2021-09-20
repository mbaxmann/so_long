/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:55:41 by user42            #+#    #+#             */
/*   Updated: 2021/09/20 16:04:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_mlx	*ft_open_window(char **map)
{
	t_mlx	*mlx;
	int		x_max;
	int		y_max;

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
	int		i;

	i = 0;
	mlx_get_screen_size(mlx->ptr, &(window_s.x), &(window_s.y));
	while (i < 2)
	{
		img[i] = (t_img *)malloc(sizeof(t_img));
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

char	*ft_choose_file(int i)
{
	char	*filename;

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
	return (ft_strdup(filename));
}

void	ft_load_textur(t_mlx *mlx, t_textur **textur)
{
	int		i;
	int		util[3];
	char	*filename;

	i = 0;
	util[0] = 32;
	util[1] = 0;
	while (i < 5)
	{
		filename = ft_choose_file(i);
		textur[i] = (t_textur *)malloc(sizeof(t_textur));
		textur[i]->img = mlx_xpm_file_to_image(mlx->ptr, filename,
				&textur[i]->width, &textur[i]->height);
		util[2] = textur[i]->width * 4;
		textur[i]->addr = mlx_get_data_addr(textur[i]->img,
				&util[0], &util[2], &util[1]);
		free(filename);
		i++;
	}
}

int	ft_limitx(t_img *img, char *offset, int x)
{
	int	tmp;

	tmp = offset - img->pt;
	tmp %= img->line;
	if ((tmp + 4 * x) > img->line)
		return (1);
	return (0);
}
