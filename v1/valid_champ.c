/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:31:32 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/09 15:31:34 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

void    validate_magic(unsigned char *champ)
{
    int     magic;
    int     buf;

    magic = 0;
    buf = champ[0] << 24;
    magic |= buf;
    buf = champ[1] << 16;
    magic |= buf;
    buf = champ[2] << 8;
    magic |= buf;
    magic |= champ[3];
    if (magic != COREWAR_EXEC_MAGIC)
        exit(0);
    else
        printf("magic = YES\n");
}

void    validate_name(unsigned char *champ, header_t *head)
{
    int     i;

    i = 4;
    while (champ[i] != '\0' && i < 133)
    {
        head->prog_name[i-4] = champ[i];
        i++;
    }
    if (i == 133)
    {
        printf("name = NO_1\n");
        exit(0);
    }
    while (i < 133)
    {
        if (champ[i] != '\0')
        {
            printf("name = NO_2\n");
            exit(0);
        }
        i++;
    }
    printf("name = YES\n");
}

void    validate_commit(unsigned char *champ, header_t *head)
{
    int     i;

    i = 140;
    while (champ[i] != '\0' && i < 2188)
    {
        head->comment[i-140] = champ[i];
        i++;
    }
    if (i == 2188)
    {
        printf("commit = NO\n");
        exit(0);
    }
    printf("commit = YES\n");
}

void    validate_prog_size(unsigned char *champ, header_t *head)
{
    unsigned int     size;
    unsigned int     buf;

    size = 0;
    buf = 0;
    buf = champ[136] << 24;
    size |= buf;
    buf = champ[137] << 16;
    size |= buf;
    buf = champ[138] << 8;
    size |= buf;
    size |= champ[139];
    head->prog_size = size;
}

void    validate_champ(unsigned char *champ, header_t *head)
{
    validate_magic(champ);
    validate_name(champ, head);
    validate_prog_size(champ, head);
    validate_commit(champ, head);
    validate_prog_size(champ, head);
    if ((head->len - 2192) != head->prog_size)
    {
        printf("Prog_size NO\n");
        exit(0);
    }
}
