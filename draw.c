/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:52:00 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/29 13:03:32 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double  max(double a, double b)
{
	return (a > b ? a : b);
}

static double my_abs(double a)
{
	return (a < 0 ? -a : a);
}

static void	put_pixel(int x, int y, int color, t_fdf *fdf)
{
	int		i;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

void 	draw_line(t_point a, t_point b, t_map *map, t_fdf *fdf)
{
	int step_x;
	int step_y;
	t_point point;
	t_point sign;
	t_point error;

	step_x = my_abs(b.x - a.x);
	step_y = my_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error.x = step_x - step_y;
	point = a;
	while ((point.x != b.x) || (point.y != b.y))
	{
		put_pixel(point.x, point.y, point.color, fdf);
		error.y = error.x * 2;
		if (error.y > -step_y)
		{
			error.x = error.x - step_y;
			point.x += sign.x;
		}
		if (error.y < step_x)
		{
			error.x = error.x + step_x;
			point.y += sign.y;
		}
	}
}

void	draw(t_map *map, t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	ft_bzero(fdf->data_addr, WIN_WIDTH * WIN_HEIGHT * (fdf->bpp / 8));
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(p3d(make_point(x, y, map), fdf), p3d(make_point(x +
				1, y, map), fdf), map, fdf);
			if (y < map->height - 1)
				draw_line(p3d(make_point(x, y, map), fdf), p3d(make_point(x, y
				+ 1, map), fdf), map, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	print_usage(fdf);
}

