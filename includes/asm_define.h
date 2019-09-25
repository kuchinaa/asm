/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuchina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 16:02:27 by akuchina          #+#    #+#             */
/*   Updated: 2019/09/25 16:02:29 by akuchina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DEFINE_H
# define ASM_DEFINE_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1u
# define T_DIR					2u
# define T_IND					4u
# define T_LAB					8u

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define FILE_CHECK(fd) if(fd == -1){write (1, FILE_ERROR, 18);exit(1);}

# define REV_1(x) ((x&0xff000000)>>24) | (((x&0x00ff0000)<<8)>>16)
# define REV(x) (REV_1(x) | (((x&0x0000ff00)>>8)<<16) | ((x&0x000000ff)<<24))

# define ADD_NULL(fd) write(fd, "\0\0\0\0", 4);

# define GET_MARK(l) ((t_marker *)(l->content))
# define GET_COMM(l) ((t_command *)(l->content))

# define FILE_ERROR "Cannot open file.\n"

#endif
