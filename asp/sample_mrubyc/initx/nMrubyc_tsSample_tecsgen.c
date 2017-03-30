/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#include "nMrubyc_tsSample_tecsgen.h"
#include "nMrubyc_tsSample_factory.h"


/* 呼び口の参照する受け口ディスクリプタ(実際の型と相違した定義) #_CPEPD_# */


/* 呼び口配列 #_CPA_# */


/* 属性・変数の配列 #_AVAI_# */
/* セル INIB #_INIB_# */
/* cell: SimpleBridge0_CB:  SimpleBridge0 id=1 */
const nMruby_tsSample_INIB SimpleBridge0_INIB = {
};

/* cell: SimpleBridge2_CB:  SimpleBridge2 id=2 */
const nMruby_tsSample_INIB SimpleBridge2_INIB = {
};

/* 受け口ディスクリプタ #_EPD_# */
/* ID to INIB table #_INTAB_# */
nMruby_tsSample_INIB *nMruby_tsSample_INIB_tab[] ={
    &SimpleBridge0_INIB,
    &SimpleBridge2_INIB,
};
/* CB 初期化コード #_CIC_# */
void
nMruby_tsSample_CB_initialize()
{
    nMruby_tsSample_CB	*p_cb;
    int		i;
    FOREACH_CELL(i,p_cb)
        SET_CB_INIB_POINTER(i,p_cb)
        INITIALIZE_CB(p_cb)
    END_FOREACH_CELL
}
