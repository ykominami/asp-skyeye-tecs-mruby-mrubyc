/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef nMrubyc_tsKernel_TECSGEN_H
#define nMrubyc_tsKernel_TECSGEN_H

/*
 * celltype          :  tsKernel
 * global name       :  nMrubyc_tsKernel
 * idx_is_id(actual) :  yes(yes)
 * singleton         :  no
 * has_CB            :  false
 * has_INIB          :  0
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sKernel_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_nMruby_tsKernel_INIB {
    /* call port #_TCP_# */
}  nMruby_tsKernel_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define nMruby_tsKernel_CB_tab           nMruby_tsKernel_INIB_tab
#define nMruby_tsKernel_SINGLE_CELL_CB   nMruby_tsKernel_SINGLE_CELL_INIB
#define nMruby_tsKernel_CB               nMruby_tsKernel_INIB
#define tag_nMruby_tsKernel_CB           tag_nMruby_tsKernel_INIB

extern nMruby_tsKernel_CB  *nMruby_tsKernel_CB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef ID nMruby_tsKernel_IDX;
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  nMruby_tsKernel_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tKernel_tecsgen.h"
#ifdef  nMruby_tsKernel_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* nMruby_tsKernel_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define nMruby_tsKernel_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define nMruby_tsKernel_N_CELL        (2)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define nMruby_tsKernel_VALID_IDX(IDX) (nMruby_tsKernel_ID_BASE <= (IDX) && (IDX) < nMruby_tsKernel_ID_BASE+nMruby_tsKernel_N_CELL)


/* セルCBを得るマクロ #_GCB_# */
#define nMruby_tsKernel_GET_CELLCB(idx) (nMruby_tsKernel_CB_tab[(idx) - nMruby_tsKernel_ID_BASE])
 /* 呼び口関数マクロ #_CPM_# */
#define nMruby_tsKernel_cTECS_sleep( p_that ) \
	  tKernel_eKernel_sleep( \
	    )
#define nMruby_tsKernel_cTECS_sleepTimeout( p_that, timeout ) \
	  tKernel_eKernel_sleepTimeout( \
	    (timeout) )
#define nMruby_tsKernel_cTECS_delay( p_that, delayTime ) \
	  tKernel_eKernel_delay( \
	    (delayTime) )
#define nMruby_tsKernel_cTECS_exitTask( p_that ) \
	  tKernel_eKernel_exitTask( \
	    )
#define nMruby_tsKernel_cTECS_getTaskId( p_that, p_taskId ) \
	  tKernel_eKernel_getTaskId( \
	    (p_taskId) )
#define nMruby_tsKernel_cTECS_rotateReadyQueue( p_that, taskPriority ) \
	  tKernel_eKernel_rotateReadyQueue( \
	    (taskPriority) )
#define nMruby_tsKernel_cTECS_getTime( p_that, p_systemTime ) \
	  tKernel_eKernel_getTime( \
	    (p_systemTime) )
#define nMruby_tsKernel_cTECS_getMicroTime( p_that, p_systemMicroTime ) \
	  tKernel_eKernel_getMicroTime( \
	    (p_systemMicroTime) )
#define nMruby_tsKernel_cTECS_lockCpu( p_that ) \
	  tKernel_eKernel_lockCpu( \
	    )
#define nMruby_tsKernel_cTECS_unlockCpu( p_that ) \
	  tKernel_eKernel_unlockCpu( \
	    )
#define nMruby_tsKernel_cTECS_disableDispatch( p_that ) \
	  tKernel_eKernel_disableDispatch( \
	    )
#define nMruby_tsKernel_cTECS_enableDispatch( p_that ) \
	  tKernel_eKernel_enableDispatch( \
	    )
#define nMruby_tsKernel_cTECS_disableTaskException( p_that ) \
	  tKernel_eKernel_disableTaskException( \
	    )
