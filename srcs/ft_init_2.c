/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:02:14 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/20 15:53:35 by user42           ###   ########.fr       */
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
