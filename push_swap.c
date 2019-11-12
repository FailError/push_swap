/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 20:10:18 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/08 19:29:28 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_push_v_b(t_stack *all, int *a, int *b)
{
	int tmpasize;

	tmpasize = all->asize;
	while (tmpasize - 2 > 0)
	{
		if (a[tmpasize - 1] != all->min && a[tmpasize - 1] != all->max)
		{
			ft_pb(a, b, all);
			if (b[all->bsize - 1] >= all->mediana)
			{
				ft_rb(b, all);
				all->countmin++;
			}
			tmpasize--;
		}
		else
			ft_ra(a, all);
	}
}

void		ft_command(int *a, int *b, t_stack *all)
{
	int		*tmp;
	int		p;

	p = 0;
	tmp = (int *)malloc(sizeof(int) * all->asize);
	while (p < all->asize)
	{
		tmp[p] = a[p];
		p++;
	}
	qs(tmp, 0, all->asize - 1);
	ft_doubleint(tmp, all);
	all->min = tmp[0];
	all->max = tmp[all->asize - 1];
	all->mediana = tmp[all->asize / 2];
	ft_push_v_b(all, a, b);
	*(a + 1) > *(a + 0) ? 0 : ft_sa(a, all);
	ft_algorithm(a, b, all, tmp);
}

void		ft_argctwo(int **a, char *s, t_stack *all)
{
	if (*s == ' ' || s[ft_strlen(s) - 1] == ' ')
	{
		ft_putstr("\x1B[31mError\033[0m\n");
		exit(0);
	}
	*a = ft_split(s, all);
	!(all->ch) ? ft_ifsorted(*a, all) : 0;
}

int			*ft_argcovertwo(int *a, t_stack *all, int argc, char **argv)
{
	int		j;
	int		gv;
	int		*aa;

	all->v ? argc -= 1 : 0;
	gv = all->v ? 2 : 1;
	if (all->v)
		aa = (int *)malloc(sizeof(int) * argc - 2);
	else
		aa = (int *)malloc(sizeof(int) * argc - 1);
	all->asize = argc - 1;
	j = all->asize;
	while (argc > 1)
	{
		aa[j - 1] = ft_atoi(argv[gv]);
		j--;
		gv++;
		argc--;
	}
	a = aa;
	!(all->ch) ? ft_ifsorted(a, all) : 0;
	return (a);
}

void		ft_for235(int *a, int *b, t_stack *all)
{
	ft_doubleint(a, all);
	if (all->asize == 2 && a[1] > a[0])
	{
		ft_ra(a, all);
		exit(0);
	}
	all->asize == 3 ? ft_forthree(a, all) : 0;
	all->asize == 5 ? ft_forfive(a, b, all) : 0;
}
