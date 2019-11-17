/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worked_from_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:15:16 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/17 15:02:49 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_rrr(int *a, int *b, t_stack *all)
{
	all->asize < 2 ? 0 : ft_rra(a, all);
	all->bsize < 2 ? 0 : ft_rrb(b, all);
	all->current = "rrr";
}

int		ft_ifsorted(const int *a, t_stack *all)
{
	int	tmpasize;
	int	i;
	int	tmp;

	if (all->asize == 1)
		exit(0);
	tmpasize = all->asize;
	i = tmpasize - 2;
	tmp = a[tmpasize - 1];
	while (a[i] > tmp)
	{
		if (i == 0)
		{
			all->ch ? ft_printf("OK\n") : 0;
			exit(0);
		}
		tmp = a[i];
		i--;
		tmpasize--;
	}
	return (0);
}

void	ft_doubleint(const int *tmp, t_stack *all)
{
	int	tmpasize;
	int	i;
	int	t;

	tmpasize = all->asize;
	i = 0;
	t = 1;
	while (tmpasize > i + 1)
	{
		while (tmpasize > i + 1)
		{
			if (tmp[i] == tmp[t])
			{
				ft_putstr("\x1B[31mError\033[0m\n");
				exit(0);
			}
			t++;
			tmpasize--;
		}
		i++;
		t = i + 1;
		tmpasize = all->asize;
	}
}

int		ft_forthree(int *a, t_stack *all)
{
	if (a[2] > a[1] && a[2] < a[0])
		ft_sa(a, all);
	else if (a[2] > a[1] && a[1] > a[0])
	{
		ft_sa(a, all);
		ft_rra(a, all);
	}
	else if (a[2] > a[1] && a[1] < a[0] && a[0] < a[2])
		ft_ra(a, all);
	else if (a[2] < a[1] && a[2] < a[0] && a[0] < a[1])
	{
		ft_sa(a, all);
		ft_ra(a, all);
	}
	else if (a[2] < a[1] && a[2] > a[0])
		ft_rra(a, all);
	if (all->asize == 3 && !(all->bsize))
		exit(0);
	else
		return (0);
}
