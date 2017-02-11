/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloroctants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:36:26 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/11 18:01:03 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	coloroctants(t_env *env, char *str, int i)
{
	ft_putstr("Color for octant ");
	ft_putnbr(i);
	ft_putstr(" : ");
	if (get_next_line(0, &str) == 1)
	{
		if (strcmp(str, "1") == 0)
			env->color.oct[i] = 0xFFFFE0;
		else if (strcmp(str, "2") == 0)
			env->color.oct[i] = 0xFFA800;
		else if (strcmp(str, "3") == 0)
			env->color.oct[i] = 0xFF0000;
		else if (strcmp(str, "4") == 0)
			env->color.oct[i] = 0xFFB8C0;
		else if (strcmp(str, "5") == 0)
			env->color.oct[i] = 0x7868E8;
		else if (strcmp(str, "6") == 0)
			env->color.oct[i] = 0xABC8E2;
		else if (strcmp(str, "7") == 0)
			env->color.oct[i] = 0x20B4A8;
		else if (strcmp(str, "8") == 0)
			env->color.oct[i] = 0xA8ACA8;
		else if (strcmp(str, "9") == 0)
			env->color.oct[i] = 0xC88440;
		ft_memdel((void**)&str);
	}
}

void		usecolor(t_env *env, char *str)
{
	int		i;

	i = 0;
	ft_putchar('\n');
	ft_putstr("Choices of colors for your octants :\n");
	ft_putchar('\n');
	ft_putstr("1) "YELLOW"LightYellow"EOC" = 0xFFFFE0\n\
2) "ORANGE"LightOrange"EOC" = 0xFFA800\n\
3) "RED"SimpleRed"EOC" = 0xFF0000\n\
4) "PINK"LightPink"EOC" = 0xFFB8C0\n\
5) "PURPLE"DarkPurple"EOC" = 0x7868E8\n\
6) "BLUE"LightBlue"EOC" = 0xABC8E2\n\
7) "GREEN"CadetGreen"EOC" = 0x20B4A8\n\
8) "GRAY"DarkGray"EOC" = 0xA8ACA8\n\
9) "PERU"Peru"EOC" = 0xC88440\n\n");
	while (i < 8)
	{
		coloroctants(env, str, i);
		i++;
	}
}
