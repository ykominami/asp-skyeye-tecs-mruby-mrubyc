/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2006-2009 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: chip_kernel.h 1635 2009-09-16 01:17:30Z ertl-honda $
 */

/*
 *  kernel.hのチップ依存部（AT91SAM7S用）
 *
 *  このインクルードファイルは，kernel.hでインクルードされる．他のファ
 *  イルから直接インクルードすることはない．このファイルをインクルード
 *  する前に，t_stddef.hがインクルードされるので，それらに依存してもよ
 *  い．
 */

#ifndef TOPPERS_CHIP_KERNEL_H
#define TOPPERS_CHIP_KERNEL_H

/*
 *  コア依存で共通な定義（ARM用）
 */
#include "arm_gcc/common/core_kernel.h"

/*
 *  サポートする機能の定義
 */
#define TOPPERS_SUPPORT_ENA_INT			/* ena_intをサポートする */
#define TOPPERS_SUPPORT_DIS_INT			/* dis_intをサポートする */
#define TOPPERS_SUPPORT_GET_UTM			/* get_utmをサポートする */

/*
 *  割込み優先度の範囲
 */
#define TMIN_INTPRI        (-7)        /* 割込み優先度の最小値（最高値）*/
#define TMAX_INTPRI        (-1)        /* 割込み優先度の最大値（最低値）*/

/*
 *  タイムティックの定義
 */
#define TIC_NUME     1U            /* タイムティックの周期の分子 */
#define TIC_DENO     1U            /* タイムティックの周期の分母 */

/*
 *  割り込み属性
 */
#define	TA_POSEDGE		0x04U		/* ポジティブエッジトリガ */
#define	TA_LOWLEVEL		0x00U		/* ローレベルトリガ */
#define	TA_HIGHLEVEL	0x08U		/* ハイレベルトリガ */

#endif /* TOPPERS_CHIP_KERNEL_H */
