/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:52:00 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 20:57:15 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		aff(t_vm *vm, t_cursor *cursor)
{
	int32_t	r_id;
	int32_t	value;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	value = cursor->reg[INDEX(r_id)];
	cursor->step += REG_LEN;
	if (vm->display_aff)
		ft_printf("Aff: %c\n", (char)value);
	if (vm->vs)
	{
		vm->vs->aff_symbol = (char)value;
		vm->vs->aff_player = cursor->player;
	}
}
