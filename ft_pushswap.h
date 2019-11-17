/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:55:14 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/17 15:16:22 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <zconf.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <stdio.h>
# define VISUAL "-v"

typedef struct			s_tack
{
	char				*current;
	char				*s;
	int					i;
	int					ch;
	int					v;

	int					asize;
	int					bsize;

	int					min;
	int					max;

	int					mediana;
	int					countmin;

	int					skolkonaverx;
	int					skolkovniz;

	int					re;
}						t_stack;

typedef	struct			s_five
{
	int					tmpasize;
	int					pos;
	int					i;
	int					min;
	int					newmin;
}						t_five;

typedef	struct			s_skokplus
{
	int					tmpbsize;
	int					tmpasize;
	int					min;
	int					minpos;
	int					i;
	int					chislo;
	int					counter;
	int					tmp;
}						t_sp;

typedef	struct			s_algrithm
{
	int					tmpasize;
	int					tmpbsize;
	int					pos;
	int					mediana_a;
	int					mediana_b;
	int					*count;
}						t_algos;

void					ft_sa(int *a, t_stack *all);
void					ft_sb(int *b, t_stack *all);
void					ft_ss(int *a, int *b, t_stack *all);

int						ft_pb(const int *a, int *b, t_stack *all);
int						ft_pa(int *a, const int *b, t_stack *all);

int						ft_ra(int *a, t_stack *all);
int						ft_rb(int *b, t_stack *all);
void					ft_rr(int *a, int *b, t_stack *all);

int						ft_rra(int *a, t_stack *all);
int						ft_rrb(int *b, t_stack *all);
void					ft_rrr(int *a, int *b, t_stack *all);

void					ft_argctwo (int **a, char *s, t_stack *all);
int						*ft_argcovertwo (int *a, t_stack *all, int argc,
						char **argv);
void					ft_for235 (int *a, int *b, t_stack *all);

void					ft_command(int *a, int *b, t_stack *all);

void					qs(int *s_arr, int first, int last);

void					ft_algorithm(int *a, int *b, t_stack *all, int *tmp);

int						*ft_skolkoraz(t_stack *all);
void					ft_skolkoplusuem(const int *a, const int *b,
						t_stack *all, int *count);

int						ft_minimal(int *countm, t_stack *all);
void					ft_krutim_a(int *a, const int *b, t_stack *all,
						int pos);
int						ft_minimal1(const int *a, t_stack *all);

int						*ft_split(char *str, t_stack *all);

int						ft_ifsorted(const int *a, t_stack *all);
void					ft_checkstr(char *s);
void					ft_doubleint(const int *tmp, t_stack *all);

int						ft_forthree(int *a, t_stack *all);
void					ft_forfive(int *a, int *b, t_stack *all);
void					ft_helpfive(int *a, int *b, t_stack *all, t_five *f);
void					ft_from_fv1(int *a, int *b, t_stack *all);

int						ft_ifsorted1(const int *a, t_stack *all);
void					printstack(int *a, int *b, t_stack *all);
void					if_visual(int argc, char **argv, int **a, t_stack *all);
void					novis_argc2(char **argv, t_stack *all, int **a);

#endif
