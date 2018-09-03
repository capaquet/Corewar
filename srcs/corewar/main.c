/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:58:08 by lbelda            #+#    #+#             */
/*   Updated: 2018/06/28 18:04:13 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "visu.h"

/*
**	Initialisation de l'arene qui va comporter les instructions de chaque
**	programme et sur laquelle va se jouer la partie
*/

t_arena	g_arena[MEM_SIZE];

/*
**	Controle des parametres et de la validite des define dans op.h
*/

static void		ft_basic_control(int argc)
{
	int		size_magic_nbr;

	size_magic_nbr = 0;
	if (argc <= 1)
		ft_error_usage("Too few parameters\n");
	else if (argc - 1 > MAX_ARGS_NUMBER)
		ft_error_usage("Too many parameters\n");
	while (COREWAR_EXEC_MAGIC >> (size_magic_nbr * 8))
		size_magic_nbr++;
	if (size_magic_nbr > 4)
		ft_error(0, "Error: Magic number > uint_max", 0, 0);
	if (sizeof(REG_SIZE) > 4)
		ft_error(0, "Error: REG_SIZE > uint_max", 0, 0);
	if (REG_SIZE < 0)
		ft_error(0, "Error: ", 0, 0);
}

static int		ft_get_flags(int argc, char **argv, t_data *f, int i)
{
	while (i < argc && ft_is_valid_flag(argv[i]))
	{
		if (ft_strequ("-dump", argv[i]))
		{
			if (f->dump_val)
				ft_error_usage("Error : wrong flag usage");
			if (ft_isnumber(argv[i + 1]))
			{
				if ((f->dump_val = ft_atoi(argv[++i])) <= 0)
					ft_error_usage(
							"Error : You must dump memory at a valid value");
			}
			else
				ft_error_usage(
						"Error : Dump must be followed by a valid number");
		}
		if (ft_strequ("-p", argv[i]))
			f->flag_p++;
		if (ft_strequ("-v", argv[i++]))
			f->flag_v++;
		if ((f->flag_v && f->dump_val) || f->flag_v > 1 || f->flag_p > 1)
			ft_error_usage("Error : wrong flag usage");
	}
	return (i);
}

static t_data	ft_init_data(int argc, char **argv, int i)
{
	t_data	d;

	ft_bzero(&d, sizeof(t_data));
	d.end_flag = ft_get_flags(argc, argv, &d, i);
	ft_players(&d, argv, argc);
	ft_process(&d);
	d.cy = 1;
	d.cyc_tot = 1;
	d.ctd = CYCLE_TO_DIE;
	d.number = 1;
	d.check = 0;
	if ((d.flag_v && MAX_PLAYERS > 4) ||
		(d.flag_v && !ft_verif_mem_size(MEM_SIZE)))
		d.flag_v = 0;
	return (d);
}

int				main(int argc, char **argv)
{
	t_data	data;
	t_visu	*visu;

	ft_control_define();
	ft_basic_control(argc);
	ft_init_func_tab();
	data = ft_init_data(argc, argv, 1);
	if (data.flag_p)
		ft_print_player(data.players_list);
	ft_print_game(&(data.players_list));
	visu = init_visu(&data);
	ft_game(&data, visu);
	ft_free_visu(visu, data);
	ft_free_data(&data);
	return (0);
}
