/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_clock.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 16:02:28 by lbelda            #+#    #+#             */
/*   Updated: 2018/06/28 17:49:13 by achirat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

#define SEC_INTRO 8.6

t_events	init_clock(void)
{
	t_events	e;

	ft_bzero(&e, sizeof(t_events));
	e.phase = PH_INTRO;
	if (clock_gettime(CLOCK_MONOTONIC, &e.origin) == -1)
		error_exit("clock_gettime error");
	return (e);
}

static void	set_outro_clock(t_events *e)
{
	e->time_end = (float)(e->current.tv_sec - e->end.tv_sec) +
				(float)(e->current.tv_nsec - e->end.tv_nsec) * 1.0e-9;
}

void		update_clock(t_visu *v, t_events *e)
{
	if (clock_gettime(CLOCK_MONOTONIC, &e->current) == -1)
		error_exit("");
	if (e->phase == PH_OUTRO)
		set_outro_clock(e);
	e->current = (struct timespec){e->current.tv_sec - e->origin.tv_sec,
								e->current.tv_nsec - e->origin.tv_nsec};
	e->time = (float)e->current.tv_sec + (float)(e->current.tv_nsec * 1.0e-9);
	if (e->phase == PH_INTRO)
		if ((e->intro = e->time / SEC_INTRO) >= 1.)
		{
			e->phase = PH_GAME;
			e->intro = 1.;
			v->pause = 0;
		}
	if (e->phase == PH_OUTRO)
		e->outro = ft_fmin(e->outro + 0.01, 1.);
}
