/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:02:14 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/20 10:41:29 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_mapis_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	ft_lineiswall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_allok(char **map)
{
	int	tab[3];
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				tab[0]++;
			else if (map[i][j] == 'C')
				tab[1]++;
			else if (map[i][j] == 'P')
				tab[2]++;
			j++;
		}
		j = 0;
		i++;
	}
	if (!tab[0] || !tab[1] || tab[2] != 1)
		return (0);
	return (1);
}

int	ft_mapisclose(char **map)
{
	int	i;

	i = 0;
	if (!ft_lineiswall(map[i]))
		return (0);
	i++;
	while (map[i])
	{
		if (map[i][0] != '1'
		|| map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	if (!ft_lineiswall(map[i - 1]))
		return (0);
	return (1);
}
