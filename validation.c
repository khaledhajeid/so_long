/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:06:38 by kal-haj-          #+#    #+#             */
/*   Updated: 2025/10/25 18:09:39 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_rectangle(t_game *game)
{
    int i;
    int length_of_line;

    i = 0;
    length_of_line = get_length(game, 0);
    while (game->map[i])
    {
        if(get_length(game, i) != length_of_line)
            return (0);
        i++;
    }
    return (1);

}

int surrounded_by_walls(t_game *game)
{
    int i;
    int last_line;
    int len_of_line;

    len_of_line = get_length(game, 0);
    last_line = num_of_lines(game);
    if (!last_line)
        return (0);
    i = 0;
    while (i < len_of_line)
    {
        if(game->map[0][i] != '1')
            return (0);
        if (game->map[last_line - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < last_line)
    {
        if (game->map[i][0] != '1')
            return (0);
        if (game->map[i][len_of_line - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_exit_start_collectible(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (num_char_in_map(game->map, 'P') != 1)
                return (1);
            if (num_char_in_map(game->map, 'C') < 1)
                return (2);
            if (num_char_in_map(game->map, 'E') != 1)
                return (3);
            if (game->map[y][x] != 'P' && game->map[y][x] != 'C' && game->map[y][x] != 'E' && game->map[y][x] != '1' && game->map[y][x] != '0')
                return (4);
            x++;
        }
        y++;
    }
    return (0);
}

void print_message(int num_of_error)
{
    if (num_of_error == 1)
        ft_printf("Erorr\nThere is no Player in the map or more than 1 player");
    if (num_of_error == 2)
        ft_printf("Erorr\nThere is no Collectible in the map");
    if (num_of_error == 3)
        ft_printf("Erorr\nThere is no Exit in the map or more than 1 exit");
    if (num_of_error == 4)
        ft_printf("Erorr\nThere is an undefined character");
}


int check_validation(t_game *game)
{
    int count;

    count = 0;
    if (!check_rectangle(game))
    {
        ft_printf("Erorr\nIt's not a Rectangle map");
        return (0);
    }
    if (!surrounded_by_walls(game))
    {
        ft_printf("Erorr\nthe map not surrounded by walls");
        return (0);
    }
    count = check_exit_start_collectible(game);
    if (count)
    {
        print_message(count);
        return (0);
    }
    if (!check_validation_exit_coll_path(game))
        return (0);
    return (1);
}
