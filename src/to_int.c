/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:00:29 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/05 00:00:31 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_height(char **map)
{
	int	height;
	int	i;

	i = -1;
	height = 0;
	while (map[++i])
		height++;
	return (height);
}

int	get_max_width(char **map)
{
	int	widht;
	int	max;
	int	i;

	i = -1;
	max = 0;
	while (map[++i])
	{
		widht = ft_strlen(map[i]);
		if (max < widht)
			max = widht;
	}
	return (max);
}

void	to_int(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	data->map = (int **)malloc(sizeof(int *) * (data->map_h));
	data->widht = get_max_width(data->map_c);
	while (++i < data->map_h)
		data->map[i] = (int *)malloc(sizeof(int *) * (data->widht));
	i = -1;
	while (data->map_c[++i])
	{
		j = -1;
		while (data->map_c[i][++j])
			data->map[i][j] = (int)data->map_c[i][j];
	}
}
