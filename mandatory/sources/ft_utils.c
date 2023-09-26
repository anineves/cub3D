/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:43:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/26 18:26:49 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1)
	{
		return (NULL);
	}
	newstr = (char *)malloc (sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		newstr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		newstr[j++] = s2[i];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}

void	ft_free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i += 1;
	}
	free(map);
	map = NULL;
}

void	ft_free_textures3(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->textures[i] != NULL)
		{
			free(data->textures[i]);
			data->textures[i] = NULL;
		}
		i++;
	}
	free(data->textures);
	data->textures = NULL;
}

void	ft_free_textures(t_data *data)
{
	if (data->map.north)
		free(data->map.north);
	if (data->map.south)
		free(data->map.south);
	if (data->map.east)
		free(data->map.east);
	if (data->map.west)
		free(data->map.west);
}

void	ft_color_empty(char **colors, t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 3)
	{
		k = 0;
		j = 0;
		while (colors[i][j] != '\0')
		{
			if (colors[i][j] != 32 && colors[i][j] != '\t')
				k++;
			j++;
		}
		if (k == 0)
			ft_error("empty color", data, 0);
		i++;
	}
}
