/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achirat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:44:12 by achirat           #+#    #+#             */
/*   Updated: 2018/06/28 14:58:23 by lbelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"
#include "visu.h"

/*
**	On determine le gagnant en fonction de la variable 'last' dans le tableau
**	global rassemblant les joueurs. Elle sert a distinguer le dernier champion
**	a avoir emis un live a son nom.
*/

static void	*thrd_taunt(void *d)
{
	system(d);
	free_pro((void**)&d);
	return (NULL);
}

static void	ft_taunt(t_player *lst, int winner)
{
	char		*cmd;
	char		*tmp;
	pthread_t	taunt_thread;

	while (lst)
	{
		if (!ft_strcmp(lst->name, g_live_tab[winner].name))
			break ;
		lst = lst->next;
	}
	tmp = ft_control_comment(lst->comment);
	m_pro_null_bonus(cmd = ft_strjoin("say \'", tmp), tmp);
	free_pro((void**)&tmp);
	if (pthread_create(&taunt_thread, NULL, &thrd_taunt, (void*)cmd))
	{
		free_pro((void**)&cmd);
		error_exit("");
	}
}

static void	ft_setup_final(t_visu *v, int winner)
{
	if (winner < MAX_PLAYERS)
	{
		ft_bzero(v->scene.pl_on, sizeof(int) * MAX_PLAYERS);
		v->scene.pl_on[winner] = 1;
		v->scene.arena.winner = winner;
	}
	v->scene.events.phase = PH_OUTRO;
	if (clock_gettime(CLOCK_MONOTONIC, &v->scene.events.end) == -1)
		error_exit("");
}

static void	ft_winner(t_player *lst, int flag_v, t_visu *v)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (g_live_tab[i].last == 1)
		{
			ft_printf("Contestant %d, \"%s\", has won !\n", g_live_tab[i].id,
					g_live_tab[i].name);
			if (flag_v)
				ft_taunt(lst, i);
			break ;
		}
		i++;
	}
	if (flag_v)
		ft_setup_final(v, i);
	if (i == MAX_PLAYERS)
		ft_printf("No live, no game.\n");
}

/*
**	"L'horloge' de la machine virtuelle, elle rythme les cycles, clean les pro-
**	cessus et regule le compteur de live.
*/

void		ft_game(t_data *data, t_visu *visu)
{
	while (data->ctd > 0 && data->proc_list != NULL && !visu->quit)
	{
		data->cy = 0;
		while (++data->cy < data->ctd)
		{
			if (data->flag_v && (int)visu->cyc_per_frame <
									data->cyc_since_refresh)
			{
				render(visu, data);
				data->cyc_since_refresh = 0;
			}
			ft_fight(&data->proc_list);
			if (data->dump_val && data->dump_val == data->cyc_tot)
				ft_print_matrix();
			data->cyc_tot++;
			data->cyc_since_refresh++;
		}
		ft_refresh_lives(data);
	}
	if (!visu->quit)
		ft_winner(data->players_list, data->flag_v, visu);
	while (!visu->quit && data->flag_v)
		render(visu, data);
}
