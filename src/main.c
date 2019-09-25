/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:46:06 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/25 14:06:37 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

void	add_head(t_asm *all, t_list *l)
{
	int				i;
	int				size;
	unsigned int	magic;

	magic = REV(g_header.magic);
	write(all->fd, &magic, sizeof(magic));
	write(all->fd, &g_header.prog_name, PROG_NAME_LENGTH);
	ADD_NULL(all->fd);
}

void	write_asm(t_list *list)
{
	t_asm		all;

	ft_bzero(&all, sizeof(t_asm));
	g_header.magic = COREWAR_EXEC_MAGIC;
	FILE_CHECK((all.fd = open("ex.cor", O_WRONLY | O_CREAT | O_TRUNC, 0777)));
	add_head(&all, list);
	add_marker(&all, list);
	g_header.prog_size = REV(g_header.prog_size);
	write(all.fd, &g_header.prog_size, sizeof(g_header.prog_size));
	write(all.fd, &g_header.comment, COMMENT_LENGTH);
	ADD_NULL(all.fd);
	add_champion_code(&all);
	close(all.fd);
}

void	check_file_name(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (len < 2 || name[len - 1] != 's' || name[len - 2] != '.')
	{
		ft_printf(RED"Can't read source file %s\n"RESET, name);
		exit(1);
	}
}

void	init_param(void)
{
	g_name.string = NULL;
	g_name.end = false;
	g_comment.string = NULL;
	g_comment.end = false;
}

int		main(int ac, char **av)
{
	t_list		*list;

	if (ac == 2)
	{
		ft_bzero(&g_header, sizeof(t_header));
		check_file_name(av[1]);
		init_param();
		list = get_content(NULL, av[1]);
		list = parse(list);
		operations(list);
		printf(BLUE"name = %s\n"RESET, g_header.prog_name);
		printf(BLUE"comment = %s\n"RESET, g_header.comment);
		write_asm(list);
	}
	else if (ac == 1)
		ft_printf(RED"Missing file\n"RESET);
	else if (ac > 2)
		ft_printf(RED"Too much files\n"RESET);
	return (0);
}
