/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:32:42 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/26 13:32:43 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int     counting_lives(t_process **head)
{
    int     count;
    t_process *current;

    count = 0;
    current = *head;
    while (current != NULL)
    {
        count += current->live;
        current = current->next;
    }
    return (count);
}

void    kill_you(t_process **head)
{
    t_process *start;
    t_process *tmp;

    while (*head != NULL && (*head)->live == 0)
    {
        start = (*head)->next;
        free(*head);
        *head = start;
    }
    tmp = (*head);
    while (tmp != NULL)
    {
        start = tmp;
        tmp = tmp->next;
        if (tmp != NULL && tmp->live == 0)
        {
            start->next = tmp->next;
            free(tmp);
            tmp = start;
        }
    }
}

void    set_to_zero(t_process **head)
{
    t_process *current;

    current = *head;
    while (current != NULL)
    {
        current->live = 0;
        current = current->next;
    }
}

void    cycle_die(t_process **head, t_base *base)
{
    int     count_live;

    count_live = counting_lives(head);
    kill_you(head);
    if (count_live < NBR_LIVE && base->max_check == 0) {
        base->cycle_to_die = base->cycle_to_die - CYCLE_DELTA;
        base->max_check = 10;
    }
    else if (count_live < NBR_LIVE)
        base->max_check--;
    set_to_zero(head);
}
