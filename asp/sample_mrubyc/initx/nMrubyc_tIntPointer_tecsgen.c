/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "nMrubyc_tIntPointer_tecsgen.h"
#include "nMrubyc_tIntPointer_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eInitialize */
struct tag_nMruby_tIntPointer_eInitialize_DES {
    const struct tag_nMruby_sInitializeTECSBridge_VMT *vmt;
    tIntPointer_IDX  idx;
};

/* 受け口スケルトン関数 #_EPSF_# */
/* eInitialize */
void           nMruby_tIntPointer_eInitialize_initializeBridge_skel( const struct tag_nMruby_sInitializeTECSBridge_VDES *epd, mrb_vm* mrb, struct RClass * TECS)
{
    nMruby_tIntPointer_eInitialize_initializeBridge( mrb, TECS );
}

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eInitialize */
const struct tag_nMruby_sInitializeTECSBridge_VMT nMruby_tIntPointer_eInitialize_MT_ = {
    nMruby_tIntPointer_eInitialize_initializeBridge_skel,
};

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */

/* 呼び口配列 #_CPA_# */

/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
nMruby_tIntPointer_INIB nMruby_tIntPointer_SINGLE_CELL_INIB = 
{
    /* entry port #_EP_# */ 
};

/* 受け口ディスクリプタ #_EPD_# */
extern const struct tag_nMruby_tIntPointer_eInitialize_DES CtIntPointer_eInitialize_des;
const struct tag_nMruby_tIntPointer_eInitialize_DES CtIntPointer_eInitialize_des = {
    &nMruby_tIntPointer_eInitialize_MT_,
    &nMruby_tIntPointer_SINGLE_CELL_INIB,     /* INIB */
};
/* CB 初期化コード #_CIC_# */
void
nMruby_tIntPointer_CB_initialize()
{
    SET_CB_INIB_POINTER(i,p_cb)
    INITIALIZE_CB()
}
