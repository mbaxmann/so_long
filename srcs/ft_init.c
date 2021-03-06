/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:20:47 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/22 11:33:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_fillmap(char *map)
{
	t_list	*first;
	t_list	*current;
	char	**ret;
	int		i;

	ret = NULL;
	first = ft_list_init(map);
	i = ft_list_len(first);
	ret = (char **)malloc(sizeof(char *) * (i + 1));
	if (!ret)
		ft_error("malloc", -1, ret);
	i = 0;
	current = first;
	while (current)
	{
		ret[i] = ft_strdup(current->data);
		current = current->next;
		i++;
	}
	ret[i] = NULL;
	ft_free_lst(first);
	return (ret);
}

int	ft_valide_c(char c)
{
	if (c != '0' && c != '1'
		&& c != 'C' && c != 'E'
		&& c != 'P')
	{
		return (0);
	}
	else
		return (1);
}

void	ft_check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (!ft_valide_c(map[i][j]))
				ft_error("invalid map", 0, map);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_check_ext(char *str)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".ber", 5))
		ft_error("ext", 0, NULL);
}

char	**ft_init(char **av)
{
	char	**map;

	if (!av[1])
		return (NULL);
	else
	{
		ft_check_ext(av[1]);
		map = ft_fillmap(av[1]);
		if (!ft_mapisclose(map))
			ft_error("invalid map", 0, map);
		if (!ft_mapis_rectangular(map))
			ft_error("invalid map", 0, map);
		ft_check_map(map);
		if (!ft_allok(map))
			ft_error("invalid map", 0, map);
	}
	return (map);
}
