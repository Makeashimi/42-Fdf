/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:23:44 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/11 19:30:22 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				destroywindow(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
	return (0);
}

static int		keyevent2(int keycode, t_env *env)
{
	if (keycode == 126)
		env->height = env->height - 10;
	if (keycode == 125)
		env->height = env->height + 10;
	if (keycode == 124)
		env->width = env->width + 10;
	if (keycode == 123)
		env->width = env->width - 10;
	exposehook(env);
	return (0);
}

int				keyevent(int keycode, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (keycode == 53)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if (keycode == 69)
		env->depth++;
	if (keycode == 78)
		env->depth--;
	if (keycode == 35)
		env->zoom++;
	if (keycode == 37)
		env->zoom--;
	keyevent2(keycode, env);
	exposehook(env);
	return (0);
}
