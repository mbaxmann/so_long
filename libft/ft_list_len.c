/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:32:49 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/16 17:15:44 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_len(t_list *first)
{
	t_list	*current;
	int		count;

	count = 0;
	if (first)
		count++;
	current = first;
	while (current && current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
