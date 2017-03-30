/*
 *  @(#) $Id$
 */

/*
 * メモリサイズの指定
 */
MEMORY
{
	FLASH : ORIGIN = 0x00000000, LENGTH  = 0x20000 /* 128kbyte */
    SRAM  : ORIGIN = 0x00200000, LENGTH  =  0x8000 /*  32kbyte */
}

/*
 * 共通リンカスクリプトのインクルード
 */
INCLUDE at91sam7s.ld
