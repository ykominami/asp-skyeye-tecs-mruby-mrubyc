$ 
$     �ѥ�2�Υ������åȰ�¸�ƥ�ץ졼�ȡ�AT91SKYEYE�ѡ�
$ 


$ 
$  ͭ���ʳ�����ֹ桤����ߥϥ�ɥ��ֹ桤CPU�㳰�ϥ�ɥ��ֹ�
$  0,19��31�ϻ��ѽ���ʤ������ơ��֥��������뤿���ɬ��
$INTNO_VALID = { 0,1,...,31 }$
$INHNO_VALID = INTNO_VALID$

$ 
$  ATT_ISR�ǻ��ѤǤ��������ֹ�Ȥ�����б��������ߥϥ�ɥ��ֹ�
$ 
$INTNO_ATTISR_VALID = { 1,2,...,18 }$
$INHNO_ATTISR_VALID = { 1,2,...,18 }$

$ 
$  DEF_INT�ǻ��ѤǤ������ߥϥ�ɥ��ֹ�
$ 
$INHNO_DEFINH_VALID = { 1,2,...,18 }$

$ 
$  CFG_INT�ǻ��ѤǤ��������ֹ�ȳ����ͥ����
$ 
$INTNO_CFGINT_VALID  = { 1,2,...,18 }$
$INTPRI_CFGINT_VALID = { -1,-2,...,-7 }$

$ 
$  �����°����Υ������åȰ�¸���Ѥ���ӥå�
$ 
$TARGET_INTATR = TA_HIGHLEVEL | TA_POSEDGE | TA_LOWLEVEL$

$ 
$  ������¸�ƥ�ץ졼�ȤΥ��󥯥롼�ɡ�ARM�ѡ�
$ 
$INCLUDE"arm_gcc/common/core.tf"$

$ 
$  �����ͥ���٥ơ��֥�
$ 
$FILE "kernel_cfg.c"$
$NL$
const PRI _kernel_inh_ipm_tbl[TNUM_INH] = {$NL$
$FOREACH inhno INHNO_VALID$ 
	$IF LENGTH(INH.INHNO[inhno])$
	  $TAB$$INT.INTPRI[inhno]$,
	$ELSE$
	  $TAB$0,
	$END$
	$SPC$$FORMAT("/* %d */", +inhno)$$NL$
$END$
$NL$};$NL$
$NL$

$ 
$  ����ߥޥ����ơ��֥�
$ 
const uint32_t _kernel_ipm_mask_tbl[8]={$NL$
$FOREACH intpri { 0,-1,...,-7 }$
 $intmask = 0$
 $FOREACH intno (INT.ID_LIST)$
  $IF INT.INTPRI[intno] >= intpri $
	$intmask = intmask | (1 << (INT.INTNO[intno]))$
  $END$
 $END$
 $TAB$UINT32_C($FORMAT("0x%08x", intmask)$),/* Priority $+intpri$ */$NL$
$END$
$NL$
};$NL$


$ 
$  ����ߥϥ�ɥ�ơ��֥�
$ 
$NL$
const FP _kernel_inh_tbl[TNUM_INH] = {$NL$
$FOREACH inhno INHNO_VALID$ 
	$IF LENGTH(INH.INHNO[inhno])$
		$TAB$(FP)($INH.INTHDR[inhno]$),
	$ELSE$
		$TAB$(FP)(_kernel_default_int_handler),
	$END$
	$SPC$$FORMAT("/* %d */", +inhno)$$NL$
$END$
$NL$};$NL$
$NL$
