/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allcommands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:16:42 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/02 21:32:03 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_ss(int *a, int *b, t_stack *all)
{
	if (all->asize > 1)
		ft_sa(a, all);
	if (all->bsize > 1)
		ft_sb(b, all);
	all->current = "ss";
}

void	ft_sb(int *b, t_stack *all)
{
	if (all->bsize > 1)
	{
		ft_swap(&b[all->bsize - 1], &b[all->bsize - 2]);
		all->re++;
		!(all->ch) ? write(1, "sb\n", 3) : 0;
		all->current = "sb";
	}
	all->current = "sb";
}

void	ft_sa(int *a, t_stack *all)
{
	if (all->asize > 1)
	{
		ft_swap(&a[all->asize - 1], &a[all->asize - 2]);
		!(all->ch) ? write(1, "sa\n", 3) : 0;
		all->re++;
		all->current = "sa";
	}
	all->current = "sa";
}

int		ft_pa(int *a, const int *b, t_stack *all)
{
	if (all->bsize == 0)
	{
		all->current = "pa";
		return (0);
	}
	else
	{
		a[all->asize] = b[all->bsize - 1];
		all->bsize -= 1;
		all->asize += 1;
	}
	!(all->ch) ? write(1, "pa\n", 3) : 0;
	all->re++;
	all->current = "pa";
	return (0);
}

int		ft_pb(const int *a, int *b, t_stack *all)
{
	if (all->asize == 0)
	{
		all->current = "pb";
		return (0);
	}
	else
	{
		b[all->bsize] = a[all->asize - 1];
		all->asize -= 1;
		all->bsize += 1;
	}
	!(all->ch) ? write(1, "pb\n", 3) : 0;
	all->re++;
	all->current = "pb";
	return (0);
}
