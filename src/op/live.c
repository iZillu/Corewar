/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:54:54 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 20:57:08 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	log_live(uint32_t cursor_id, int32_t player_id)
{
	ft_printf("P %4d | live %d\n", cursor_id, player_id);
}

inline static void	log_live_msg(int32_t player_id, char *player_name)
{
	ft_printf("Player %d (%s) is said to be alive\n",
													player_id,
													player_name);
}

void				live(t_vm *vm, t_cursor *cursor)
{
	int32_t			player_id;
	t_player		*player;

	cursor->step += OP_CODE_LEN;
	player_id = get_op_arg(vm, cursor, 1, false);
	vm->lives_num++;
	cursor->last_live = vm->cycles;
	player = NULL;
	if (player_id <= -1 && player_id >= -((int32_t)vm->players_num))
	{
		player = vm->players[INDEX(FT_ABS(player_id))];
		player->last_live = vm->cycles;
		player->current_lives_num++;
		vm->last_alive = player;
		if (vm->vs)
		{
			vm->vs->map[cursor->pc].wait_cycles_live = CYCLE_TO_WAIT;
			vm->vs->map[cursor->pc].player_live = player;
		}
	}
	if (vm->log & OP_LOG)
		log_live(cursor->id, player_id);
	if (vm->log & LIVE_LOG && player)
		log_live_msg(FT_ABS(player_id), player->name);
}
