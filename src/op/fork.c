/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:55:17 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 20:57:51 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

inline static void	log_fork(t_cursor *cursor, int32_t addr)
{
	ft_printf("P %4d | fork %d (%d)\n",
										cursor->id,
										addr,
										cursor->pc + addr % IDX_MOD);
}

void				fork(t_vm *vm, t_cursor *cursor)
{
	int32_t			addr;
	t_cursor		*new;

	cursor->step += OP_CODE_LEN;
	addr = get_op_arg(vm, cursor, 1, true);
	new = duplicate_cursor(cursor, addr % IDX_MOD);
	add_cursor(&(vm->cursors), new);
	vm->cursors_num++;
	if (vm->log & OP_LOG)
		log_fork(cursor, addr);
}
