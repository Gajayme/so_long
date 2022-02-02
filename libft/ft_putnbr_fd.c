/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:47 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:54:48 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ptnbr_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	l;

	if (n == 0)
		write(fd, "0", 1);
	if (!n)
		return ;
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	else if (n < 0)
		write(fd, "-", 1);
	l = ptnbr_abs(n % 10) + '0';
	write(fd, &l, 1);
}
