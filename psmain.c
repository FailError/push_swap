/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:20:24 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/17 15:15:18 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int			main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	*s;
	t_stack	all;

	a = NULL;
	ft_bzero(&all, sizeof(t_stack));
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		s = argv[1];
		*s == '\0' ? exit(0) : 0;
		ft_strlen(s) == 1 && *s == '-' ? ft_putstr("\x1B[31mError\033[0m\n")
		: 0;
		ft_argctwo(&a, s, &all);
	}
	if (argc > 2)
		a = ft_argcovertwo(a, &all, argc, argv);
	b = (int *)malloc(sizeof(int) * all.asize);
	ft_for235(a, b, &all);
	ft_command(a, b, &all);
	return (0);
}
