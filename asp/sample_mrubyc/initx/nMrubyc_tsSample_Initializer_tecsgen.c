/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "nMrubyc_tsSample_Initializer_tecsgen.h"
#include "nMrubyc_tsSample_Initializer_factory.h"

/* 受け口ディスクリプタ型 #_EDT_# */
/* eInitialize */
struct tag_nMruby_tsSample_Initializer_eInitialize_DES {
    const struct tag_nMruby_sInitializeTECSBridge_VMT *vmt;
    tsSample_Initializer_IDX  idx;
};

/* 受け口スケルトン関数 #_EPSF_# */
/* eInitialize */
void           nMruby_tsSample_Initializer_eInitialize_initializeBridge_skel( const struct tag_nMruby_sInitializeTECSBridge_VDES *epd, mrb_vm* mrb, struct RClass * TECS)
{
    struct tag_nMruby_tsSample_Initializer_eInitialize_DES *lepd
        = (struct tag_nMruby_tsSample_Initializer_eInitialize_DES *)epd;
    nMruby_tsSample_Initializer_eInitialize_initializeBridge( lepd->idx, mrb, TECS );
}

/* 受け口スケルトン関数テーブル #_EPSFT_# */
/* eInitialize */
const struct tag_nMruby_sInitializeTECSBridge_VMT nMruby_tsSample_Initializer_eInitialize_MT_ = {
    nMruby_tsSample_Initializer_eInitialize_initializeBridge_skel,
};

/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */


/* 呼び口配列 #_CPA_# */


/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
nMruby_tsSample_Initializer_INIB nMruby_tsSample_Initializer_INIB_tab[] = {
    /* cell: nMruby_tsSample_Initializer_CB_tab[0]:  Mruby0_tsSample_Initializer id=1 */
    {
        /* entry port #_EP_# */ 
    },
    /* cell: nMruby_tsSample_Initializer_CB_tab[1]:  Mruby2_tsSample_Initializer id=2 */
    {
        /* entry port #_EP_# */ 
    },
};

/* 受け口ディスクリプタ #_EPD_# */
extern const struct tag_nMruby_tsSample_Initializer_eInitialize_DES Mruby0_tsSample_Initializer_eInitialize_des;
const struct tag_nMruby_tsSample_Initializer_eInitialize_DES Mruby0_tsSample_Initializer_eInitialize_des = {
    &nMruby_tsSample_Initializer_eInitialize_MT_,
    &nMruby_tsSample_Initializer_INIB_tab[0],   /* INIB */
};
extern const struct tag_nMruby_tsSample_Initializer_eInitialize_DES Mruby2_tsSample_Initializer_eInitialize_des;
const struct tag_nMruby_tsSample_Initializer_eInitialize_DES Mruby2_tsSample_Initializer_eInitialize_des = {
    &nMruby_tsSample_Initializer_eInitialize_MT_,
    &nMruby_tsSample_Initializer_INIB_tab[1],   /* INIB */
};
/* CB 初期化コード #_CIC_# */
void
nMruby_tsSample_Initializer_CB_initialize()
{
    nMruby_tsSample_Initializer_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
