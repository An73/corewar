/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 19:34:05 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/10 19:34:06 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

header_t    *new_champ(char *argv, int i)
{
    header_t    *new;

    new = (header_t*)malloc(sizeof(header_t));
    new->full = read_str(argv, &new);
    validate_champ(new->full, new);
    new->name = i * -1;
    new->next = NULL;
    return (new);
}

void    pushback(header_t **head, header_t *new)
{
    header_t    *current;

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
