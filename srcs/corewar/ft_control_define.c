/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_define.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:52:49 by cpaquet           #+#    #+#             */
/*   Updated: 2018/06/28 18:15:48 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

/*
**	Controle des DEFINE contenu dans le op.h et definissant les regles du jeu
*/

void		ft_control_define(void)
{
	if (IND_SIZE <= 0 || REG_SIZE <= 0 || MAX_PLAYERS <= 0
		|| MEM_SIZE <= 23 || REG_CODE <= 0 || DIR_CODE <= 0 || IND_CODE <= 0
		|| MAX_ARGS_NUMBER <= 0 || IDX_MOD <= 0
		|| CHAMP_MAX_SIZE <= 0 || REG_NUMBER <= 1 || CYCLE_TO_DIE <= 0
		|| NBR_LIVE <= 0 || MAX_CHECKS <= 0 || OP_NBR <= 0 || T_REG <= 0
		|| T_DIR <= 0 || T_IND <= 0 || T_LAB <= 0)
	{
		ft_putstr_fd("Wrong define in op.h", 2);
		exit(1);
	}
}

int			ft_verif_mem_size(int mem_size)
{
	int		i;

	i = -1;
	while (++i < mem_size / 2)
	{
		if (i * i == mem_size)
			return (1);
		else if (i * i > mem_size)
			return (0);
	}
	return (0);
}

void		ft_check_cor(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len < 4)
		ft_error(2, str, 0, 0);
	if (str[len - 1] != 'r' || str[len - 2] != 'o' || str[len - 3] != 'c'
		|| str[len - 4] != '.')
		ft_error(2, str, 0, 0);
}
