/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forfive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 23:17:49 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/09 21:13:43 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	fv1(int *a, int *b, t_stack *all, t_five *fff)
{
	ft_forthree(a, all);
	if (a[0] < b[1])
		ft_pa(a, b, all);
	else if (a[1] < b[1])
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
	else if (a[2] < b[1])
	{
		ft_ra(a, all);
		ft_pa(a, b, all);
	}
	else
		ft_pa(a, b, all);
	fff->min = b[0];
	fff->tmpasize = all->asize;///важно!!!
	if(b[0] < a[0] && b[0] < a[1] && b[0] < a[2] && b[0] < a[3])
		ft_helpfive(a, b, all, fff);
}

static void	fv2(const int *a, t_stack *all, t_five *fff)
{
	while (fff->tmpasize > fff->i)
	{
		if (a[fff->i] < fff->min)
		{
			fff->newmin = a[fff->i];
			fff->pos = fff->i;
			break ;
		}
		else
			fff->i++;
		fff->tmpasize -= 1;
	}
	fff->i = fff->pos;
	fff->tmpasize = all->asize;
	while (fff->tmpasize > fff->i)
	{
		if (a[fff->i] < fff->min && a[fff->i] > fff->newmin)
		{
			fff->newmin = a[fff->i];
			fff->pos = fff->i;
			fff->i++;
		}
		else
			fff->i++;
	}
}

static void	fv3(int *a, int *b, t_stack *all, t_five *fff)
{
	if (fff->pos == 3)
		ft_ra(a, all);
	else
	{
		while (fff->pos != 0)
		{
			ft_rra(a, all);
			fff->pos--;
		}
	}
	ft_pa(a, b, all);
	fff->i = 0;
	fff->min = a[fff->i];
	fff->pos = 0;
	fff->tmpasize = all->asize;
	while (fff->tmpasize-- > fff->i)
	{
		if (a[fff->i++ + 1] < fff->min)
		{
			fff->min = a[fff->i];
			fff->pos = fff->i;
		}
		else
			fff->i++;
	}
}

static void	fv4(int *a, t_stack *all, t_five *fff)
{
	if (fff->pos >= 2)
	{
		while (fff->pos != 4)
		{
			ft_ra(a, all);
			fff->pos++;
		}
	}
	else
	{
		while (fff->pos != -1)
		{
			ft_rra(a, all);
			fff->pos--;
		}
	}
}

void		ft_forfive(int *a, int *b, t_stack *all)
{
	t_five	fff;

	fff.pos = 0;
	fff.i = 0;
	fff.newmin = 0;
	fff.tmpasize = all->asize;
	ft_pb(a, b, all);
	ft_pb(a, b, all);
	fv1(a, b, all, &fff);
	fv2(a, all, &fff);
	fv3(a, b, all, &fff);
	fv4(a, all, &fff);
	exit(0);
}
