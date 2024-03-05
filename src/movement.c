/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:24:03 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/04 23:31:15 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	qayl_aj(t_data *data)
{
	if (data->map_c[(int)(data->pos_x + data->plane_x * \
	(data->move_speed + 0.9))][(int)data->pos_y] == '0' )
		data->pos_x += data->plane_x * data->move_speed;
	if (data->map_c[(int)data->pos_x][(int)(data->pos_y + \
	data->plane_y * (data->move_speed + 0.9))] == '0')
		data->pos_y += data->plane_y * data->move_speed;
}

void	qayl_dzax(t_data *data)
{
	if (data->map_c[(int)(data->pos_x - data->plane_x * \
	(data->move_speed + 0.9))][(int)data->pos_y] == '0')
		data->pos_x -= data->plane_x * data->move_speed;
	if (data->map_c[(int)data->pos_x][(int)(data->pos_y - \
	data->plane_y * (data->move_speed + 0.9))] == '0')
		data->pos_y -= data->plane_y * data->move_speed;
}

void	qayl_araj(t_data *data)
{
	if (data->map_c[(int)(data->pos_x + data->dir_x * \
	(data->move_speed + 0.9))][(int)data->pos_y] == '0')
		data->pos_x += data->dir_x * data->move_speed;
	if (data->map_c[(int)data->pos_x][(int)(data->pos_y + \
	data->dir_y * (data->move_speed + 0.9))] == '0')
		data->pos_y += data->dir_y * data->move_speed;
}

void	qayl_het(t_data *data)
{
	if (data->map_c[(int)(data->pos_x - data->dir_x * \
	(data->move_speed + 0.9))][(int)data->pos_y] == '0')
		data->pos_x -= data->dir_x * data->move_speed;
	if (data->map_c[(int)data->pos_x][(int)(data->pos_y - \
	data->dir_y * (data->move_speed + 0.9))] == '0')
		data->pos_y -= data->dir_y * data->move_speed;
}

void	depi_aj(t_data *data)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->rot_speed) - \
	data->dir_y * sin(-data->rot_speed);
	data->dir_y = old_dir_x * sin(-data->rot_speed) + \
	data->dir_y * cos(-data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = old_plane_x * cos(-data->rot_speed) - \
	data->plane_y * sin(-data->rot_speed);
	data->plane_y = old_plane_x * sin(-data->rot_speed) + \
		data->plane_y * cos(-data->rot_speed);
}
