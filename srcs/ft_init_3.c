/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:47:37 by user42            #+#    #+#             */
/*   Updated: 2021/09/22 12:06:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_set_var(int *var, char *map)
{
	var[0] = 1;
	var[1] = open(map, O_RDONLY);
	var[2] = 0;
}

void	ft_skip_empty_line(int	*var, char **stock)
{
	var[0] = get_next_line(var[1], stock);
	while (var[0] > 0 && !ft_strncmp(*stock, "", 1))
	{
		free(*stock);
		var[0] = get_next_line(var[1], stock);
	}
}

void	ft_list_init_2(int *var, char **stock, t_list **first)
{
	if (!(*stock))
		var[0] = get_next_line(var[1], stock);
	if (!ft_strncmp((*stock), "", 1))
		var[2] = 1;
	if (!*first && !var[2])
		*first = ft_newlst(ft_strdup(*stock));
	else if (!var[2])
		ft_add_list(*first, ft_newlst(ft_strdup(*stock)));
}

t_list	*ft_list_init(char *map)
{
	t_list	*first;
	char	*stock;
	int		var[3];

	first = NULL;
	stock = NULL;
	ft_set_var(var, map);
	if (var[1] < 1)
		ft_error("fd", 0, NULL);
	ft_skip_empty_line(var, &stock);
	while (var[0] > 0)
	{
		ft_list_init_2(var, &stock, &first);
		free(stock);
		stock = NULL;
	}
	if (var[0] == -1)
		ft_error("gnl", var[1], NULL);
	close(var[1]);
	return (first);
}

int	ft_allok(char **map)
{
	int	tab[3];
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_bzero(tab, 12);
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
