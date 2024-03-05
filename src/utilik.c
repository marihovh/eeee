/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilik.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:27:38 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/05 20:53:04 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_it_move_it(t_data *data)
{
	if (data->keys.w == 1 && !data->keys.a && !data->keys.s && !data->keys.d)
		qayl_araj(data);
	if (data->keys.a == 1 && !data->keys.w && !data->keys.s && !data->keys.d)
		qayl_dzax(data);
	if (data->keys.s == 1 && !data->keys.a && !data->keys.w && !data->keys.d)
		qayl_het(data);
	if (data->keys.d == 1 && !data->keys.a && !data->keys.s && !data->keys.w)
		qayl_aj(data);
	if (data->keys.rl == 1 && !data->keys.rr)
		depi_dzax(data);
	if (data->keys.rr == 1 && !data->keys.rl)
		depi_aj(data);
}

void	depi_dzax(t_data *data)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rot_speed) - \
	data->dir_y * sin(data->rot_speed);
	data->dir_y = old_dir_x * sin(data->rot_speed) + \
	data->dir_y * cos(data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = old_plane_x * cos(data->rot_speed) - \
	data->plane_y * sin(data->rot_speed);
	data->plane_y = old_plane_x * sin(data->rot_speed) + \
	data->plane_y * cos(data->rot_speed);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{

		j = -1;
		while (data->map_c[i][++j])
		{
			if (can_be(data->map_c[i][j]))
			{
				return (1);
			}
			if (direction(data->map_c[i][j]))
			{
				data->nb++;
				data->pos_x = i;
				data->pos_y = j;
			}
			if (direction(data->map_c[i][j]) || data->map_c[i][j] == '0')
			{
				if (check_neighbor(data->map_c, i, j))
					return (1);
			}
		}
		i++;
	}
	if (data->nb > 1)
	{
		printf("aaaassssssa\n");
		return (1);
	}
	return (0);
}

int	tree_nb(char *line, t_data *data, int flag)
{
	int	i;
	int	j;
	int	nb[3];

	j = -1;
	while (++j < 3)
	{
		i = 0;
		while (line[i] != '\n' && line[i] >= '0' && line[i] <= '9')
			i++;
		if (line[i] != '\n' && line[i] != ' ' && line[i] != ',')
			return (1);
		nb[j] = ft_atoi(line);
		line += i;
		skip_sp(&line);
		if (any_invalid(&line, i, j))
			return (1);
		if (j == 2)
			line++;
	}
	printf("aaaaaaaaaaaaaaaaaaaaaaaa%s", line);
	if (!flag)
		data->c = create_trgb(0, nb[0], nb[1], nb[2]);
	else
		data->f = create_trgb(0, nb[0], nb[1], nb[2]);
	return (0);
}

void	camera_frame_counting(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(screenHeight / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + screenHeight / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = screenHeight / 2 + data->line_height / 2 ;
	if (data->draw_end >= screenHeight)
		data->draw_end = screenHeight;
}
