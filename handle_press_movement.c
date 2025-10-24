/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_press_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kal-haj- <kal-haj-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:14:14 by kal-haj-          #+#    #+#             */
/*   Updated: 2025/10/24 19:53:33 by kal-haj-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_x_button(void *game)
{
    (void) game;
    exit(0);
    return(0);
}

void take_coin(t_game *game)
{
    if (game->map[game->player.y_player][game->player.x_player] == 'C')
    {
        game->map[game->player.y_player][game->player.x_player] = '0';
        game->num_of_coin--;
    }
    else if (game->map[game->player.y_player][game->player.x_player] == 'C')
    {
        game->map[game->player.y_player][game->player.x_player] = '0';
        game->num_of_coin--;
    }
    else if (game->map[game->player.y_player][game->player.x_player] == 'C')
    {
        game->map[game->player.y_player][game->player.x_player] = '0';
        game->num_of_coin--;
    }
    else if (game->map[game->player.y_player][game->player.x_player] == 'C')
    {

        game->map[game->player.y_player][game->player.x_player] = '0';
        game->num_of_coin--;
    }
}

void win_game(t_game *game)
{
    if (game->map[game->player.y_player][game->player.x_player] == 'E' && game->num_of_coin == 0)
        exit(0);
}

void handle_movement(int keycode, t_game *game)
{
    if (keycode == 0x77 && game->map[game->player.y_player - 1][game->player.x_player] != '1')
    {
        game->player.y_player -= 1;
        game->player.num_move++;
        game->player.move = 1;
    }
    else if (keycode == 0x73 && game->map[game->player.y_player + 1][game->player.x_player] != '1')
    {
        game->player.y_player += 1;
        game->player.num_move++;
        game->player.move = 1;
    }
    else if (keycode == 0x64 && game->map[game->player.y_player][game->player.x_player + 1] != '1')
    {
        game->player.x_player += 1;
        game->player.num_move++;
        game->player.move = 1;
    }
    else if (keycode == 0x61 && game->map[game->player.y_player][game->player.x_player - 1] != '1')
    {
        game->player.x_player -= 1;
        game->player.num_move++;
        game->player.move = 1;
    }
}
int handle_press(int keycode, void *param)
{
    t_game *game;

    game  = (t_game *)param;
    if (keycode == 0xff1b)
        exit(0);
    handle_movement(keycode, game);
    if (game->player.move == 1)
        printf("Number of move: %d\n", game->player.num_move);
    game->player.move = 0;
    take_coin(game);
    win_game(game);
    render(game);
    player_render(game, keycode);
    return (0);
}