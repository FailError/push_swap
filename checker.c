/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:11:49 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/09 22:15:57 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static void	ft_ifsort1(t_stack *all)
{
	if ((all->asize == 0 || all->asize == 1) && all->bsize == 0)
	{
		ft_putstr("\033[32mOK ✅\033[0m\n");
		exit(0);
	}
	if (all->bsize != 0)
	{
		ft_putstr("\x1B[31mKO ❌\033[0m\n");
		ft_printf("Total steps: %d\n", all->re);
		exit(0);
	}
}

int			ft_ifsorted1(const int *a, t_stack *all)
{
	int		i;
	int		tmp;

	ft_ifsort1(all);
	i = all->asize - 2;
	tmp = a[all->asize - 1];
	while (a[i] > tmp)
	{
		if (i == 0)
		{
			ft_putstr("\033[32mOK ✅\033[0m\n");
			ft_printf("Total steps: %d\n", all->re);
			exit(0);
		}
		tmp = a[i];
		i--;
	}
	ft_putstr("\x1B[31mKO ❌\033[0m\n");
	ft_printf("Total steps: %d\n", all->re);
	exit(0);
}

static void	printstack2(t_stack *all)
{
	int		tmpasize;
	int		tmpbsize;
	int		i;

	write(1, "\n", 1);
	tmpasize = all->asize;
	tmpbsize = all->bsize;
	i = 0;
	if (tmpasize > tmpbsize)
	{
		while (tmpasize >= i)
		{
			ft_putstr("\x1B[34m▀▀▀▀▀▀\033[0m");
			tmpasize--;
		}
	}
	else
	{
		while (tmpbsize >= i)
		{
			ft_putstr("\x1B[34m▀▀▀▀▀▀\033[0m");
			tmpbsize--;
		}
	}
	write(1, "\n", 1);
}

void		printstack(int *a, int *b, t_stack *all)
{
	int		tmpasize;
	int		tmpbsize;
	int		i;

	i = 0;
	tmpasize = all->asize;
	tmpbsize = all->bsize;
	ft_printf("Current command: %s\n", all->current);
	if (all->asize == 0)
		ft_putstr("\x1B[31mNULL\033[0m\n");
	ft_putstr("Stack \x1B[35mⒶ\033[0m [ ]: ");
	while (tmpasize > 0)
	{
		ft_printf("%d | ", a[tmpasize - 1]);
		tmpasize--;
	}
	ft_putstr("\nStack \x1B[36mⒷ\033[0m [ ]: ");
	if (all->bsize == 0)
		ft_putstr("\x1B[31mNULL\033[0m");
	while (tmpbsize > i)
	{
		ft_printf("%d | ", b[tmpbsize - 1]);
		tmpbsize--;
	}
	printstack2(all);
}
