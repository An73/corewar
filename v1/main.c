/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:22:12 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/08 17:22:16 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <stdio.h>

unsigned char    *read_str(char *file, header_t **head)
{
    unsigned char    *str;
    int     len;
    int     fd;

    fd = open(file, O_RDONLY);
    len = (int)lseek(fd, 0, SEEK_END);
    (*head)->len = len;
    lseek(fd, 0, SEEK_SET);
    str = (unsigned char *)malloc(sizeof(unsigned char) * len + 1);
    read(fd, str, len);

    return (str);
}

char    check_name(char *argv)
{
    int     i;

    i = 0;
    while (argv[i] != '\0')
        i++;
    if (argv[i - 1] == 'r' && argv[i - 2] == 'o' && argv[i - 3] == 'c' && argv[i - 4] == '.')
        return (1);
    return (0);
}

int     main(int argc, char **argv)
{
    unsigned  char      *str;
    int     i;
    header_t            *head;
    t_flag              flag;
    t_base              base;

    i = 1;
    head = NULL;
    while (i < argc)
    {
        if (check_name(argv[i])) {
            pushback(&head, new_champ(argv[i], i));
        }
        i++;
    }

    printf("%s\n", head->prog_name);
    printf("%s\n", head->comment);
    printf("prog_size = %d\nlen = %d\n", head->prog_size, head->len);
    base = battlefield(&head);
    base.cycle_to_die = CYCLE_TO_DIE;
    base.max_check = MAX_CHECKS;

    cycle(i - 1, &base, &head);
    //ВЫВОД
    printf("\n***\n");
    i = 0;
    while (i < MEM_SIZE)
    {
        printf("%.2x  ", base.battle[i]);
        i++;
        if (i % 64 == 0)
            printf("\n");
    }
    printf("\n***\n");
}
