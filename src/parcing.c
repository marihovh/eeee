/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:44:38 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/05 20:39:13 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_map(t_data *data, char **line, int fd)
{
	int	i;

	printf("%i\n", data->map_h);
	data->map_c = (char **)malloc(sizeof(char *) * (data->map_h + 1));
	if (!data->map_c)
		return (errorik(M_ERROR));
	i = 0;
	while (i < data->map_h)
	{
		data->map_c[i++] = ft_strdup_t(*line);
		printf("->%s<-\n", data->map_c[i - 1]);
		free(*line);
		*line = get_next_line(fd);
	}
	data->map_c[data->map_h] = NULL;
	if (check_map(data))
	{
		
		printf("valaaaaaaa\n");
		return (errorik(M_ERROR));
	}
	to_int(data);
	return (0);
}

void	skip(char **line, t_data *data, int fd)
{
	while (empty_line(*line))
	{
		free(*line);
		*line = get_next_line(fd);
		data->to_map++;
	}
}

int	parce_map(int fd, char *line, t_data *data)
{
	int	i;

	i = 0;
	data->to_map++;
	skip(&line, data, fd);
	if (!line)
		return (errorik(M_ERROR));
	while (line)
	{
		data->map_h++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(data->filename, O_RDONLY);
	while (i++ < data->to_map)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (init_map(data, &line, fd))
		return (1);
	return (0);
}

int	inner_map(int fd, t_data *data)
{
	char	*line;
	int		i;

	i = -1;
	line = get_next_line(fd);
	while (empty_line(line))
	{
		free(line);
		line = get_next_line(fd);
		data->to_map++;
	}
	if (line && is_texture(line))
	{
		if (first_texture(line, fd, data))
			return (1);
	}
	else if (line && is_color(line))
	{
		if (first_color(line, fd, data))
			return (1);
	}
	else
		return (errorik(E_ERROR));
	return (0);
}

int	parcing(t_data *data, char **argv)
{
	char	*file_ext;
	int		fd;

	file_ext = argv[1];
	data->filename = ft_strdup(argv[1]);
	if (ft_strlen(file_ext) <= 4)
		return (errorik(F_ERROR));
	file_ext += ft_strlen(file_ext) - 4;
	if (ft_strncmp(file_ext, ".cub", 4))
		return (errorik(F_ERROR));
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (errorik(M_ERROR));
	if (inner_map(fd, data))
		return (1);
	return (0);
}
