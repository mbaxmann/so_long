/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:13:47 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/19 17:14:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define UP 122
# define DOWN 115
# define RIGHT 100
# define LEFT 113
# define ESC 65307

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

typedef struct  s_dim
{
        int	x;
        int	y;
}               t_dim;

typedef struct	s_img
{
	int			bpp;
	int			line;
	int			endian;
	int			height;
	int			width;
	void		*img;
	char		*pt;
}		t_img;


typedef struct	s_textur
{
	void		*img;
	char		*addr;
	int			height;
	int			width;
}				t_textur;

typedef struct	s_data
{
	t_mlx		*mlx;
	t_img		**img;
	t_textur	**textur;
	int		count;
	char		**map;
}		t_data;

int	main(int ac, char **av);
void	ft_error(char *str, int fd, char **map);
char	**ft_init(char **av);
void	ft_check_ext(char *str);
void	ft_check_map(char **map);
int	ft_valide_c(char c);
t_list	*ft_list_init(char *map);
char	**ft_fillmap(char *map);
int	ft_lineiswall(char *line);
int	ft_mapisclose(char **map);
int	ft_mapis_rectangular(char **map);
int	ft_allok(char **map);
t_mlx	*ft_open_window(char **map);
void	ft_engine(char **map);
int	ft_loop(t_data *data);
void	ft_event(t_data *data);

#endif
