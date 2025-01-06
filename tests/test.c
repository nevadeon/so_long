/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:32:07 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:47 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *stack)
{
	t_number_list	*list;

	printf("%c ->", stack->name);
	list = stack->list;
	while (list != NULL)
	{
		printf("%3d ", list->number);
		list = list->next;
	}
	printf("\n");
}

t_stack	*stack_from_string(char *str, char c)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->list = list_from_tab(ft_split(str, ' '));
	stack->len = ft_lstsize((t_list *)stack->list);
	stack->max = find_max(stack->list);
	stack->min = find_min(stack->list);
	stack->name = c;
	return (stack);
}
