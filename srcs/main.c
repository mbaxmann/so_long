/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:17:07 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/19 18:04:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_test(char **map)
{
	int	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	ft_error(char *str, int fd, char **map)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "invalid map", 11))
		ft_putendl_fd("Error\nInvalid map", 1);
	else if (!ft_strncmp(str, "gnl", 3))
		ft_putendl_fd("Error\nFailed to read map.ber", 1);
	else if (!ft_strncmp(str, "fd", 2))
		ft_putendl_fd("Error\nFailed to read map.ber", 1);
	else if (!ft_strncmp(str, "malloc", 6))
		ft_putendl_fd("Error\nMalloc failed somewhere", 1);
	else if (!ft_strncmp(str, "ext", 3))
                ft_putendl_fd("Error\nWrong extension for map", 1);
	if (fd)
		close (fd);
	if (map && fd == -1)
		free(map);
	else if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	exit(1);
}

void	ft_free_textur(t_textur *textur)
{
	free(textur->img);
	free(textur);
}

void	ft_free_img(t_img **img)
{
	int i;

	i = 0;
	while (i < 2)
	{
		free(img[i]->img);
		free(img[i]);
		i++;
	}
	free(img);
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data)
	{
		if (data->map)
		{
			while (data->map[i])
				free(data->map[i++]);
			free(data->map);
		}
		free(data->mlx->ptr);
		free(data->mlx->win);
		free(data->mlx);
		ft_free_img(data->img);
		i = 0;
		while (i < 5)
			ft_free_textur(data->textur[i++]);
		free(data->textur);
	}
}

int	main(int ac, char **av)
{
	char	**map;

	if (ac == 1)
		return (0);
	map = ft_init(av);
	ft_engine(map);
	ft_test(map);
}
