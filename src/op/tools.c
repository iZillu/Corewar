/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:04:55 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/15 21:11:33 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_coach				*clone_coach(t_coach *crnt_coach, int shift)
{
	int		i;
	t_coach	*new_coach;

	i = 0;
	shift = (coach->pc + shift) % MEM_SIZE;
	// new_coach = init_coach(crnt_coach->player, shift); 
	while (++i < REG_NUMBER)
		new_coach->reg[i] = crnt_coach->reg[i];
	new_coach->carry = crnt_coach->carry;
	new_coach->last_live = crnt_coach->last_live;
	return (new_coach);
}

static inline int	read_bytecode(t_cw *cw, int size, int position)
{
	int		i;
	int		res;
	bool	minus;

	i = 0;
	res = 0;
	minus = (cw->map[(position) % MEM_SIZE] & 128) ? true : false ;
	while (size)
	{
		if (minus)
			res += ((cw->map[(position + size - 1) % MEM_SIZE] ^ 255) << (i * 8));
		else
			res += cw->map[(position + size - 1) % MEM_SIZE] << (i * 8);
		i++;
		size--;
	}
	if (minus)
		res = ~res;
	return (res);
}

int					parse_args(t_cw *cw, t_coach *coach, int num, t_op *op)
{
	int		id;
	int		res;
	int		position;

	res = 0;
	id = cw->map[(coach->pc + coach->shift) % MEM_SIZE];
	if (coach->arg_type[num] == T_REG)
		res = coach->reg[id];
	else if (coach->arg_type[num] == T_DIR)
		res = read_bytecode(cw, op->label_size, coach->pc + coach->shift);
	else if (coach->arg_type[num] == T_IND)
	{
		position = read_bytecode(cw, IND_SIZE, coach->pc + coach->shift);
		if (coach->op_id != 1 && coach->op_id != 13)
			position = position % IDX_MOD;
		res = read_bytecode(cw, DIR_SIZE, coach->pc + position);
	}
	coach->shift += shift_size(coach->arg_type[num], op);
	return (res);
}
