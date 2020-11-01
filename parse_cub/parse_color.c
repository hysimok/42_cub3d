/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:09:54 by hjung             #+#    #+#             */
/*   Updated: 2020/11/01 18:08:55 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_num_color(char *line, int *i)
{
	int	color;

	color = ft_atoi(&line[*i]);
	if (color < 0 || color > 255)
		return (-1);
	while (ft_isdigit(line[*i]))
		*i += 1;
	*i += 1;
	return (color);
}

int		parse_color(t_game *game, char *line, char opt)
{
	int	i;
	int	r;
	int	g;
	int b;
	int	rgb;

	i = 1;
	if (line[1] != ' ')
		return (0);
	while (is_whitespace(line[i]) || line[i] == ',')
		i++;
	if ((r = get_num_color(line, &i)) == -1
		|| (g = get_num_color(line, &i)) == -1
		|| (b = get_num_color(line, &i)) == -1)
		return (0);
	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	if (opt == 'F')
		game->cub_info->color_floor = rgb;
	else if (opt == 'C')
		game->cub_info->color_ceil = rgb;
	return (1);
}
