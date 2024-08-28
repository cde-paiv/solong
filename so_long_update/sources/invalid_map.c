/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:15:52 by marvin            #+#    #+#             */
/*   Updated: 2024/08/28 11:15:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **make_area(char **map, t_game *game)
{
    char    **new;
    int i;
    int j;

    i = 0;
    new = malloc(sizeof(char*) * game->map_h);
    if (!new)
        exit_game(game);
    while (i < game->map_h)
    {
        new[i] = malloc(game->map_w + 1);
        if (!new[i])
            exit_game(game);
        j = 0;
        while (j < game->map_w)
        {
            new[i][j] = map[i][j];
            j++;
        }
        new[i][game->map_w] = '\0';
        i++;
    }
    return (new);
}

void    flood_fill(t_game *game, char **new, int x, int y)
{
    if (x < 0 || y < 0 || x >= game->map_h|| y >= game->map_w)
        return (0);
    if(new[x][y] == 'C' || new[x][y] == 'E' || new[x][y] == '0'
        || new[x][y] == 'P')
    {
        new[x][y] = '2';
        flood_fill(game, new, x + 1, y);
        flood_fill(game, new, x - 1, y);
        flood_fill(game, new, x, y + 1);
        flood_fill(game, new, x, y - 1);
    }
}
