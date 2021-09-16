/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:13:47 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/16 15:45:33 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

int	main(int ac, char **av);
void	ft_error(char *str);
char	**ft_init(char **av);
void	ft_check_ext(char *str);
void	ft_check_map(char **map);
int	ft_valide_c(char c);
t_list	*ft_list_init(char *map);
char	**ft_fillmap(char *map);

#endif
