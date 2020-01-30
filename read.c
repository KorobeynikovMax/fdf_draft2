/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 17:02:34 by bedavis           #+#    #+#             */
/*   Updated: 2020/01/26 15:31:37 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_matrix(int *z_line, char *line)
{
	char **nums;
	int i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

static void			free_str_split(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static t_list_z		*new_elem(char *s)
{
	t_list_z		*coord;
	char			**parts;

	if (!(coord = (t_list_z *)ft_memalloc(sizeof(t_list_z))))
		fdf_exit("error: memory allocation for map reading.");
	if (!(parts = ft_strsplit(s, ',')))
		fdf_exit("error: splitting coordinates, while reading.");
	//if (!ft_isnumber(parts[0], 10))
	//	terminate(ERR_MAP_READING);
	//if (parts[1] && !ft_isnumber(parts[1], 16))
	//	terminate(ERR_MAP_READING);
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoihex(parts[1]) : -1;
	coord->next = NULL;
	free_str_split(parts);
	return (coord);
}

static void		parse_line(char **coord_line, t_list_z **coordinates,
								t_map *map)
{
	int	width;

	width = 0;
	while (*coord_line)
	{
		list_put(coordinates, new_elem(*(coord_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		fdf_exit("error: wrong map.");
}

void	read_file(int fd, t_list_z **coordinates, t_map *map)
{
	char *line;
	int r;
	char **coord_line;

	line = NULL;
	while ((r = ft_get_next_line(fd, &line)) == 1)
	{
		if (!(coord_line = ft_strsplit(line, ' ')))
			fdf_exit("error: map reading.");
		parse_line(coord_line, coordinates, map);
		free_str_split(coord_line);
		ft_strdel(&line);
		map->height++;
	}
	if ((r == -1) || (!(*coordinates)))
		fdf_exit("error: map reading.");
}