/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_of _map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:06:36 by kal-haj-          #+#    #+#             */
/*   Updated: 2025/10/24 19:50:02 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validation_map_path(t_game game)
{
    int len;
    char path[4];
    int i;
    int j;

    j = 0;
    path[0] = '.';
    path[1] = 'b';
    path[2] = 'e';
    path[3] = 'r';
    len = ft_strlen(game.name_map_file);
    i = len - 4;
    if (len < 4)
        return (0);
    while(i < len)
    {
        if (game.name_map_file[i] != path[j])
            return (0);
        i++;
        j++;
    }
    return (1);
}

int flood_fill(char **map, int playery, int playerx)
{
    map[playery][playerx] = '1';
    if (map[playery + 1][playerx] != '1')
        flood_fill(map, playery + 1, playerx);
    if (map[playery- 1][playerx] != '1')
        flood_fill(map, playery - 1, playerx);
    if (map[playery][playerx + 1] != '1')
        flood_fill(map, playery, playerx + 1);
    if (map[playery][playerx - 1] != '1')
        flood_fill(map, playery, playerx - 1);
    return (num_char_in_map(map, 'C') == 0 && num_char_in_map(map, 'E') == 0);
}

int check_validation_exit_coll_path(t_game *game)
{
    t_game copy;
    copy.name_map_file = game->name_map_file;
    fill_map(num_of_lines(game), &copy);
    if (!flood_fill(copy.map, game->player.y_player, game->player.x_player))
    {
        printf("Erorr\nthere is an collectible or the exit you can't take it");
        return (0);
    }
    return (1);
}