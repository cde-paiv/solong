#include "so_long.h"

static void		game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->y_player += 1;
		player_d(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->y_player -= 1;
		player_a(game);
	}
}
static int	exit_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		printf("moves %d/n", game->move);
	}
	return (0);
}

void	game_keys(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, game_events, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
	mlx_hook(game->win, 9, 1L << 21, map_draw);
}