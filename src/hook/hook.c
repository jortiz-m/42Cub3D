/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:14:07 by jortiz-m          #+#    #+#             */
/*   Updated: 2025/07/16 12:43:18 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_key_press(int key, void *param)
{
	t_game *cub3d;
	
	cub3d = (t_game *)param;
	if (key == KEY_ESC)
		return (mlx_loop_end(cub3d->mlx));
	if (key == KEY_W)
		cub3d->player.move.forward = true;
	else if (key == KEY_S)
		cub3d->player.move.back = true;
	else if (key == KEY_A)
		cub3d->player.move.left = true;
	else if (key == KEY_D)
		cub3d->player.move.right = true;
	else if (key == KEY_LEFT)
		cub3d->player.rotate.left = true;
	else if (key == KEY_RIGHT)
		cub3d->player.rotate.right = true;
	return (0);
}

int	handle_key_release(int key, void *param)
{
	t_game *cub3d;

	cub3d = (t_game *)param;
	if (key == KEY_W)
		cub3d->player.move.forward = false;
	else if (key == KEY_S)
		cub3d->player.move.back = false;
	else if (key == KEY_A)
		cub3d->player.move.left = false;
	else if (key == KEY_D)
		cub3d->player.move.right = false;
	else if (key == KEY_LEFT)
		cub3d->player.rotate.left = false;
	else if (key == KEY_RIGHT)
		cub3d->player.rotate.right = false;
	return (0);
}
