/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:46:58 by hjung             #+#    #+#             */
/*   Updated: 2020/10/27 19:58:02 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "get_next_line.h"
# include <fcntl.h>

typedef	struct	s_map_info
{
	int			rows;
	int			cols;
	char		**map;
}				t_map_info;

int	parse_map(t_map_info *map_info);
int	chk_map_validity(t_map_info *map_info);

#endif