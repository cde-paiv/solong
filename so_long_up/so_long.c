/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:57:49 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/08/20 13:57:49 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int  argv_check(char *argv)
{
    int i;

    if (!argv)
        return (0);
    i = 0;
    while (argv[i])
        i++;
    i -= 1;
    if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b' && argv[i - 3] == '.' )
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    t_game  game;

    if (argc == 2)
    {
        game.map = read_map(argv[1]);
        if (map_checker(&game) && argv_check(argv[1]))
        {
            game_init(&game);
            game_keys(&game);
            mlx_loop(game.mlx);
        }
        else
        {
            if (game.map)
                free_map(game.map);
            printf("Invalid Map");
            exit (1);
        }
    }
    else
    {
        printf("error");
        exit (1);
    }
    return (0);
}