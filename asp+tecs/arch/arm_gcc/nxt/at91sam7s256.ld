/*
 *  @(#) $Id$
 */

/*
 * メモリサイズの指定
 */
MEMORY
{
	FLASH : ORIGIN = 0x00000000, LENGTH  = 0x40000 /* 256kbyte */
    SRAM  : ORIGIN = 0x00200000, LENGTH  = 0x10000 /*  64kbyte */
}

/*
 * 共通リンカスクリプトのインクルード
 */
INCLUDE at91sam7s.ld

