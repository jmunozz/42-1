/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 08:46:58 by jubarbie          #+#    #+#             */
/*   Updated: 2015/11/05 16:31:57 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_cells(int *cel1, int *cel2)
{
	int	temp;

	temp = *cel1;
	*cel1 = *cel2;
	*cel2 = temp;
}

void	ft_sort_integer_table(int *tab, int size)
{
	if (size > 2)
		ft_sort_integer_table(tab, size - 1);
	while (size > 1)
	{
		if (tab[size - 2] > tab[size - 1])
			ft_swap_cells(&tab[size - 1], &tab[size - 2]);
		size--;
	}
}
