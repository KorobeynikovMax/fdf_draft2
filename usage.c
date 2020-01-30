/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:45:16 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/29 13:47:31 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_usage(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 45, y += 20, TEXT_COLOR, "Fdf's usage:");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or '+' / "
												   "'-'");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move: Arrows(Left, "
												   "Right, Up, Down)");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Change Z: '<' / '>'");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Alpha projection +/- "
												   "'2'/'8'");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Betta projection +/- "
													  "'4'/'6'");
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Gamma increase '1' '3'");
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Gamma decrease '7' '9'");
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Use mouse Left button "
												   "for changing projection");
	mlx_string_put(mlx, win, 15, y += 25, TEXT_COLOR, "Use mouse Right button "
													  "for moving");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Change projection 'P'");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "-------");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "-------");
/*	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, "Current Shift_X: ");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, ft_itoa(map->shift_x));
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, "Current Shift_Y: ");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, ft_itoa(map->shift_y));
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, "Current Zoom X: ");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, ft_itoa(map->zoom));
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, "Current Z_flatten: ");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, ft_itoa(map->flat));
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, "Current Color: ");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR2, ft_itoa(map->color));*/
}