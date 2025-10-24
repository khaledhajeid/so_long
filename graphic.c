#include "so_long.h"

// int num_of_lines(t_game *game) //done
// {
//     int fd;
//     int i;
//     char buffer;

//     fd = open(game->name_map_file, O_RDONLY);
//     if (fd == -1)
//         return (0);
//     i = 1;
//     while (1)
//     {
//         int check = read(fd, &buffer, 1);
//         if (check == -1)
//             return (0);
//         if (check == 0)
//             break;
//         if (buffer == '\n')
//             i++;
//     }
//     close(fd);
//     return (i);
// }

// int    fill_map(int num_line, t_game *game) //done
// {
//     int i;
//     int fd;

//     fd = open(game->name_map_file, O_RDONLY);
//     if (fd == -1)
//         return (0);
//     i = 0;
//     game->map = malloc((num_line + 1) * sizeof(char *));
//     if (!game->map)
//         return (0);
//     while(i < num_line)
//     {
//         game->map[i] = get_next_line(fd);
//         if (game->map[i] == NULL)
//         {
//             close(fd);
//             return (0);
//         }
//         i++;
//     }
//     game->map[i] = NULL;
//     close(fd);
//     return (1);
// }

// int get_length(t_game *game, int i) //done
// {
//     int j;

//     j = 0;
//     while (game->map[i][j])
//         j++;
//     return (j);
// }

// int check_rectangle(t_game *game) //done
// {
//     int i;
//     int length_of_line;

//     i = 0;
//     length_of_line = get_length(game, 0);
//     while (game->map[i])
//     {
//         if(get_length(game, i) != length_of_line)
//             return (0);
//         i++;
//     }
//     return (1);
// }

// int surrounded_by_walls(t_game *game) //done
// {
//     int i;
//     int last_line;
//     int len_of_line;

//     len_of_line = get_length(game, 0);
//     last_line = num_of_lines(game);
//     i = 0;
//     while (i < len_of_line)
//     {
//         if(game->map[0][i] != '1')
//             return (0);
//         if (game->map[last_line - 1][i] != '1')
//             return (0);
//         i++;
//     }
//     i = 0;
//     while (i < last_line)
//     {
//         if (game->map[i][0] != '1')
//             return (0);
//         if (game->map[i][len_of_line - 1] != '1')
//             return (0);
//         i++;
//     }
//     return (1);
// }

// int num_char_in_map(char **map, char c) //done
// {    
//     int y;
//     int x;
//     int count;

//     count = 0;
//     y = 0;
//     while (map[y])
//     {
//         x = 0;
//         while (map[y][x])
//         {
//             if (map[y][x] == c)
//                 count++;
//             x++;
//         }
//         y++;
//     }
//     return (count);
// }
// int check_exit_start_collectible(t_game *game) //done
// {
//     int y;
//     int x;

//     y = 0;
//     while (game->map[y])
//     {
//         x = 0;
//         while (game->map[y][x])
//         {
//             if (num_char_in_map(game->map, 'P') != 1)
//                 return (1);
//             if (num_char_in_map(game->map, 'C') < 1)
//                 return (2);
//             if (num_char_in_map(game->map, 'E') != 1)
//                 return (3);
//             if (game->map[y][x] != 'P' && game->map[y][x] != 'C' && game->map[y][x] != 'E' && game->map[y][x] != '1' && game->map[y][x] != '0')
//                 return (4);
//             x++;
//         }
//         y++;
//     }
//     return (0);
// }
// void print_message(int num_of_error) //done
// {
//     if (num_of_error == 1)
//         printf("Erorr\nThere is no Player in the map or more than 1 player");
//     if (num_of_error == 2)
//         printf("Erorr\nThere is no Collectible in the map");
//     if (num_of_error == 3)
//         printf("Erorr\nThere is no Exit in the map or more than 1 exit");
//     if (num_of_error == 4)
//         printf("Erorr\nThere is an undefined character");
// }

// int flood_fill(char **map, int playery, int playerx) //done
// {
//     map[playery][playerx] = '1';
//     if (map[playery + 1][playerx] != '1')
//         flood_fill(map, playery + 1, playerx);
//     if (map[playery- 1][playerx] != '1')
//         flood_fill(map, playery - 1, playerx);
//     if (map[playery][playerx + 1] != '1')
//         flood_fill(map, playery, playerx + 1);
//     if (map[playery][playerx - 1] != '1')
//         flood_fill(map, playery, playerx - 1);
//     return (num_char_in_map(map, 'C') == 0 && num_char_in_map(map, 'E') == 0);
// }

// int check_validation_exit_coll_path(t_game *game) //done
// {
//     t_game copy;
//     copy.name_map_file = game->name_map_file;
//     fill_map(num_of_lines(game), &copy);
//     if (!flood_fill(copy.map, game->y_player, game->x_player))
//     {
//         printf("Erorr\nthere is an collectible or the exit you can't take it");
//         return (0);
//     }
//     return (1);
// }

// int check_validation(t_game *game) //done
// {
//     int count;

//     count = 0;
//     if (!check_rectangle(game))
//     {
//         printf("Erorr\nIt's not a Rectangle map");
//         return (0);
//     }
//     if (!surrounded_by_walls(game))
//     {
//         printf("Erorr\nthe map not surrounded by walls");
//         return (0);
//     }
//     count = check_exit_start_collectible(game);
//     if (count)
//     {
//         print_message(count);
//         return (0);
//     }
//     if (!check_validation_exit_coll_path(game))
//         return (0);
//     return (1);
// }

// int handle_x_button(void *game) //done
// {
//     (void) game;
//     exit(0);
//     return(0);
// }

