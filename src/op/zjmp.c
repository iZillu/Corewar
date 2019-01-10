/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:53:43 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 21:03:30 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	log_zjmp(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | zjmp %d %s\n",
									cursor->id,
									addr,
									(cursor->carry) ? "OK" : "FAILED");
}

void				zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t 		addr;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	if (cursor->carry)
	{
		if (vm->vs)
			clear_cursor(vm, cursor);
		cursor->pc = calc_addr(cursor->pc + (addr % IDX_MOD));
		if (vm->vs)
			draw_cursor(vm, cursor);
		cursor->step = 0;
	}
	if (vm->log & OP_LOG)
		log_zjmp(cursor, addr);
}
