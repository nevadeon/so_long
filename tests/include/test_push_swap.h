/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:07:38 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/17 13:13:23 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_PUSH_SWAP_H
# define TEST_PUSH_SWAP_H

# include <assert.h>
# include <stdio.h>
# include "push_swap.h"

# define ft_arena_alloc malloc
# define exit(error_code) fprintf(stderr, "exit was called with %d\n", error_code);


/* debug */
t_stack			*stack_from_string(char *str, char c);
void			printlist(t_stack *stack);
void			turk(t_stack *a, t_stack *b);
t_number_list	*list_from_tab(char	**tab);

#endif
