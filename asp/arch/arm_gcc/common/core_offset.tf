$
$       ���ե��åȥե����������ѥƥ�ץ졼�ȥե������ARM�ѡ�
$

$
$  ɸ��ƥ�ץ졼�ȥե�����Υ��󥯥롼��
$
$INCLUDE "kernel/genoffset.tf"$

$
$  �ե�����ɤΥ��ե��åȤ����������
$
$DEFINE("TCB_p_tinib", offsetof_TCB_p_tinib)$
$DEFINE("TCB_texptn", offsetof_TCB_texptn)$
$DEFINE("TCB_sp", offsetof_TCB_sp)$
$DEFINE("TCB_pc", offsetof_TCB_pc)$
$DEFINE("TINIB_exinf", offsetof_TINIB_exinf)$
$DEFINE("TINIB_task", offsetof_TINIB_task)$

$
$  �ӥåȥե�����ɤΥ��ե��åȤȥӥåȰ��֤����������
$
$DEFINE_BIT("TCB_enatex", sizeof_TCB, "B")$
