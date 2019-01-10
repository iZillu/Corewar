/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:15:32 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/10 21:28:35 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static const t_op	op_tab[17] =
{
	{0, 0, {0}, 0, 0, 0, 0, 0, NULL},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, &live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, &ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, &st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, &add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, &sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, &zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1, &ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1, &sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, &fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, &lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1, &lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, &lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, &aff}
};

static inline void	update_op_id(t_cw *cw, t_coach *coach)
{
	coach->op_id = cw->map[coach->pc]
	if (cw->map[coach->pc] >= 1 && cw->map[coach->pc] <= 16)
		coach->cycles_to_wait = op_tab[coach->op_id].cycles;
}

static inline void	process_op(t_coach *coach, t_cw *cw)
{
	t_op			*op;

	op = NULL;
	if (!coach->cycles_to_wait)
	{
		update_op_id(coach, cw);
		if (coach->op_id >= 1 && coach->op_id <= 16)
			op = &op_tab[coach->op_id]
	}
	else
		coach->cycles_to_wait--;
	
}

void		start_game(t_cw *cw)
{
	t_coach	*crnt_coach;

	while(cw->amt_coaches)
	{
		// if (-dump == true)
		// {
		// 	print_map()
		// 	exit(0);
		// }
		crnt_coach = cw->coach;
		while (crnt_coach)
		{
			process_op(crnt_coach, cw);
			crnt_coach = crnt_coach->next;
		}
	}
}