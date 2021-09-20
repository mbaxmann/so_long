/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:06:11 by user42            #+#    #+#             */
/*   Updated: 2021/09/20 17:10:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_limity(t_img *img, char *offset)
{
	int	tmp;

	tmp = offset - img->pt;
	tmp += img->line;
	if (tmp > img->line * img->height)
		return (1);
	return (0);
}

char	*ft_setup_offset(t_img *img, t_dim coord, t_dim squar)
{
	char	*offset;

	offset = img->pt + (coord.y * img->line * squar.y)
		+ (coord.x * 4 * squar.x);
	return (offset);
}

void	ft_put_textur(t_img *img, t_dim coord, t_dim squar, t_textur *textur)
{
	int				i;
	int				j;
	unsigned int	pixel;
	t_dim			ratio;
	char			*offset;

	i = -1;
	j = -1;
	offset = ft_setup_offset(img, coord, squar);
	while (++i < squar.y && !ft_limity(img, offset))
	{
		ratio.y = (i * textur->height) / squar.y;
		while (++j < squar.x && !ft_limitx(img, offset, j))
		{
			ratio.x = (j * textur->height) / squar.x;
			offset += j * 4;
			pixel = *((unsigned int *)(textur->addr
						+ (ratio.y * textur->height * 4) + (4 * ratio.x)));
			if (pixel)
				*(unsigned int *)offset = pixel;
			offset -= j * 4;
		}
		j = -1;
		offset += img->line;
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
	double	i;
	int		j;

	i = (double)big / (double)small;
	j = big / small;
	if (i != j)
	{
		return (j + 1);
	}
	else
		return (j);
}
