/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "nMrubyc_tTECSInitializer_tecsgen.h"
#include "nMrubyc_tTECSInitializer_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eInitialize : omitted by entry port optimize */

/* 受け口スケルトン関数 #_EPSF_# */
/* eInitialize : omitted by entry port optimize */

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eInitialize : omitted by entry port optimize */

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */
extern struct tag_nMruby_sInitializeTECSBridge_VDES Mruby0_tsKernel_Initializer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES Mruby0_tsSample_Initializer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES CtIntPointer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES CtULongPointer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES CtCharPointer_eInitialize_des;

extern struct tag_nMruby_sInitializeTECSBridge_VDES Mruby2_tsKernel_Initializer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES Mruby2_tsSample_Initializer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES CtIntPointer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES CtULongPointer_eInitialize_des;
extern struct tag_nMruby_sInitializeTECSBridge_VDES CtCharPointer_eInitialize_des;

/* 呼び口配列 #_CPA_# */
struct tag_nMruby_sInitializeTECSBridge_VDES * const Mruby0_TECSInitializer_cInitialize[] = {
    &Mruby0_tsKernel_Initializer_eInitialize_des,
    &Mruby0_tsSample_Initializer_eInitialize_des,
    &CtIntPointer_eInitialize_des,
    &CtULongPointer_eInitialize_des,
    &CtCharPointer_eInitialize_des,
};

struct tag_nMruby_sInitializeTECSBridge_VDES * const Mruby2_TECSInitializer_cInitialize[] = {
    &Mruby2_tsKernel_Initializer_eInitialize_des,
    &Mruby2_tsSample_Initializer_eInitialize_des,
    &CtIntPointer_eInitialize_des,
    &CtULongPointer_eInitialize_des,
    &CtCharPointer_eInitialize_des,
};

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
nMruby_tTECSInitializer_INIB nMruby_tTECSInitializer_INIB_tab[] = {
    /* cell: nMruby_tTECSInitializer_CB_tab[0]:  Mruby0_TECSInitializer id=1 */
    {
        /* call port (INIB) #_CP_# */ 
        Mruby0_TECSInitializer_cInitialize,      /* #_CCP3B_# */
        5,                                       /* length of cInitialize (n_cInitialize) #_CCP4_# */
        /* entry port #_EP_# */ 
    },
    /* cell: nMruby_tTECSInitializer_CB_tab[1]:  Mruby2_TECSInitializer id=2 */
    {
        /* call port (INIB) #_CP_# */ 
        Mruby2_TECSInitializer_cInitialize,      /* #_CCP3B_# */
        5,                                       /* length of cInitialize (n_cInitialize) #_CCP4_# */
        /* entry port #_EP_# */ 
    },
};

/* セル CB #_CB_# */
struct tag_nMruby_tTECSInitializer_CB nMruby_tTECSInitializer_CB_tab[2];
/* 受け口ディスクリプタ #_EPD_# */
/* eInitialize : omitted by entry port optimize */
/* eInitialize : omitted by entry port optimize */
/* CB 初期化コード #_CIC_# */
void
nMruby_tTECSInitializer_CB_initialize()
{
    nMruby_tTECSInitializer_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
