/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 00:01:42 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/05 20:51:49 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	any_invalid(char **line, int i, int j)
{
	if ((*line[0] == '\n' && j != 2) || i == 0)
		return (1);
	if (*line[0] == ',' && j == 2)
		return (1);
	if (*line[0] == ',' && j != 2)
	{
		(*line)++;
		skip_sp(line);
		printf("aaaaaaaaaa:%s\n", *line);
		if (*line[0] != '\n')
			return (1);
	}
	return (0);
}

int	key_hook(void)
{
	exit(0);
	return (0);
}

int	key_cross(int keycode)
{
	(void)keycode;
	ft_putstr_fd ("The session is over!\n", 1);
	exit(0);
}
