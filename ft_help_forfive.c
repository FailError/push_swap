/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_forfive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:14:37 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/16 22:28:20 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		ft_from_fv1(int *a, int *b, t_stack *all)
{
	if (a[2] > a[1] && a[2] < b[1])
	{
		ft_ra(a, all);
		ft_pa(a, b, all);
	}
	else
	{
		ft_rra(a, all);
		ft_pa(a, b, all);
	}
}

static void	ft_pos_five(t_five *f, t_stack *all, int *a)
{
	if (f->pos > 0)
	{
		while (f->pos != 3)
		{
			ft_ra(a, all);
			f->pos++;
		}
	}
	else
	{
		while (f->pos != -1)
		{
			ft_rra(a, all);
			f->pos--;
		}
	}
}

void		ft_helpfive(int *a, int *b, t_stack *all, t_five *f)
{
	int j;

	if (b[0] < a[0] && b[0] < a[1] && b[0] < a[2] && b[0] < a[3])
	{
		j = 1;
		f->newmin = a[0];
		while (f->tmpasize - 1 > f->i)
		{
			if (a[j] < f->newmin && a[j] > f->min)
			{
				f->newmin = a[j];
				f->pos = j;
				j++;
				f->tmpasize--;
			}
			else
			{
				f->tmpasize--;
				j++;
			}
		}
	}
	ft_pos_five(f, all, a);
	ft_pa(a, b, all);
	exit(0);
}
