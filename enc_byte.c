/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enc_byte.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkotenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:55:48 by dkotenko          #+#    #+#             */
/*   Updated: 2018/05/24 13:55:54 by dkotenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char 	arg_1(unsigned char enc)
{
	unsigned char	num;

	num = enc >> 6;
	//сравнение
	if (num == 1)
		return (1);
	else if (num == 2)
		return (2);
	else if (num == 3)
		return (4);
}

char 	arg_2(unsigned char enc)
{
	unsigned char	num;

	num = enc << 2;
	num = num >> 6;
	//сравнение
	if (num == 1)
		return (1);
	else if (num == 2)
		return (2);
	else if (num == 3)
		return (4);
}

char 	arg_3(unsigned char enc)
{
	unsigned char	num;

	num = enc << 4;
	num = num >> 6;
	//сравнение
	if (num == 1)
		return (1);
	else if (num == 2)
		return (2);
	else if (num == 3)
		return (4);
}

char	enc_byte(unsigned char enc, char argum)
{
	if (argum == 1)
		return (arg_1(enc));
	else if (argum == 2)
		return (arg_2(enc));
	else if (argum == 3)
		return (arg_3);
}

int		main(void)
{
	enc_byte(232);
}