// void player_render(t_game *game, int keycode) //done
// {
//     if (keycode == 0x77)
//     {
//         mlx_put_image_to_window(game->mlx, game->win, game->player[0], game->x_player * 64, game->y_player * 64);
//     }
//     else if (keycode == 0x73)
//     {
//         mlx_put_image_to_window(game->mlx, game->win, game->player[1], game->x_player * 64, game->y_player * 64);
//     }
//     else if (keycode == 0x64)
//     {
//         mlx_put_image_to_window(game->mlx, game->win, game->player[3], game->x_player * 64, game->y_player * 64);
//     }
//     else if (keycode == 0x61)
//     {
//         mlx_put_image_to_window(game->mlx, game->win, game->player[2], game->x_player * 64, game->y_player * 64);
//     }
// }

// void render(t_game *game) //done
// {
//     int x = 0;
//     int y = 0;

//     game->num_of_coin = 0;
//     mlx_clear_window(game->mlx, game->win);
//     while (game->map[y])
//     {
//         x = 0;
//         while(game->map[y][x])
//         {
//             mlx_put_image_to_window(game->mlx, game->win, game->floor, x * 64, y * 64);
//             if (game->map[y][x] == '1')
//                  mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 64, y * 64);
//             if (game->map[y][x] == 'C')
//             {
//                  mlx_put_image_to_window(game->mlx, game->win, game->coin, x * 64, y * 64);
//                  game->num_of_coin++;
//             }
//             if (game->map[y][x] == 'E')
//                  mlx_put_image_to_window(game->mlx, game->win, game->exit, x * 64, y * 64);
//             x++;
//         }
//         y++;
//     }
//     mlx_put_image_to_window(game->mlx, game->win, game->player[3], game->x_player * 64, game->y_player * 64);
// }

// void find_player_position(t_game *game) //done
// {
//     int y;
//     int x;

//     y = 0;
//     while (game->map[y])
//     {
//         x = 0;
//         while (game->map[y][x])
//         {
//             if (game->map[y][x] == 'P')
//             {
//                 game->x_player = x;
//                 game->y_player = y;
//                 return ;
//             }
//             x++;
//         }
//         y++;
//     }
// }
// void take_coin(t_game *game) //done
// {
//     if (game->map[game->y_player][game->x_player] == 'C')
//     {
//         game->map[game->y_player][game->x_player] = '0';
//         game->num_of_coin--;
//     }
//     else if (game->map[game->y_player][game->x_player] == 'C')
//     {
//         game->map[game->y_player][game->x_player] = '0';
//         game->num_of_coin--;
//     }
//     else if (game->map[game->y_player][game->x_player] == 'C')
//     {
//         game->map[game->y_player][game->x_player] = '0';
//         game->num_of_coin--;
//     }
//     else if (game->map[game->y_player][game->x_player] == 'C')
//     {

//         game->map[game->y_player][game->x_player] = '0';
//         game->num_of_coin--;
//     }
// }

// void win_game(t_game *game) //done
// {
//     if (game->map[game->y_player][game->x_player] == 'E' && game->num_of_coin == 0)
//         exit(0);
// }

// void handle_movement(int keycode, t_game *game) //done
// {
//     if (keycode == 0x77 && game->map[game->y_player - 1][game->x_player] != '1')
//     {
//         game->y_player -= 1;
//         game->num_move++;
//         game->move = 1;
//     }
//     else if (keycode == 0x73 && game->map[game->y_player + 1][game->x_player] != '1')
//     {
//         game->y_player += 1;
//         game->num_move++;
//         game->move = 1;
//     }
//     else if (keycode == 0x64 && game->map[game->y_player][game->x_player + 1] != '1')
//     {
//         game->x_player += 1;
//         game->num_move++;
//         game->move = 1;
//     }
//     else if (keycode == 0x61 && game->map[game->y_player][game->x_player - 1] != '1')
//     {
//         game->x_player -= 1;
//         game->num_move++;
//         game->move = 1;
//     }
// }
// int handle_press(int keycode, void *param) //done
// {
//     t_game *game;

//     game  = (t_game *)param;
//     if (keycode == 0xff1b)
//         exit(0);
//     handle_movement(keycode, game);
//     if (game->move == 1)
//         printf("Number of move: %d\n", game->num_move);
//     game->move = 0;
//     take_coin(game);
//     win_game(game);
//     render(game);
//     player_render(game, keycode);
//     return (0);
// }

// int validation_map_path(t_game game) //done
// {
//     int len;
//     char path[4];
//     int i;
//     int j;

//     j = 0;
//     path[0] = '.';
//     path[1] = 'b';
//     path[2] = 'e';
//     path[3] = 'r';
//     len = ft_strlen(game.name_map_file);
//     i = len - 4;
//     if (len < 4)
//         return (0);
//     while(i < len)
//     {
//         if (game.name_map_file[i] != path[j])
//             return (0);
//         i++;
//         j++;
//     }
//     return (1);
// }

int main (int argc, char **argv)
{
    t_game game;
    
    if (argc < 2)
        return (0);
    game.name_map_file = argv[1];
    if (!validation_map_path(game))
        return (1);
    if (!fill_map(num_of_lines(&game), &game))
        return (1);
    find_player_position(&game);
    if(!check_validation(&game))
        return (1);
    game.player.move = 0;
    game.player.num_move = 0;
    game.window.mlx = mlx_init();
    game.window.win = mlx_new_window(game.window.mlx, get_length(&game, 0) * 64, num_of_lines(&game) * 64, "so_long");
    mlx_hook(game.window.win, 2, 1L<<0, handle_press, &game);
    mlx_hook(game.window.win, 17, 0, handle_x_button, &game);
    read_texture(&game);
    render(&game);
    mlx_loop(game.window.mlx);
}
