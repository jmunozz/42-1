/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubarbie <jubarbie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 09:04:02 by jubarbie          #+#    #+#             */
/*   Updated: 2015/10/21 11:25:42 by jubarbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_getlen(char *str)
{
	int n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

void	ft_swap_cells(char *c1, char *c2)
{
	char temp;

	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	int	size;
	int stop;

	size = ft_getlen(str);
	i = 0;
	j = size - 1;
	stop = ((size / 2) - 1);
	while (i <= stop)
		ft_swap_cells(&str[i++], &str[j--]);
	return (str);
}
