/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:28:12 by marihovh          #+#    #+#             */
/*   Updated: 2024/03/05 19:18:46 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i] || line[i] == '\n')
		return (1);
	return (0);
}

int	is_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		return (1);
	return (0);
}

int	ft_strlen_t(const char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] == '\t')
			ret += 3;
		i++;
		ret++;
	}
	return (ret);
}


char	*ft_strdup_t( char *s1)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen_t(s1) + 2;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	int j= -1;
	int x = 0;
	while (s1[++j] != '\0' && s1[j] != '\n')
	{
		i = 0;
		while (s1[j] == '\t')
		{
			i = 0;
			while (i++ < 4)
			{
				ptr[x] = ' ';
				x++;
			}
			j++;
		}
		ptr[x] = s1[j];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}
