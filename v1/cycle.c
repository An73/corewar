/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:35:59 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/12 14:36:01 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void    operation_part_1(int i, t_process *current, t_base *base, header_t **header)
{
    if (base->battle[i] == 1)
        op_live(header, current, base, i);
    /*else if (battle[i] == 2)
        op_ld();
    else if (battle[i] == 3)
        op_st();
    else if (battle[i] == 4)
        op_add();
    else if (battle[i] == 5)
        op_sub();*/
    else if (base->battle[i] == 6)
        op_and(current, base, i);
    /*else if (battle[i] == 7)
        op_or();
    else if (battle[i] == 8)
        op_xor();*/
}

void    run(t_base *base, t_process *current, header_t **header)
{
    int     i;

    i = current->position;
    if (base->battle[i] >= 1 && base->battle[i] <= 8)
        operation_part_1(i, current, base, header);
    /*else if (base->battle[i] >= 9 && base->battle[i] <= 16)
        operation_part_2();*/
    else
        current->position++;
}

void    run_process(t_base *base, t_process **head, header_t **header)
{
    t_process   *current;

    current = *head;
    while (current != NULL)
    {
        run(base, current, header);
       /* if (current->cycle == 0)
            run(base, current, header);
        else
            current->cycle--;*/
        current = current->next;
    }
}

void    cycle(int num_champ, t_base *base, header_t **header)
{
    t_process   *head;
    int         i = 1;

    head = NULL;
    start_position(&head, num_champ, base);
    while (head != NULL)
    {
        ft_printf("cycle = %d\n", i);
        run_process(base, &head, header);
        i++;
        if (i % base->cycle_to_die == 0)
            cycle_die(&head, base);
    }
}
