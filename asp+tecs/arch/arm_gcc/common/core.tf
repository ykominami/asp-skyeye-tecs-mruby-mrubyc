$ 
$     �ѥ�2�Υ�����¸�ƥ�ץ졼�ȡ�ARM�ѡ�
$ 

$ 
$ ͭ����CPU�㳰�ϥ�ɥ��ֹ�
$ 
$EXCNO_VALID = { 1,2,3,4,6 }$

$ 
$  DEF_EXC�ǻ��ѤǤ���CPU�㳰�ϥ�ɥ��ֹ�
$ 
$EXCNO_DEFEXC_VALID = EXCNO_VALID$

$ 
$  ɸ��ƥ�ץ졼�ȥե�����Υ��󥯥롼��
$ 
$INCLUDE "kernel/kernel.tf"$

$ 
$  �㳰�ϥ�ɥ�ơ��֥�
$ 
$FILE "kernel_cfg.c"$
$NL$
const FP _kernel_exch_tbl[TNUM_EXCH] = {$NL$
$FOREACH excno {0,1,...,6}$ 
	$IF LENGTH(EXC.EXCNO[excno])$
		$TAB$(FP)($EXC.EXCHDR[excno]$),
	$ELSE$
		$TAB$(FP)(_kernel_default_exc_handler),
	$END$
	$SPC$$FORMAT("/* %d */", +excno)$$NL$
$END$
$NL$};$NL$
$NL$

