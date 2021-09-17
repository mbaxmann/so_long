/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:54:43 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/17 17:00:37 by mbaxmann         ###   ########.fr       */
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

void	*ft_create_img(char **map, t_mlx *mlx)
{
	void	*img;
	t_dim	window_s;
	t_dim	square;
	int	i;

	i = 0;
	mlx_get_screen_size(mlx->ptr, &(window_s.x), &(window_s.y));
	img = mlx_new_image(mlx->ptr, window_s.x, window_s.y);
	while (map[i])
		i++;
	square.x = window_s.x / ft_strlen(map[0]);
	square.y = window_s.y / i;
}

void	ft_engine(char **map)
{
	t_mlx	*mlx;
	void	*img;

	mlx = ft_open_window(map);
	img = ft_create_img(map, mlx);
	mlx_loop(mlx->ptr);
}
