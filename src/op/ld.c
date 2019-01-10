/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:55:12 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 20:58:04 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	log_ld(uint32_t cursor_id, int32_t value, int32_t r_id)
{
	ft_printf("P %4d | ld %d r%d\n", cursor_id, value, r_id);
}

void				ld(t_vm *vm, t_cursor *cursor)
{
	int32_t			value;
	int32_t			r_id;

	cursor->step += (OP_CODE_LEN + ARGS_CODE_LEN);
	value = get_op_arg(vm, cursor, 1, true);
	cursor->carry = (t_bool)(!value);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_ld(cursor->id, value, r_id);
}
