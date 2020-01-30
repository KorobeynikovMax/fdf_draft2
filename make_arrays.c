/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:02:00 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/27 14:03:50 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	make_arrays(t_list_z **cordinates, t_map *map)
{
	t_list_z	*coord;
	size_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	if (!(map->arr_coord = (int *)ft_memalloc(arr_size)))
		fdf_exit("error: coordinates creation.");
	if (!(map->arr_color = (int *)ft_memalloc(arr_size)))
		fdf_exit("error: coordinates creation.");
	i = map->width * map->height - 1;
	while ((coord = list_get(cordinates)))
	{
		map->arr_coord[i] = coord->z;
		map->arr_color[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}

t_point	make_point(int x, int y, t_map *map)
{
	t_point	new;
	int		i;

	i = y * map->width + x;
	new.x = x;
	new.y = y;
	new.z = map->arr_coord[i];
	if (map->arr_color[i] == -1)
		new.color = BACK_COLOR;
	else
		new.color = map->arr_color[i];
	return (new);
}