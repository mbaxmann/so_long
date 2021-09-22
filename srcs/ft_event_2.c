/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:15:55 by user42            #+#    #+#             */
/*   Updated: 2021/09/22 11:24:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_is_win(t_data *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
			if (data->map[i][j++] == 'C')
				c++;
		j = 0;
		i++;
	}
	if (!c)
	{
		data->count++;
		printf("%d\n", data->count);
		ft_free_data(data);
		exit(0);
	}
}
