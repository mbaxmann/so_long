/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:32:24 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/16 15:52:10 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_list(t_list *first, t_list *to_add)
{
	t_list	*current;

	current = first;
	if (first != to_add)
	{
		if (first)
		{
			while (current->next != NULL)
				current = current->next;
			current->next = to_add;
		}
		else
			first = to_add;
	}
}
