/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battlefield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:37:00 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/10 14:37:01 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void    champ_on_field(unsigned char *champ, header_t *head, unsigned char battle[MEM_SIZE], int numb)
{
    int     i;

    i = 0;
    while (i < head->prog_size)
    {
        battle[numb++] = champ[2192 + i];
        i++;
    }
}

t_base    battlefield(header_t **head)
{
    header_t        *current;
    int             count;
    int             position;
    t_base          base;

    base.name_proc = 1;
    position = 0;
    count = 0;
    current = *head;
    ft_bzero(base.battle, MEM_SIZE);
    while (current)
    {
        current = current->next;
        count++;
    }
    current = *head;
    if (count > 4 || count == 0)
    {
        printf("Champ_count NO");
        exit(0);
    }
    printf("->%d\n", current->prog_size);
    write(1, "+", 1);
    champ_on_field(current->full, current, base.battle, 0);
    current = current->next;
    while (current != NULL)
    {
        position += (MEM_SIZE / count);
        champ_on_field((*head)->full, current, base.battle, position);
        current = current->next;
    }
    return (base);
}
