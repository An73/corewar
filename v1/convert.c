/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:45:10 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/25 14:45:14 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

union convert{
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    int32_t n;
};

int32_t     conv(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    union convert conv;

    conv.a = a;
    conv.b = b;
    conv.c = c;
    conv.d = d;
    return (conv.n);
}
