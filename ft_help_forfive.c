#include "ft_pushswap.h"

void 					ft_helpfive(int *a, int *b, t_stack *all, t_five *f)
{
	if(b[0] < a[0] && b[0] < a[1] && b[0] < a[2] && b[0] < a[3])
	{
		int j = 1;
		f->newmin = a[0];
		while(f->tmpasize - 1 > f->i)
		{
			if(a[j] < f->newmin && a[j] > f->min)
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
	if(f->pos > 0)
	{
		while(f->pos != 3)
		{
			ft_ra(a, all);
			f->pos++;
		}
	}
	else
	{
		while(f->pos != -1)
		{
			ft_rra(a, all);
			f->pos--;
		}
	}
	ft_pa(a, b, all);
	exit(0);
}
