/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:17:07 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/16 18:14:34 by mbaxmann         ###   ########.fr       */
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

void	ft_error(char *str)
{
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
	exit(1);
}

int	main(int ac, char **av)
{
	char	**map;

	if (ac == 1)
		return (0);
	map = ft_init(av);
	ft_test(map);
	ac++;
}