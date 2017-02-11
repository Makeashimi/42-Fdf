/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:00:22 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/11 17:13:08 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawsegmentthree(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;
	int e;

	e = ft_abs(pos2.x - pos1.x);
	dx = e * 2;
	dy = ft_abs(pos2.y - pos1.y) * 2;
	while (pos1.x >= pos2.x)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[3]);
		pos1.x--;
		e = e - dy;
		if (e <= 0)
		{
			pos1.y--;
			e = e + dx;
		}
	}
}

void	drawsegmentfour(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;
	int e;

	e = (pos2.y - pos1.y);
	dx = ft_abs(pos2.x - pos1.x) * 2;
	dy = e * 2;
	while (pos2.y >= pos1.y)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[4]);
		pos1.x--;
		e = e - dy;
		if (e <= 0)
		{
			pos1.y++;
			e = e + dx;
		}
	}
}

void	drawsegmentfive(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;
	int e;

	e = (pos2.y - pos1.y);
	dx = ft_abs(pos2.x - pos1.x) * 2;
	dy = e * 2;
	while (pos2.y >= pos1.y)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[5]);
		pos1.y++;
		e = e - dx;
		if (e <= 0)
		{
			pos1.x--;
			e = e + dy;
		}
	}
}

void	drawsegmentsix(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;
	int e;

	e = (pos2.y - pos1.y);
	dx = (pos2.x - pos1.x) * 2;
	dy = e * 2;
	while (pos2.y >= pos1.y)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[6]);
		pos1.y++;
		e = e - dx;
		if (e <= 0)
		{
			pos1.x++;
			e = e + dy;
		}
	}
}

void	drawsegmentseven(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;
	int e;

	e = (pos2.x - pos1.x);
	dx = e * 2;
	dy = (pos2.y - pos1.y) * 2;
	while (pos2.x >= pos1.x)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[7]);
		pos1.x++;
		e = e - dy;
		if (e <= 0)
		{
			pos1.y++;
			e = e + dx;
		}
	}
}
