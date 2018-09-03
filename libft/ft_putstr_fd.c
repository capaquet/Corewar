/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:15:58 by achirat           #+#    #+#             */
/*   Updated: 2017/11/17 14:04:43 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (*s != '\0')
	{
		write(fd, &*s, 1);
		s++;
	}
}