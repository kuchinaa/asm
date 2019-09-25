/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:04:04 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/25 16:04:06 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCT_H
# define ASM_STRUCT_H

# include "asm_define.h"

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct s_operation		t_operation;

struct							s_operation
{
	char						*name;
	int							arr[3][3];
	int							num_arg;
	t_operation					*next;
};

typedef struct					s_com_name
{
	char						*string;
	bool						end;
}								t_com_name;

typedef struct					s_tuple
{
	t_list						*list;
	bool						rewrite;
}								t_tuple;

typedef	struct					s_marker
{
	char						*marker;
	uint8_t						size;
}								t_marker;

typedef	struct					s_command
{
	unsigned int				command;
	char						*name;
	char						**param;
	uint8_t						size;
}								t_command;

typedef	struct					s_asm
{
	int							fd;
	t_list						*markers;
	t_list						*command_start;
	t_list						*command_end;
}								t_asm;

typedef struct					s_op
{
	char						*name;
	uint8_t						count_of_arg;
	uint8_t						args[3];
	uint8_t						index;
	uint16_t					pause;
	char						*instruction;
	uint8_t						type_code;
	uint8_t						dir_ind;
}								t_op;

#endif
