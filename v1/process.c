/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 15:35:01 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/12 15:35:03 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

t_process   *new_process(int position, int name)
{
    t_process *new_process;

    new_process = (t_process*)malloc(sizeof(t_process));
    new_process->carry = 0;
    ft_bzero(new_process->reg, 16);
    new_process->live = 0;
    new_process->position = position;
    new_process->cycle = -1;
    new_process->name = name;
    new_process->next = NULL;
    return (new_process);
}

void    pushback_proc(t_process **head, t_process *new)
{
    t_process   *current;

    current = *head;
    if (*head != NULL)
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
    else
        *head = new;
}

void    start_position(t_process **head, int number_champ, t_base *base)
{
    int     position;
    int     num;

    position = 0;
    num = 1;
    pushback_proc(head, new_process(0, base->name_proc));
    base->name_proc = 1;
    while (num != number_champ)
    {
        position += (MEM_SIZE / number_champ);
        //name--;
        pushback_proc(head, new_process(position, base->name_proc));
        base->name_proc++;
        num++;
    }
}
