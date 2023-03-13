/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:00:51 by albaud            #+#    #+#             */
/*   Updated: 2023/03/13 21:04:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASHCAN_H

# define TRASHCAN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_n
{
	void		*data;
	struct s_n	*next;
}	t_nn;

typedef struct s_gb
{
	t_nn	*head;
	t_nn	*tail;
	int		size;
	char	*name;
}	t_gb;

int		freek(void *to_freek);
int		freeko(void **to_freek);
void	*allok(int amount, int size);
void	exit_trashcan(int error, char *text);
t_gb	*trashcan(void);
void	add_pointer(void *p);

#endif