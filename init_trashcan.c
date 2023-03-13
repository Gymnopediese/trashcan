/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_trashcan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:37:09 by albaud            #+#    #+#             */
/*   Updated: 2023/03/13 21:03:54 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trashcan.h"

t_gb	*trashcan(void)
{
	static t_gb	gb[1];
	static int	init = 0;

	if (init == 0 && ++init)
		*gb = (t_gb){0, 0, 0, "trashcan"};
	return (gb);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	exit_trashcan(int error, char *text)
{
	t_nn	*node;
	t_nn	*next;

	node = trashcan()->head;
	while (node)
	{
		next = node->next;
		free(node->data);
		free(node);
		node = next;
	}
	if (text)
	{
		ft_putstr_fd(trashcan()->name, error + 1);
		ft_putstr_fd(":", error + 1);
		ft_putstr_fd(text, error + 1);
	}
	exit(error);
}

void	add_pointer(void *p)
{
	t_gb	*gb;
	t_nn	*node;

	node = malloc(sizeof(t_nn));
	if (p == 0 || node == 0)
		exit_trashcan(1, "null pointer returned by malloc");
	gb = trashcan();
	node->data = p;
	node->next = 0;
	if (gb->head == 0)
	{
		gb->head = node;
		gb->tail = node;
	}
	else
	{
		gb->tail->next = node;
		gb->tail = node;
	}
	gb->size += 1;
}
