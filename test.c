#include <mlx.h>
#include <stdlib.h>
#include "get_next_line.h"


typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *player;
    int     x;
    int     y;
    int     player_w;
    int     player_h;
    int     key_w;
    int     key_a;
    int     key_s;
    int     key_d;
    char    **map;
} t_game;

int get_length(t_game game, int i)
{
    int j;

    j = 0;
    while (game.map[i][j])
        j++;
    return (j);
}

int check_rectangle(t_game game)
{
    int i;
    int length_of_line;

    i = 0;
    length_of_line = get_length(game, 0);
    while (game.map[i])
    {
        if(get_length(game, i) != length_of_line)
            return (1);
        i++;
    }
    return (0);

}
int check_validation(t_game game)
{
    if(check_rectangle(game))
    {
        printf("It's not a Rectangle map");
        return (1);
    }
    return (0);
}

int num_of_lines(char *map)
{
    int fd;
    int i;
    char buffer;

    fd = open(map, O_RDONLY);
    i = 1;
    while (1)
    {
        int check = read(fd, &buffer, 1);
        if (check == -1)
            return (0);
        if (check == 0)
            break;
        if (buffer == '\n')
            i++;
    }
    close(fd);
    return (i);
}

int    fill_map(int num_line, t_game *game, char *map)
{
    int i;
    int fd;

    fd = open(map, O_RDONLY);
    i = 0;
    game->map = malloc(num_line * sizeof(char *) + 1);

    while(i < num_line)
    {
        game->map[i] = get_next_line(fd);
        i++;
    }
    game->map[i] = NULL;
    if (!check_validation(*game))
        return (1);
    // i = 0;
    // while(i < num_line)
    // {
    //     printf("%s", game.map[i]);
    //     i++;
    // }
    // close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    int num_line;
    t_game game;
    int check;

    if (argc != 2)
        return (0);
    //game.name_map = argv[0]
    num_line = num_of_lines(argv[1]);
    if (num_line == 0)
    {
        printf("INVALID NAME");
        return(0);
    }
    check = fill_map(num_line, &game, argv[1]);
    if (check)
        return (0);

    return (0);
}


