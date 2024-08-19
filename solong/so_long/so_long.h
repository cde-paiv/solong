/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-paiv <cde-paiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:34:53 by cde-paiv          #+#    #+#             */
/*   Updated: 2024/08/19 17:58:51 by cde-paiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	char	**map;
	int		img_w;
	int		img_h;
	int		map_w;
	int		map_h;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		move;
	int		endgame;
}	t_game;

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

int		map_checker(t_game *game);
int		exit_game(t_game *game);
int		map_draw(t_game *game);
char	**read_map(char *path);
void	game_keys(t_game *game);
void	free_map(char **map);
void	img_draw(t_game *game, void *image, int x, int y);

#endif
