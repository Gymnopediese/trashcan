/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 00:30:53 by albaud            #+#    #+#             */
/*   Updated: 2023/03/13 21:04:11 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trashcan.h"

#include <stdio.h>

int	main(void)
{
	void	*vo;
	int		*ch;
	char	*in;
	void	*random = 0;

	printf("start test\n");
	vo = allok(10, sizeof(void *));
	in = allok(10, sizeof(int));
	ch = allok(10, sizeof(char));
	printf("FREEING POINTERS:\n");
	printf("before free:\t%p %p %p\n", vo, ch, in);
	printf("freek them:\t%i %i %i\n",
		freek((void *)vo), freek((void *)ch), freek((void *)in));
	printf("after free:\t%p %p %p\n", vo, ch, in);

	vo = allok(10, sizeof(void *));
	in = allok(10, sizeof(int));
	ch = allok(10, sizeof(char));
	printf("before free:\t%p %p %p\n", vo, ch, in);
	printf("freeko them:\t%i %i %i\n",
		freeko((void **)&vo), freeko((void **)&ch), freeko((void **)&in));
	printf("after free:\t%p %p %p\n", vo, ch, in);
	vo = allok(10, sizeof(void *));
	in = allok(10, sizeof(int));
	ch = allok(10, sizeof(char));
	printf("FREEING RANDOM (NON EMPTY GB):\n");
	printf("freek random:\t%i %i %i\n",
		freek((void *)random), freek((void *)999), freek((void *)0));
	printf("freeko random:\t%i %i %i\n",
		freek((void **)&random), freek((void **)999), freek((void **)0));
	printf("freeko them:\t%i %i %i\n",
		freeko((void **)&vo), freeko((void **)&ch), freeko((void **)&in));
	printf("FREEING RANDOM (EMPTY GB):\n");
	printf("freek random:\t%i %i %i\n",
		freek((void *)random), freek((void *)999), freek((void *)0));
	vo = allok(10, sizeof(void *));
	in = allok(10, sizeof(int));
	ch = allok(10, sizeof(char));
	printf("FREEING MIXED (EMPTY GB):\n");
	printf("freek mixed:\t%i %i %i\n",
		freek((void *)random), freek((void *)vo), freek((void *)0));
	printf("freeko mixed:\t%i %i %i\n",
		freeko((void **)&ch), freeko((void **)0), freeko((void **)&in));
}
