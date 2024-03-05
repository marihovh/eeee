/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:58:44 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/05 20:41:22 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_texture(char *line, char **textures, int i)
{
	// printf("aaaaaaaa\n");
	if (*(line + ft_strlen(line) - 1) == '\n')
		*(line + ft_strlen(line) - 1) = '\0';
	textures[i] = ft_strdup(line);
	printf("%s\n", textures[i]);
	if (!textures[i])
		return (T_ERROR);
	return (0);
}

int	fill_textures(char *line, char **textures)
{
	char	**splited;
	int		ret;
	int		i;

	ret = 3;
	splited = ft_split(line, ' ');
	if (!splited || !splited[0] || !splited[1] || splited[1][0] == '\n' \
		|| (splited[2] && splited[2][0] != '\n'))
		ret = T_ERROR;
	else if (ft_strlen(splited[0]) > 2)
		ret = T_ERROR;
	else if (!ft_strncmp(splited[0], "NO", 2) && !textures[0])
		ret = set_texture(splited[1], textures, 0);
	else if (!ft_strncmp(splited[0], "SO", 2) && !textures[1])
		ret = set_texture(splited[1], textures, 1);
	else if (!ft_strncmp(splited[0], "WE", 2) && !textures[2])
		ret = set_texture(splited[1], textures, 2);
	else if (!ft_strncmp(splited[0], "EA", 2) && !textures[3])
		ret = set_texture(splited[1], textures, 3);
	i = -1;
	// printf("%s\n", textures[0]);
	while (splited[++i])
		free(splited[i]);
	free(splited);
	return (ret);
}

int	init_textures(char **line, int fd, char **textures, int *to_map)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!(*line) || fill_textures(*line, textures))
		{
			free(*line);
			return (errorik(T_ERROR));
		}
		free(*line);
		*line = get_next_line(fd);
		(*to_map)++;
		while (empty_line(*line))
		{
			free(*line);
			*line = get_next_line(fd);
			(*to_map)++;
		}
	}
	return (0);
}

int	path_exist(char **textures)
{
	int fd;
	int i = -1;

	while (++i < 4)
	{
		fd = open(textures[i], O_RDONLY);
		if (fd < 0)
			return (1);
	}
	return (0);
}

int	first_texture(char *line, int fd, t_data *data)
{
	if (init_textures(&line, fd, data->textures, &data->to_map))
		return (1);
	if (path_exist(data->textures))
	{
		free(line);
		return (errorik(T_ERROR));
	}
	if (line && is_color(line))
	{
		if (init_colors(line, data))
		{
			free(line);
			return (errorik(C_ERROR));
		}
	printf("{{{{%s}}}}\n", line);

		skipping(&line, fd, data);
		if (!line || init_colors(line, data))
		{
			free(line);
			return (errorik(C_ERROR));
		}
		free(line);
		line = get_next_line(fd);
		data->to_map += 2;
	}
	else
		return (errorik(C_ERROR));
	if (parce_map(fd, line, data))
		return (1);
	return (0);
}
