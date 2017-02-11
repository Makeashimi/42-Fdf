/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:01:35 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/11 17:44:02 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** env->d = distancebetweendots;
** env->h = heightdots;
*/

void		space(t_env *env, t_pos pos, t_pos pos2)
{
	t_pos	a;
	t_pos	b;
	int		z;
	int		z2;

	a.x = pos.x - pos.y;
	a.y = pos.y + pos.x;
	b.x = pos2.x - pos2.y;
	b.y = pos2.y + pos2.x;
	z = env->map[pos.y][pos.x] * env->depth * env->zoom / 19;
	z2 = env->map[pos2.y][pos2.x] * env->depth * env->zoom / 19;
	a.y = (a.y * env->zoom) / 2 - z + env->height;
	b.y = (b.y * env->zoom) / 2 - z2 + env->height;
	a.x = a.x * env->zoom + env->width;
	b.x = b.x * env->zoom + env->width;
	drawsegment(a, b, env);
}

void		linkdots(t_env *env)
{
	t_pos	pos;
	t_pos	pos2;

	pos.y = 0;
	while (pos.y < env->yend)
	{
		pos.x = 0;
		while (pos.x < env->xend)
		{
			if (pos.x + 1 < env->xend)
			{
				pos2.x = pos.x + 1;
				pos2.y = pos.y;
				space(env, pos, pos2);
			}
			if (pos.y + 1 < env->yend)
			{
				pos2.x = pos.x;
				pos2.y = pos.y + 1;
				space(env, pos, pos2);
			}
			pos.x++;
		}
		pos.y++;
	}
}

static void	drawsegment2(t_pos pos1, t_pos pos2, t_env *env)
{
	if ((pos2.x >= pos1.x) && (pos2.y >= pos1.y))
		drawsegmentsix(pos1, pos2, env);
	if ((pos2.x >= pos1.x) && (pos1.y >= pos2.y))
		drawsegmentone(pos1, pos2, env);
	if ((pos1.x >= pos2.x) && (pos2.y >= pos1.y))
		drawsegmentfive(pos1, pos2, env);
	if ((pos1.x >= pos2.x) && (pos1.y >= pos2.y))
		drawsegmenttwo(pos1, pos2, env);
}

void		drawsegment(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;

	dx = ft_abs(pos2.x - pos1.x);
	dy = ft_abs(pos2.y - pos1.y);
	if (dx >= dy)
	{
		if ((pos2.x >= pos1.x) && (pos2.y >= pos1.y))
			drawsegmentseven(pos1, pos2, env);
		if ((pos2.x >= pos1.x) && (pos1.y >= pos2.y))
			drawsegmentzero(pos1, pos2, env);
		if ((pos1.x >= pos2.x) && (pos2.y >= pos1.y))
			drawsegmentfour(pos1, pos2, env);
		if ((pos1.x >= pos2.x) && (pos1.y >= pos2.y))
			drawsegmentthree(pos1, pos2, env);
	}
	else
		drawsegment2(pos1, pos2, env);
}
