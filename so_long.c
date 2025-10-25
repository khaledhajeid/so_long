#include "so_long.h"

int main (int argc, char **argv)
{
    t_game game;
    
    if (argc != 2)
        return (0);
    game.name_map_file = argv[1];
    if (!validation_map_path(game))
        return (1);
    if (!fill_map(num_of_lines(&game), &game))
        return (1);
    find_player_position(&game);
    if(!check_validation(&game))
    {
        free_map(game.map);
        return (1);
    }
    game.player.move = 0;
    game.player.num_move = 0;
    game.window.mlx = mlx_init();
    if(!game.window.mlx)
    {
        free_everything(&game);
        return (0);
    }
    game.window.win = mlx_new_window(game.window.mlx, get_length(&game, 0) * 64, num_of_lines(&game) * 64, "so_long");
    if(!game.window.win)
    {
        free_everything(&game);
        return (0);
    }    
    mlx_hook(game.window.win, 2, 1L<<0, handle_press, &game);
    mlx_hook(game.window.win, 17, 0, handle_x_button, &game);
    read_texture(&game);
    render(&game);
    mlx_loop(game.window.mlx);
}
