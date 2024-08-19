/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:33:30 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/08/19 17:17:51 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_draw(game, image, x, y);
}

static void	exit_draw(t_game *game, void *image, int x, int y)
{
	if (game->n_colect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, ".xpm", &game->img_w, &game->img_h);
	}
	img_draw(game, image, x, y);
}

int	map_draw(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 1)
				img_draw(game, game->img_wall, x, y);
			else if (game->map[x][y] == '0')
				img_draw(game, game->img_backg, x, y);
			else if (game->map[x][y] == 'P')
				img_draw(game, game->img_player, x, y);
			else if (game->map[x][y] == 'C')
				img_draw(game, game->img_colect, x, y);
			else if (game->map[x][y] == 'E')
				exit_draw(game, game->img_exit, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
