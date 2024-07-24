/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_enum.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:45:45 by guhernan          #+#    #+#             */
/*   Updated: 2021/03/09 10:32:43 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_ENUM_H
# define GLOBAL_ENUM_H
# include "global_types.h"

typedef enum e_id_code
{
	PS_INF = 0,
	PS_MAP,
	PS_ULY,
	PS_GEN,
}					t_icode;

typedef enum e_error
{
	E_ERROR = -1,
	E_STOP,
	E_TRUE,
}					t_error;

typedef enum e_parsmap
{
	M_0 = 0,
	M_1,
	M_2,
	M_NO,
	M_WO,
	M_SO,
	M_EA,
	M_OUT = 7,
}					t_mpars;

typedef enum e_parsinfo
{
	D_RES = 0,
	D_NO,
	D_SO,
	D_WE,
	D_EA,
	D_SPR,
	C_F,
	C_C,
	E_OUT = 8,
}					t_pars;

typedef enum e_type_of_plan
{
	PL_NO = 0,
	PL_SO,
	PL_WE,
	PL_EA = 3,
	PL_SPR,
	PL_F,
	PL_C,
}					t_typlan;

typedef enum e_chpath
{
	PTH_MAP = 0,
	PTH_TEX,
}					t_path;

typedef enum e_typeobject
{
	TO_WALL = 0,
	TO_THGS,
	TO_OTHER,
}					t_tyobj;

typedef enum e_mlx_keymapping
{
	KEY_ECHAP = 53,
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_M = 46,
	KEY_PG_UP = 116,
	KEY_PG_DWN = 121,
	KEY_AR_UP = 126,
	KEY_AR_DWN = 125,
	KEY_AR_LFT = 123,
	KEY_AR_RGT = 124,
}				t_keymap;

typedef enum e_whichcolor
{
	WC_BLACK = 0x0,
	WC_RED = 0xFF0000,
	WC_GREEN = 0x00FF00,
	WC_BLUE = 0x0000FF,
	WC_WHITE = 0xFFFFFF,
}					t_whcolor;

typedef enum e_errgeneral
{
	EG_FD,
	EG_OPEN,
}					t_errgen;

typedef enum e_errinfo
{
	EI_WID = 8,
	EI_WORD = 9,
	EI_WDEF = 10,
	EI_WFD = 11,
	EI_WEOF = 12,
}					t_errinf;

typedef enum e_errmap
{
	EM_WPOS = 0,
	EM_WSTP,
	EM_WMAP,
	EM_WWAL,
	EM_WFD,
	EM_WEOF = 5,
}					t_errmap;

#endif
