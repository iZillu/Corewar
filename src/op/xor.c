/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:53:49 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 21:03:24 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	log_xor(uint32_t cursor_id,
							int32_t value_1,
							int32_t value_2,
							int32_t r_id)
{
	ft_printf("P %4d | xor %d %d r%d\n", cursor_id, value_1, value_2, r_id);
}

void				xor(t_vm *vm, t_cursor *cursor)
{
	int32_t			value_1;
	int32_t			value_2;
	int32_t			value;
	int32_t			r_id;

	cursor->step += OP_CODE_LEN + ARGS_CODE_LEN;
	value_1 = get_op_arg(vm, cursor, 1, true);
	value_2 = get_op_arg(vm, cursor, 2, true);
	value = value_1 ^ value_2;
	cursor->carry = (t_bool)(!value);
	r_id = get_byte(vm, cursor->pc, cursor->step);
	cursor->reg[INDEX(r_id)] = value;
	cursor->step += REG_LEN;
	if (vm->log & OP_LOG)
		log_xor(cursor->id, value_1, value_2, r_id);
}
