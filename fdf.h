/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:15:00 by jcharloi          #+#    #+#             */
/*   Updated: 2017/02/22 13:13:25 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 2000
# define HEIGHT (WIDTH * 9 / 16)
# define EOC "\033[0m"
# define YELLOW "\033[38;5;228m"
# define ORANGE "\033[38;5;214m"
# define RED "\033[38;5;196m"
# define PINK "\033[38;5;219m"
# define PURPLE "\033[38;5;99m"
# define BLUE "\033[38;5;117m"
# define GREEN "\033[38;5;36m"
# define GRAY "\033[38;5;247m"
# define PERU "\033[38;5;130m"

# include "./mlxE3/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef	struct	s_color
{
	int		oct[8];
}				t_color;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bits;
	int		size;
	int		endian;
	int		xend;
	int		yend;
	int		**map;
	int		depth;
	int		zoom;
	int		height;
	int		width;
	int		variable;
	t_color	color;
}				t_env;

typedef	struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

int				read_argv(t_env *env, int fd, char **argv);
void			drawsegment(t_pos pos1, t_pos pos2, t_env *env);
int				ft_abs(int nb);
void			write_image(t_env *env, int x, int y, int color);
void			drawsegmentzero(t_pos pos1, t_pos pos2, t_env *env);
void			drawsegmentone(t_pos pos1, t_pos pos2, t_env *env);
void			drawsegmenttwo(t_pos pos1, t_pos pos2, t_env *env);
void			drawsegmentthree(t_pos pos1, t_pos pos2, t_env *env);
void			drawsegmentfour(t_pos pos1, t_pos pos2, t_env *env);
void			drawsegmentfive(t_pos pos1, t_pos pos2, t_env *env);
void			drawsegmentsix(t_pos pos1, t_pos pos2, t_env *env);
void			drawsegmentseven(t_pos pos1, t_pos pos2, t_env *env);
void			linkdots(t_env *env);
int				exposehook(void *param);
int				keyevent(int keycode, void *param);
int				destroywindow(t_env *env);
void			usecolor(t_env *env, char *str);

#endif
