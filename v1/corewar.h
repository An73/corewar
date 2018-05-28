/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:21:40 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/09 15:24:55 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COREWAR_H
# define __COREWAR_H
# include "libft.h"
# include <fcntl.h>
# include <zconf.h>
# include "op.h"
# include "get_next_line.h"

typedef struct		s_flag
{
    int			d;
    int			s;
    int	        v;
    char        a;
    char        b;
    char        stealth;
}					t_flag;

typedef struct      s_process
{
    char                carry;
    int32_t             reg[16];
    int                 live;
    int                 position;
    int                 cycle;
    int                 name;
    struct  s_process   *next;

}                   t_process;

typedef struct      s_base
{
    unsigned char  battle[MEM_SIZE];
    int             name_proc;
    int             champ_win;

    int             max_check;
    int             cycle_to_die;
}                   t_base;

void    validate_champ(unsigned char *champ, header_t *head);
t_base    battlefield(header_t **head);
void    pushback(header_t **head, header_t *new);
header_t    *new_champ(char *argv, int i);
unsigned char    *read_str(char *file, header_t **head);
char	enc_byte(unsigned char enc, char argum);
int32_t     conv(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
void    cycle_die(t_process **head, t_base *base);
void    cycle(int num_champ, t_base *base, header_t **header);

void    op_live(header_t **head, t_process *proc, t_base *base, int i);
void    op_and(t_process *proc, t_base *base, int i);

void    start_position(t_process **head, int number_champ, t_base *base);


#endif
