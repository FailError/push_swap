/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:02:37 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/04 20:18:29 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_alg1(int *a, int *b, t_stack *all, t_algos *alg)
{
	alg->count = ft_skolkoraz(all);
	alg->mediana_b = all->bsize / 2;
	ft_skolkoplusuem(a, b, all, alg->count);
	alg->pos = ft_minimal(alg->count, all);
	if (alg->pos >= alg->mediana_b)
	{
		while (alg->pos != alg->tmpbsize - 1)
		{
			ft_rb(b, all);
			alg->pos++;
		}
		ft_krutim_a(a, b, all, alg->pos);
		ft_pa(a, b, all);
	}
	else
	{
		while (alg->pos != -1)
		{
			ft_rrb(b, all);
			alg->pos--;
		}
		ft_krutim_a(a, b, all, alg->pos);
		ft_pa(a, b, all);
	}
}

static void	ft_alg2(int *a, t_stack *all, t_algos *alg)
{
	if (alg->pos >= alg->mediana_a)
	{
		while (alg->pos != all->asize - 1)
		{
			ft_ra(a, all);
			alg->pos++;
		}
	}
	else
	{
		while (alg->pos != -1)
		{
			ft_rra(a, all);
			alg->pos--;
		}
	}
}

void		ft_algorithm(int *a, int *b, t_stack *all, int *tmp)
{
	t_algos	alg;

	ft_pa(a, b, all);
	alg.tmpasize = all->asize;
	alg.tmpbsize = all->bsize;
	alg.mediana_a = all->asize / 2;
	while (alg.tmpbsize > 0)
	{
		ft_alg1(a, b, all, &alg);
		alg.tmpbsize--;
		alg.tmpasize++;
	}
	alg.pos = ft_minimal1(a, all);
	alg.mediana_a = all->asize / 2;
	ft_alg2(a, all, &alg);
	free(tmp);
	free(a);
	free(b);
}
