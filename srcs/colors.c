/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:48:52 by hasmith           #+#    #+#             */
/*   Updated: 2018/11/15 00:38:40 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Color hooks (extentions of key_hooks)
*/

void		color_hooks(int keycode, t_fract *m)
{
	if (keycode == C_KEY)
		color_shift(m);
	else if (keycode == ONE)
		m->c.color = 1;
	else if (keycode == TWO)
		m->c.color = 2;
	else if (keycode == THREE)
		m->c.color = 3;
	else if (keycode == FOUR)
		m->c.color = 4;
	else if (keycode == FIVE)
		m->c.color = 5;
	else if (keycode == SIX)
		m->c.color = 6;
}

void		color_shift(t_fract *m)
{
	m->c.color_shift += 1;
	if (m->c.color_shift > 16)
		m->c.color_shift = 0;
}

void		psychedelic2(t_fract *m, int x, int y, int i)
{
	static int		blossom[] = {
		0xB90CF8, 0xB90CF8, 0xB90CF8, 0xD317F8, 0xEB21F8,
		0xF82CF0, 0xF936DE, 0xF941CD, 0xF94BBE, 0xF956B1,
		0xFA60A6, 0xFA6B9E, 0xFA7597, 0xFA8093, 0xFB8A91, 0xFCBFAB
	};
	static int		the_sun[] = {
		0xE0E907, 0xE8E007, 0xE7D007, 0xE6C107, 0xE5B107,
		0xE4A107, 0xE39207, 0xE28307, 0xE17407, 0xE06507,
		0xDF5607, 0xDE4707, 0xDC3807, 0xDB2A07, 0xDB1C07, 0xDA0D06
	};

	if (m->c.color == 4)
		pixel_put(m, x, y, blossom[(i + m->c.color_shift) % 16]);
	else if (m->c.color == 5)
		pixel_put(m, x, y, the_sun[(i + m->c.color_shift) % 16]);
	else if (m->c.color == 6)
	{
		m->c.color_change += 1;
		pixel_put(m, x, y, m->c.color_change);
	}
}

void		psychedelic(t_fract *m, int x, int y, int i)
{
	static int		full_spectrum[] = {
		0xE50016, 0xE23D00, 0xDF9000, 0xD9DD00, 0x85DA00,
		0x33D800, 0x005D1C, 0x00D36A, 0x00D0B6, 0x009ACE,
		0x004DCB, 0x0001C9, 0x4800C6, 0x9000C4, 0xC100AC, 0xBF0062
	};
	static int		blue_brown[] = {
		0x421E0F, 0x351821, 0x2D152D, 0x1F0F42, 0x1E1D4C,
		0x1C486C, 0x1A728B, 0x189DAB, 0x17BAC0, 0xDCF637,
		0xD8D826, 0xD3B513, 0xCFAA38, 0xAF912E, 0x8F7924
	};
	static int		gray_scale[] = {
		0x1E1E1E, 0x2C2C2C, 0x3A3A3A, 0x484848, 0x565656,
		0x646464, 0x727272, 0x808080, 0x8E8E8E, 0x9C9C9C,
		0xAAAAAA, 0xB8B8B8, 0xC6C6C6, 0xD4D4D4, 0xE2E2E2, 0xF0F0F0
	};

	if (m->c.color == 1)
		pixel_put(m, x, y, full_spectrum[(i + m->c.color_shift) % 16]);
	else if (m->c.color == 2)
		pixel_put(m, x, y, blue_brown[(i + m->c.color_shift) % 16]);
	else if (m->c.color == 3)
		pixel_put(m, x, y, gray_scale[(i + m->c.color_shift) % 16]);
	else
		psychedelic2(m, x, y, i);
}
