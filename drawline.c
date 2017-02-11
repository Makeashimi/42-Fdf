/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:21:53 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/11 17:12:54 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int nb)
{
	return (nb > 0 ? nb : -nb);
}

void	write_image(t_env *env, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
		ft_memcpy(&env->data[((y * env->size) + (x * 4))], &color, 4);
}

/*
**	drawsegmentzero(300, 300, 600, 150, &env);
**	drawsegmentone(300, 300, 450, 0, &env);
**	drawsegmenttwo(300, 300, 150, 0, &env);
**	drawsegmentthree(300, 300, 0, 150, &env);
**	drawsegmentfour(300, 300, 0, 450, &env);
**	drawsegmentfive(300, 300, 150, 600, &env);
**	drawsegmentsix(300, 300, 450, 600, &env);
**	drawsegmentseven(300, 300, 600, 450, &env);
*/

void	drawsegmentzero(t_pos pos1, t_pos pos2, t_env *env)
{
	int	dx;
	int	dy;
	int	e;

	e = (pos2.x - pos1.x);
	dx = e * 2;
	dy = ft_abs(pos2.y - pos1.y) * 2;
	while (pos2.x >= pos1.x)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[0]);
		pos1.x++;
		e = e - dy;
		if (e <= 0)
		{
			pos1.y--;
			e = e + dx;
		}
	}
}

void	drawsegmentone(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;
	int e;

	e = ft_abs(pos2.y - pos1.y);
	dx = (pos2.x - pos1.x) * 2;
	dy = e * 2;
	while (pos1.y >= pos2.y)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[1]);
		pos1.y--;
		e = e - dx;
		if (e <= 0)
		{
			pos1.x++;
			e = e + dy;
		}
	}
}

void	drawsegmenttwo(t_pos pos1, t_pos pos2, t_env *env)
{
	int dx;
	int dy;
	int e;

	e = ft_abs(pos2.y - pos1.y);
	dx = ft_abs(pos2.x - pos1.x) * 2;
	dy = e * 2;
	while (pos1.y >= pos2.y)
	{
		write_image(env, pos1.x, pos1.y, env->color.oct[2]);
		pos1.y--;
		e = e - dx;
		if (e <= 0)
		{
			pos1.x--;
			e = e + dy;
		}
	}
}
