/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:20:04 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/04 21:20:06 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north_path_data_filling(t_data *data)
{
	data->dir_x = -1.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.66;
}

void	south_path_data_filling(t_data *data)
{
	data->dir_x = 1.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = -0.66;
}

void	west_path_data_filling(t_data *data)
{
	data->dir_x = 0.0;
	data->dir_y = 1.0;
	data->plane_x = 0.66;
	data->plane_y = 0.0;
}

void	east_path_data_filling(t_data *data)
{
	data->dir_x = 0.0;
	data->dir_y = -1.0;
	data->plane_x = -0.66;
	data->plane_y = 0.0;
}

void	chose_gamer_path2(t_data *data)
{
	if (data->hero->view == 87)
		west_path_data_filling(data);
	else if (data->hero->view == 78)
		north_path_data_filling(data);
	else if (data->hero->view == 83)
		south_path_data_filling(data);
	else if (data->hero->view == 69)
		east_path_data_filling(data);
}
