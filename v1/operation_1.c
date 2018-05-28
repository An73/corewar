/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:24:27 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/12 18:24:31 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

union convert{
    unsigned char a[4];
    //unsigned char b;
    //unsigned char c;
    //unsigned char d;
    int32_t n;
};

void    op_live(header_t **head, t_process *proc, t_base *base, int i)
{
    header_t *current;
    union convert conv;

    conv.n = 0;
    if (proc->cycle == -1)
        proc->cycle = 10;
    else if (proc->cycle == 0) {
        current = *head;
        proc->live++;
        conv.a[0] = base->battle[i + 1];
        //ft_printf("%p ", &conv.a);
        conv.a[1] = base->battle[i + 2];
        //ft_printf("%p ", &conv.b);
        conv.a[2] = base->battle[i + 3];
        //ft_printf("%p ", &conv.c);
        conv.a[3] = base->battle[i + 4];
        //ft_printf("%p\n", &conv.d);
        while (current != NULL) {
            if (conv.n == current->name) {
                base->champ_win = conv.n;
            }
            current = current->next;
        }
        ft_printf("n = %d\n", conv.n);
        ft_printf("P   %d | live %d\n", proc->name, base->champ_win);
        ft_printf("%x -> ", proc->position);
        proc->cycle = -1;
        proc->position += 5;
        ft_printf("%x\n", proc->position);
    }
    else
        proc->cycle--;
}

void    op_and(t_process *proc, t_base *base, int i)
{
    int32_t first = 0;
    int32_t second = 0;

    if (proc->cycle == -1)
        proc->cycle = 6;
    else if (proc->cycle == 0) {
        ft_printf("op_and\n");
        if (enc_byte(base->battle[i + 1], 3) == T_REG) {
            i += 2;
            if (enc_byte(base->battle[i], 1) == T_REG) {
                first = proc->reg[base->battle[i + 1]];
                i++;
            }
            else if (enc_byte(base->battle[i], 1) == T_DIR) {
                first = conv(base->battle[i + 1], base->battle[i + 2], base->battle[i + 3], base->battle[i + 4]);
                i += 5;
            }
            else if (enc_byte(base->battle[i], 1) == T_IND) {
                first = conv(0, 0, base->battle[i + 1], base->battle[i + 2]);
                first = base->battle[proc->position + first];
                i += 3;
            }

            if (enc_byte(base->battle[i], 1) == T_REG) {
                second = proc->reg[base->battle[i + 1]];
                i++;
            }
            else if (enc_byte(base->battle[i], 1) == T_DIR) {
                second = conv(base->battle[i + 1], base->battle[i + 2], base->battle[i + 3], base->battle[i + 4]);
                i += 5;
            }
            else if (enc_byte(base->battle[i], 1) == T_IND) {
                second = conv(0, 0, base->battle[i + 1], base->battle[i + 2]);
                second = base->battle[proc->position + first];
                i += 3;
            }

            proc->reg[base->battle[i]] = first & second;
            if (proc->reg[base->battle[i]] == 0)
                proc->carry = 1;
            else
                proc->carry = 0;
        }
        proc->cycle = -1;
        proc->position++;
    }
    else
        proc->cycle--;
}
