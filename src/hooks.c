/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:11:37 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/05 00:11:53 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	unpressed(int keycode, t_data *data)
{
	if (keycode == 13)
		data->keys.w = 0;
	if (keycode == 0)
		data->keys.a = 0;
	if (keycode == 1)
		data->keys.s = 0;
	if (keycode == 2)
		data->keys.d = 0;
	if (keycode == 123)
		data->keys.rl = 0;
	if (keycode == 124)
		data->keys.rr = 0;
	return (0);
}

int	pressed(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
		exit(0);
	}
	if (keycode == 13)
		data->keys.w = 1;
	if (keycode == 0)
		data->keys.a = 1;
	if (keycode == 1)
		data->keys.s = 1;
	if (keycode == 2)
		data->keys.d = 1;
	if (keycode == 123)
		data->keys.rl = 1;
	if (keycode == 124)
		data->keys.rr = 1;
	return (0);
}

void	keycodes_initializing(t_data *data)
{
	data->keys.w = 0;
	data->keys.d = 0;
	data->keys.s = 0;
	data->keys.a = 0;
	data->keys.rr = 0;
	data->keys.rl = 0;
}
