/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:52:36 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/09 22:29:07 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	gnl_print1(int *a, int *b, t_stack *all)
{
	if (ft_strnequ(all->s, "pa", 3))
	{
		ft_pa(a, b, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "pb", 3))
	{
		ft_pb(a, b, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "sa", 3))
	{
		ft_sa(a, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "sb", 3))
	{
		ft_sb(b, all);
		all->v ? printstack(a, b, all) : 0;
	}
}

static void	gnl_print2(int *a, int *b, t_stack *all)
{
	if (ft_strnequ(all->s, "ss", 3))
	{
		ft_ss(a, b, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "ra", 3))
	{
		ft_ra(a, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "rb", 3))
	{
		ft_rb(b, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "rr", 3))
	{
		ft_rr(a, b, all);
		all->v ? printstack(a, b, all) : 0;
	}
}

static void	gnl_print3(int *a, int *b, t_stack *all)
{
	if (ft_strnequ(all->s, "rra", 4))
	{
		ft_rra(a, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "rrb", 4))
	{
		ft_rrb(b, all);
		all->v ? printstack(a, b, all) : 0;
	}
	else if (ft_strnequ(all->s, "rrr", 4))
	{
		ft_rrr(a, b, all);
		all->v ? printstack(a, b, all) : 0;
	}
}

static void	gnl_all(int *a, int *b, t_stack *all)
{
	if (ft_strequ(all->s, "pa") || ft_strequ(all->s, "pb") ||
		ft_strequ(all->s, "sa") || ft_strequ(all->s, "sb"))
		gnl_print1(a, b, all);
	else if (ft_strequ(all->s, "ss") || ft_strequ(all->s, "ra") ||
		ft_strequ(all->s, "rb") || ft_strequ(all->s, "rr"))
		gnl_print2(a, b, all);
	else if (ft_strequ(all->s, "rra") || ft_strequ(all->s, "rrb") ||
		ft_strequ(all->s, "rrr"))
		gnl_print3(a, b, all);
	else
	{
		ft_putstr("\x1B[31mError\033[0m\n");
		exit(0);
	}
	free(all->s);
}

int			main(int argc, char **argv)
{
	int		*a;
	int		*b;
	t_stack all;

	a = NULL;
	ft_bzero(&all, sizeof(t_stack));
	all.ch = 1;
	if (argc == 1)
		exit(0);
	if (ft_strnequ(argv[1], VISUAL, 2))
		if_visual(argc, argv, &a, &all);
	else if (argc == 2)
		novis_argc2(argv, &all, &a);
	else if (argc > 2)
		a = ft_argcovertwo(a, &all, argc, argv);
	ft_doubleint(a, &all);
	b = (int *)malloc(sizeof(int) * all.asize);
	while (get_next_line(0, &all.s) == 1)
		gnl_all(a, b, &all);
	ft_ifsorted1(a, &all);
}
