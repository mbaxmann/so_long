/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaxmann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:33:27 by mbaxmann          #+#    #+#             */
/*   Updated: 2021/09/16 14:37:54 by mbaxmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_get_list(t_list *first, int number)
{
	t_list	*current;
	int		len;

	current = first;
	number--;
	len = ft_list_len(first);
	len--;
	while (number && len)
	{
		current = current->next;
		number--;
		len--;
	}
	return (current);
}
