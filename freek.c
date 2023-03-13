/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freek.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:54:16 by albaud            #+#    #+#             */
/*   Updated: 2023/03/13 20:56:57 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trashcan.h"

int	free_node(t_nn *node)
{
	free(node->data);
	free(node);
	return (1);
}

int	freek(void *to_freek)
{
	t_nn	*node;
	t_nn	*next;

	node = trashcan()->head;
	if (to_freek == 0 || node == 0)
		return (0);
	if (node->data == to_freek)
	{
		trashcan()->head = node->next;
		return (free_node(node));
	}
	while (node->next)
	{
		if (node->next->data == to_freek)
		{
			next = node->next;
			node->next = next->next;
			return (free_node(next));
		}
		node = node->next;
	}
	return (0);
}

int	freeko(void **to_freek)
{
	t_nn	*node;
	t_nn	*next;

	node = trashcan()->head;
	if (to_freek == 0 || *to_freek == 0 || node == 0)
		return (0);
	if (node->data == *to_freek)
	{
		trashcan()->head = node->next;
		*to_freek = 0;
		return (free_node(node));
	}
	while (node->next)
	{
		if (node->next->data == *to_freek)
		{
			next = node->next;
			node->next = next->next;
			*to_freek = 0;
			return (free_node(next));
		}
		node = node->next;
	}
	return (0);
}
