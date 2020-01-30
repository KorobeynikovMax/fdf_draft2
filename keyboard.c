/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:18:22 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/30 11:13:18 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "key_map.h"

int			key_press(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_ESC)
		fdf_exit("Normal exit.");
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS)
		fdf->camera->zoom++;
	else if ((key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS) &&
	fdf->camera->zoom > 1)
		fdf->camera->zoom--;
	if (key == NUM_PAD_2)
		fdf->camera->alpha += 0.02;
	else if (key == NUM_PAD_8)
		fdf->camera->alpha -= 0.02;
	else if (key == NUM_PAD_4)
		fdf->camera->beta -= 0.02;
	else if (key == NUM_PAD_6)
		fdf->camera->beta += 0.02;
	else if (key == NUM_PAD_1 || key == NUM_PAD_3)
		fdf->camera->gamma += 0.02;
	else if (key == NUM_PAD_7 || key == NUM_PAD_9)
		fdf->camera->gamma -= 0.02;
	if (key == MAIN_PAD_MORE && fdf->camera->z_divisor >= 0.01)
		fdf->camera->z_divisor -= 0.1;
	else if (key == MAIN_PAD_LESS && fdf->camera->z_divisor <= 20)
		fdf->camera->z_divisor += 0.1;
	if (key == MAIN_PAD_P)
	{
		if (fdf->camera->projection == ISO)
		{
			fdf->camera->projection = PARALLEL;
			fdf->camera->alpha = 0;
			fdf->camera->beta = 0;
			fdf->camera->gamma = 0;
		}
		else
			fdf->camera->projection = ISO;
	}
	if (key == ARROW_LEFT)
		fdf->camera->x_offset -= 10;
	if 	(key == ARROW_RIGHT)
		fdf->camera->x_offset += 10;
	if (key == ARROW_UP)
		fdf->camera->y_offset -= 10;
	if (key == ARROW_DOWN)
		fdf->camera->y_offset += 10;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf->map, fdf);
	return (0);
}

int	x_close(t_fdf *fdf)
{
	fdf_exit("Normal exit.");
	return (0);
}

void	hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win_ptr, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, x_close, fdf);
}