#define nMruby_tsKernel_cTECS_enableTaskException( p_that ) \
	  tKernel_eKernel_enableTaskException( \
	    )
#define nMruby_tsKernel_cTECS_changeInterruptPriorityMask( p_that, interruptPriority ) \
	  tKernel_eKernel_changeInterruptPriorityMask( \
	    (interruptPriority) )
#define nMruby_tsKernel_cTECS_getInterruptPriorityMask( p_that, p_interruptPriority ) \
	  tKernel_eKernel_getInterruptPriorityMask( \
	    (p_interruptPriority) )
#define nMruby_tsKernel_cTECS_exitKernel( p_that ) \
	  tKernel_eKernel_exitKernel( \
	    )
#define nMruby_tsKernel_cTECS_senseContext( p_that ) \
	  tKernel_eKernel_senseContext( \
	    )
#define nMruby_tsKernel_cTECS_senseLock( p_that ) \
	  tKernel_eKernel_senseLock( \
	    )
#define nMruby_tsKernel_cTECS_senseDispatch( p_that ) \
	  tKernel_eKernel_senseDispatch( \
	    )
#define nMruby_tsKernel_cTECS_senseDispatchPendingState( p_that ) \
	  tKernel_eKernel_senseDispatchPendingState( \
	    )
#define nMruby_tsKernel_cTECS_senseKernel( p_that ) \
	  tKernel_eKernel_senseKernel( \
	    )

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  nMruby_tsKernel_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  nMruby_tsKernel_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	nMruby_tsKernel_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	nMruby_tsKernel_IDX

#define tsKernel_IDX  nMruby_tsKernel_IDX
/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cTECS_sleep( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_sleep( p_cellcb ))
#define cTECS_sleepTimeout( timeout ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_sleepTimeout( p_cellcb, timeout ))
#define cTECS_delay( delayTime ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_delay( p_cellcb, delayTime ))
#define cTECS_exitTask( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_exitTask( p_cellcb ))
#define cTECS_getTaskId( p_taskId ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_getTaskId( p_cellcb, p_taskId ))
#define cTECS_rotateReadyQueue( taskPriority ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_rotateReadyQueue( p_cellcb, taskPriority ))
#define cTECS_getTime( p_systemTime ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_getTime( p_cellcb, p_systemTime ))
#define cTECS_getMicroTime( p_systemMicroTime ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_getMicroTime( p_cellcb, p_systemMicroTime ))
#define cTECS_lockCpu( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_lockCpu( p_cellcb ))
#define cTECS_unlockCpu( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_unlockCpu( p_cellcb ))
#define cTECS_disableDispatch( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_disableDispatch( p_cellcb ))
#define cTECS_enableDispatch( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_enableDispatch( p_cellcb ))
#define cTECS_disableTaskException( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_disableTaskException( p_cellcb ))
#define cTECS_enableTaskException( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_enableTaskException( p_cellcb ))
#define cTECS_changeInterruptPriorityMask( interruptPriority ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_changeInterruptPriorityMask( p_cellcb, interruptPriority ))
#define cTECS_getInterruptPriorityMask( p_interruptPriority ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_getInterruptPriorityMask( p_cellcb, p_interruptPriority ))
#define cTECS_exitKernel( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_exitKernel( p_cellcb ))
#define cTECS_senseContext( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_senseContext( p_cellcb ))
#define cTECS_senseLock( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_senseLock( p_cellcb ))
#define cTECS_senseDispatch( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_senseDispatch( p_cellcb ))
#define cTECS_senseDispatchPendingState( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_senseDispatchPendingState( p_cellcb ))
#define cTECS_senseKernel( ) \
          ((void)p_cellcb, nMruby_tsKernel_cTECS_senseKernel( p_cellcb ))



/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < nMruby_tsKernel_N_CELL; (i)++ ){ \
       (p_cb) = nMruby_tsKernel_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* nMrubyc_tsKernel_TECSGENH */
