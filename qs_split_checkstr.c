/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   123.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:54:17 by kbessa            #+#    #+#             */
/*   Updated: 2019/11/08 19:29:28 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static int	len(const char *len, t_stack *all)
{
	all->i = 0;
	while (*len != '\0')
	{
		if (*len == '-')
			len += 1;
		while (*len >= '0' && *len <= '9')
			len += 1;
		if (*len != '\0')
		{
			while (*len == ' ')
				len += 1;
		}
		all->i++;
	}
	return (all->i);
}

int			*ft_split(char *str, t_stack *all)
{
	char	**ss;
	int		i;
	int		j;
	int		*a;

	ss = ft_strsplit(str, ' ');
	i = len(str, all);
	j = 0;
	ft_atoi(*ss);
	all->asize = i;
	all->bsize = 0;
	a = (int *)malloc(sizeof(int) * all->i);
	while (i-- > 0)
	{
		a[i] = ft_atoi(ss[j]);
		free(ss[j]);
		j++;
	}
	free(ss);
	return (a);
}

void		ft_checkstr(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ' || (s[i] == '-' &&
			s[i + 1] != '-'))
			i++;
		else
		{
			ft_putstr("\x1B[31mError\033[0m\n");
			exit(0);
		}
	}
}

static void	ft_qs2(int *s_arr, int *tmp, int *left, int *right)
{
	*tmp = s_arr[*left];
	s_arr[*left] = s_arr[*right];
	s_arr[*right] = *tmp;
	*left += 1;
	*right -= 1;
}

void		qs(int *s_arr, int first, int last)
{
	int		tmp;
	int		left;
	int		right;
	int		middle;

	if (first < last)
	{
		left = first;
		right = last;
		middle = s_arr[(left + right) / 2];
		while (left <= right)
		{
			while (s_arr[left] < middle)
				left++;
			while (s_arr[right] > middle)
				right--;
			if (left <= right)
				ft_qs2(s_arr, &tmp, &left, &right);
		}
		qs(s_arr, first, right);
		qs(s_arr, left, last);
	}
}
