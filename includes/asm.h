/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:42:51 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/25 14:26:39 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdio.h>
# include <sys/stat.h>
# include <stdbool.h>
# include "../libft/libft.h"

# include "asm_struct.h"
# include "asm_define.h"

t_com_name			g_name;
t_com_name			g_comment;
t_list				*g_head;

typedef char		t_arg_type;
t_header			g_header;
t_op				g_op_tab[17];

void				add_marker(t_asm *all, t_list *list);
void				add_champion_code(t_asm *all);
uint8_t				command_size(t_command *comm);

t_list				*list_init(char *line);
t_list				*list_add(t_list *list, char *line);
t_list				*list_add_data(t_list *list, char *line);
t_list				*list_insert(t_list *list, char *line);
t_list				*list_free(t_list *list);

t_list				*get_content(t_list *list, char *file);

/*
**handle_line
*/

void				delete_comment(char *line);
char				*delete_tabs(char *line);
char				*delete_spaces(char *line);
bool				handle_point(t_list *list, char *line,
						int i, bool marker);
void				put_space_after_operation(t_list *list);
void				write_name_comment(void);

t_list				*parse(t_list *list);

/*
**operations
*/

void				operations(t_list *list);
t_operation				*parse_operation(t_operation *operation);

t_operation			*operation_init(t_op tab, int arr[3][3]);
t_operation			*operation_add(t_operation *o, t_op tab, int arr[3][3]);

/*
**arguments T_REG T_DIR T_IND
*/

int					check_reg(char *line, t_operation
						*oper, int arg, int number_arg);
int					check_dir(char *line, t_operation
						*oper, int arg, int number_arg);
int					check_ind(char *line, t_operation
						*oper, int arg, int number_arg);

void				handle_name_comment(char *l);

void				error_exit(char *line);

#endif
