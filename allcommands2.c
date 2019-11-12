/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allcommands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:17:05 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/02 22:47:37 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int		ft_ra(int *a, t_stack *all)
{
	int	tmpasize;

	if (all->asize < 2)
	{
		all->current = "ra";
		return (0);
	}
	tmpasize = all->asize;
	while (tmpasize > 1)
	{
		ft_swap(a + tmpasize - 1, a + tmpasize - 2);
		tmpasize--;
	}
	!(all->ch) ? write(1, "ra\n", 3) : 0;
	all->re++;
	all->current = "ra";
	return (0);
}

int		ft_rb(int *b, t_stack *all)
{
	int	tmpasize;
	int	tmpbsize;

	if (all->bsize < 2)
	{
		all->current = "rb";
		return (0);
	}
	tmpbsize = all->bsize;
	tmpasize = all->asize;
	while (tmpbsize > 1)
	{
		ft_swap(b + tmpbsize - 1, b + tmpbsize - 2);
		tmpbsize--;
		tmpasize++;
	}
	!(all->ch) ? write(1, "rb\n", 3) : 0;
	all->re++;
	all->current = "rb";
	return (0);
}

void	ft_rr(int *a, int *b, t_stack *all)
{
	all->asize < 2 ? 0 : ft_ra(a, all);
	all->bsize < 2 ? 0 : ft_rb(b, all);
	all->current = "rr";
}

int		ft_rra(int *a, t_stack *all)
{
	int	tmpasize;
	int	i;

	if (all->asize < 2)
	{
		all->current = "rra";
		return (0);
	}
	tmpasize = all->asize;
	i = 0;
	while (tmpasize > 1)
	{
		ft_swap(a + i, a + (i + 1));
		tmpasize--;
		i++;
	}
	!(all->ch) ? write(1, "rra\n", 4) : 0;
	all->re++;
	all->current = "rra";
	return (0);
}

int		ft_rrb(int *b, t_stack *all)
{
	int	tmpbsize;
	int	i;

	if (all->bsize < 2)
	{
		all->current = "rrb";
		return (0);
	}
	tmpbsize = all->bsize;
	i = 0;
	while (tmpbsize > 1)
	{
		ft_swap(b + i, b + (i + 1));
		tmpbsize--;
		i++;
	}
	!(all->ch) ? write(1, "rrb\n", 4) : 0;
	all->re++;
	all->current = "rrb";
	return (0);
}
