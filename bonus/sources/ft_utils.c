/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:43:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 17:13:10 by anaraujo         ###   ########.fr       */
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
	while (i < 7)
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
