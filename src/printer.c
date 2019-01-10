/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <hmuravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:08:00 by hmuravch          #+#    #+#             */
/*   Updated: 2019/01/09 16:37:29 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_help(void)
{
    ft_printf("Usage: ./corewar [-a (-dump|-d) <num> (-shed|-s) <num> -l"\
							" <num>] [-v] [-n <num>] <champion.cor> <...>\n");
	// ft_printf("    %-11s : Print output from \"aff\" (Default is off)\n", "-a");
	// ft_printf("    %-11s : Dump memory (32 octets per line)"\
	// 						" after <num> cycles and exit\n", "-dump <num>");
	// ft_printf("    %-11s : Dump memory (64 octets per line)"\
	// 						" after <num> cycles and exit\n", "-d    <num>");
	// ft_printf("    %-11s : Run <num> cycles, dump memory (32 octets per line),"\
	// 						" pause and repeat\n", "-show <num>");
	// ft_printf("    %-11s : Run <num> cycles, dump memory (64 octets per line),"\
	// 						" pause and repeat\n", "-s    <num>");
	// ft_printf("    %-11s : Log levels\n", "-l    <num>");
	// ft_printf("            %9s : Show lives\n", "1 ");
	// ft_printf("            %9s : Show cycles\n", "2 ");
	// ft_printf("            %9s : Show operations\n", "4 ");
	// ft_printf("            %9s : Show deaths\n", "8 ");
	// ft_printf("            %9s : Show PC movements\n", "16");
	// ft_printf("    %-11s : Run visualizer\n", "-v");
	// ft_printf("    %-11s : Set <num> of the next player\n", "-n    <num>");
	exit(0);
}