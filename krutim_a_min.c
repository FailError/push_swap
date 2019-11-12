/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   krutim_a&&min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:17:24 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/04 20:17:39 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	krutim_a1(t_stack *all, t_sp *kra, const int *a)
{
	kra->tmpasize = all->asize;
	kra->counter = kra->minpos;
	kra->tmp = kra->counter;
	while (kra->tmpasize - kra->tmp > 0)
	{
		if (a[kra->counter] > kra->min && a[kra->counter] < kra->chislo)
		{
			kra->min = a[kra->counter];
			kra->minpos = kra->counter;
			kra->counter++;
		}
		else
			kra->counter++;
		kra->tmpasize--;
	}
}

static void	krutim_a2(t_stack *all, t_sp *kra, int *a)
{
	if (kra->minpos > all->mediana)
	{
		all->skolkonaverx = (all->asize - 1) - kra->minpos + 1;
		while (all->skolkonaverx != 0)
		{
			ft_ra(a, all);
			all->skolkonaverx--;
		}
	}
	else
	{
		all->skolkovniz = kra->minpos;
		while (all->skolkovniz != 0)
		{
			ft_rra(a, all);
			all->skolkovniz--;
		}
	}
}

void		ft_krutim_a(int *a, const int *b, t_stack *all, int pos)
{
	t_sp	kra;

	kra.tmpasize = all->asize;
	kra.min = 0;
	kra.minpos = 0;
	all->mediana = all->asize / 2;
	kra.i = 0;
	if (pos == -1)
		pos = all->bsize - 1;
	kra.chislo = b[pos];
	while (kra.tmpasize > 0)
	{
		if (a[kra.i] < kra.chislo)
		{
			kra.min = a[kra.i];
			kra.minpos = kra.i;
			break ;
		}
		else
			kra.i++;
		kra.tmpasize--;
	}
	krutim_a1(all, &kra, a);
	krutim_a2(all, &kra, a);
}

int			ft_minimal(int *count, t_stack *all)
{
	int		tmpbsize;
	int		min;
	int		pos;

	tmpbsize = all->bsize;
	min = count[tmpbsize - 1];
	pos = tmpbsize - 1;
	while (tmpbsize > 0)
	{
		if (count[tmpbsize - 1] < min)
		{
			min = count[tmpbsize - 1];
			pos = tmpbsize - 1;
		}
		tmpbsize--;
	}
	free(count);
	return (pos);
}

int			ft_minimal1(const int *a, t_stack *all)
{
	int		tmpasize;
	int		i;

	tmpasize = all->asize;
	i = 0;
	while (tmpasize > 0)
	{
		if (a[i] != all->min)
		{
			i++;
			tmpasize--;
		}
		else
			return (i);
	}
	return (i);
}
