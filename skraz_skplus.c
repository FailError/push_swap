/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skraz_skplus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:24:35 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/04 20:29:33 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_skokplus1(const int *a, const int *b, t_stack *all, t_sp *plus)
{
	plus->chislo = b[plus->tmpbsize - 1];
	plus->i = 0;
	plus->tmpasize = all->asize;
	while (plus->tmpasize > 0)
	{
		if (a[plus->i] < plus->chislo)
		{
			plus->min = a[plus->i];
			plus->minpos = plus->i;
			break ;
		}
		else
			plus->i++;
		plus->tmpasize--;
	}
	plus->tmpasize = all->asize;
	plus->counter = plus->minpos;
	plus->tmp = plus->counter;
}

static void	ft_skokplus2(int *count, t_sp *plus, t_stack *all)
{
	if (plus->minpos > all->mediana)
	{
		all->skolkonaverx = (all->asize - 1) - plus->minpos + 1;
		count[plus->tmpbsize - 1] += all->skolkonaverx;
	}
	else
	{
		all->skolkovniz = plus->minpos;
		count[plus->tmpbsize - 1] += all->skolkovniz;
	}
}

void		ft_skolkoplusuem(const int *a, const int *b, t_stack *all,
			int *count)
{
	t_sp	plus;

	plus.min = 0;
	plus.minpos = 0;
	all->mediana = all->asize / 2;
	plus.tmpbsize = all->bsize;
	while (plus.tmpbsize > 0)
	{
		ft_skokplus1(a, b, all, &plus);
		while (plus.tmpasize - plus.tmp > 0)
		{
			if (a[plus.counter] > plus.min && a[plus.counter] < plus.chislo)
			{
				plus.min = a[plus.counter];
				plus.minpos = plus.counter;
				plus.counter++;
			}
			else
				plus.counter++;
			plus.tmpasize--;
		}
		ft_skokplus2(count, &plus, all);
		plus.tmpbsize--;
	}
}

static void	skolkoraz1(int *count, int *tmpbsize, t_stack *all, int *i)
{
	*i = 0;
	while (*tmpbsize > 0)
	{
		count[*tmpbsize - 1] = *i;
		*tmpbsize -= 1;
		*i += 1;
		all->mediana--;
		if (all->mediana == -1)
			break ;
	}
	*i = 0;
	while (*tmpbsize > 0)
	{
		count[*i] = *i + 1;
		*i += 1;
		*tmpbsize -= 1;
	}
}

int			*ft_skolkoraz(t_stack *all)
{
	int		tmpbsize;
	int		i;
	int		*count;

	tmpbsize = all->bsize;
	count = (int *)malloc(sizeof(int ) * all->bsize);
	ft_bzero(count, all->bsize);
	all->mediana = all->bsize / 2;
	while (tmpbsize > 0)
		skolkoraz1(count, &tmpbsize, all, &i);
	return (count);
}
