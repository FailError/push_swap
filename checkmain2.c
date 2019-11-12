/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmain2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:00:41 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/08 19:29:28 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	if_visual(int argc, char **argv, int **a, t_stack *all)
{
	all->v = 1;
	if (argc == 2)
		exit(0);
	if (argc == 3)
	{
		all->s = argv[2];
		*all->s == '\0' ? exit(0) : 0;
		ft_argctwo(a, all->s, all);
	}
	if (argc > 3)
		*a = ft_argcovertwo(*a, all, argc, argv);
}

void	novis_argc2(char **argv, t_stack *all, int **a)
{
	all->s = argv[1];
	*all->s == '\0' ? exit(0) : 0;
	ft_strlen(all->s) == 1 && *all->s == '-' ?
	ft_putstr("\x1B[31mError\033[0m\n") : 0;
	ft_argctwo(a, all->s, all);
}
