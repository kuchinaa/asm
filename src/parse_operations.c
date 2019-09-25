/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <vpalamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:03:33 by vpalamar          #+#    #+#             */
/*   Updated: 2019/09/21 19:03:42 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_int2(int arr[3], int i, int j, int k)
{
	arr[0] = i;
	arr[1] = j;
	arr[2] = k;
}

static void	get_int(int arr[3][3], uint8_t arg, int i)
{
	if (arg == 0)
		get_int2(arr[i], 0, 0, 0);
	if (T_REG == arg || T_DIR == arg || T_IND == arg)
	{
		arr[i][0] = (T_REG == arg) ? 1 : 0;
		arr[i][1] = (T_DIR == arg) ? 2 : 0;
		arr[i][2] = (T_IND == arg) ? 3 : 0;
	}
	else if ((T_REG + T_DIR + T_IND) == arg)
		get_int2(arr[i], 1, 2, 3);
	else if ((T_REG + T_DIR) == arg)
		get_int2(arr[i], 1, 2, 0);
	else if ((T_REG + T_IND) == arg)
		get_int2(arr[i], 1, 0, 3);
	else if ((T_DIR + T_IND) == arg)
		get_int2(arr[i], 0, 2, 3);
}

t_operation	*parse_operation(t_operation *operation)
{
	int		i;
	int		j;
	int		arr[3][3];

	i = 0;
	while (i < 16)
	{
		j = -1;
		while (++j < 3)
			get_int(arr, g_op_tab[i].args[j], j);
		if (!operation)
			operation = operation_init(g_op_tab[i], arr);
		else
			operation_add(operation, g_op_tab[i], arr);
		i++;
	}
	return (operation);
}
