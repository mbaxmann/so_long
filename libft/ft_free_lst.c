/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:30:42 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/16 16:32:24 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_lst(t_list *first)
{
	t_list	*stock;

	while (first)
	{
		stock = first;
		first = first->next;
		free(stock->data);
		free(stock);
	}
}
