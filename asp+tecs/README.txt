
	TOPPERS/ASP Kernel with TECS��Release 1.0.0��
		Toyohashi Open Platform for Embedded Real-Time Systems/
		Advanced Standard Profile Kernel
	  + Embedded Component System

���Υѥå������ϡ�TOPPERS/ASP�����ͥ�ʰʲ���ASP�����ͥ�ˤμ��ե⥸�塼
���TECS�λ��ͤ˴�Ť��ƥ���ݡ��ͥ�Ȳ�������ΤǤ���

�ڥե������Ÿ����ˡ��

���Υѥå������ϡ�ASP�����ͥ��Ʊ�ͤΥǥ��쥯�ȥ깽���ˤʤäƤ��ޤ�����
ASP�����ͥ뤫�齤����ä��Ƥ��ʤ��ǥ��쥯�ȥ�Τ����Ĥ���ޤ�Ƥ��ޤ���

����ץ�ץ������ۤ�����ˤϡ����Υѥå�������Ÿ�������ǥ��쥯
�ȥ�β��ˡ��ʲ��Υ��եȥ�������Ÿ���ʤޤ��ϡ�����ܥ�å���󥯡ˤ���
����������

	tecsgen		TECS�Υ��󥿥ե����������ͥ졼��

�ڹ�����ˡ��

����ץ�ץ������ۡ�ư�������ϡ�����Ū�ˤϡ�ASP�����ͥ��Ʊ
�ͤǤ���ASP�����ͥ�Υѥå������˴ޤޤ���TOPPERS/ASP�����ͥ� �桼����
���ޥ˥奢��פΡ֣��������å��������ȥ����ɡפ���򻲾Ȥ��Ƥ���������

�ޤ���Skyeye���ߥ�졼�����Ķ����Ѥ�����ˤϡ�AT91SKYEYE�������å�
��¸���Υޥ˥奢���target/at91skyeye_gcc/target_user.txt�ˤ��ɤ߲���
����

�ڥ���ݡ��ͥ�Ȳ������⥸�塼���

���������å����¸��

syssvc/tLogTask: �����ƥ��������
syssvc/tSerialPort: ���ꥢ�륤�󥿥ե������ɥ饤��
syssvc/tSysLog: �����ƥ����ǽ

���������åȰ�¸����SkyEye��¸����

target/at91skyeye_gcc/tPutLogSkyeye: �����ƥ�������٥����
target/at91skyeye_gcc/tSIOPortSkyeye: ���ꥢ��I/O�ǥХ�����SIO�˥ɥ饤��

������ץ�ץ����

sample/tSample: ����ץ�ץ����

�ڥ���ץ�μ¹���ˡ��skyeye�ǡˡ�
tecs_package/asp+tecs/

������ܥ�å����
tecsgen��TECS�Υ��󥿥ե����������ͥ졼���ˤ˥���ܥ�å���󥯤�ĥ��

tecs_package/asp+tecs/�˰�ư

��bin/tecsgen.exe�����Ѥ�����
: ln -s ../bin/tecsgen.exe tecsgen.exe 

����ʬ�ǹ��ۤ���tecsgen�����Ѥ�����
: ln -s ../tecsgen tecsgen

tecsgen�ι�����ˡ�ϡ�tecs_package/README.txt
�����tecs_package/tecsgen/README.txt�򻲾Ȥ��Ƥ���������

������ץ�ץ����Υǥ��쥯�ȥ��asp+tecs/sample1_skyeye�ˤ˰�ư
: cd sample1_skyeye
  
��TECS�Υ��󥿥ե����������ͥ졼���μ¹�

��bin/tecsgen.exe�����Ѥ�����
: make tecs

  ���ѡ��ߥå���󥨥顼�ˤʤ���
     �����Υ��ޥ�ɤ�¹Ԥ���
: chmod 500 ../../bin/tecsgen.exe

  ��CPP���顼�ˤʤ���
  gcc������ܥ�å���󥯤ξ��ϡ�Makefile��CPP����ܥ�å���������ꤹ��ɬ�פ����롥
  ����Ū�ˤ�Makefile�� TECSGEN_CPP���ѹ����롥

 #cygwin��gcc������ܥ�å���󥯤ξ��ϡ�
 #�����褦�˥���ܥ�å������(gcc-3,gcc-4�ʤ�)��ľ�ܻ��ꤹ��ɬ�פ����롥
 #TECSGEN_CPP = 'gcc-3 -E -D TECS'
 #TECSGEN_CPP = 'gcc-4 -E -D TECS'

����ʬ�ǹ��ۤ���tecsgen�����Ѥ�����
  Makefile��111���ܤ�TECSGEN�򥳥��ȥ����Ȥ���
  114�����դ��RUBYLIB��TECSGEN�Υ����Ȥ򳰤���

#tecsgen.rb (ruby + racc)�����Ѥ�����ϲ�����RUBYLIB��TECSGEN����������Ѥ���
#RUBYLIB = $(SRCDIR)/tecsgen/tecsgen
#TECSGEN =$(RUBY) $(SRCDIR)/tecsgen/tecsgen/tecsgen.rb -L $(RUBYLIB)

: make tecs

����¸�ط�������
: make depend
  ������ѥ��뤹��ˤϥ�������ѥ���Ķ���arm-elf*�ˤ�������ɬ�פ�����ޤ���
      http://www.embedded.jp/gnuwing/�ʤɤ�����Ǥ��ޤ���
  ���ѡ��ߥå���󥨥顼�ˤʤ���ϲ����Υ��ޥ�ɤ�¹Ԥ���
      chmod 500 ../cfg/cfg/cfg.exe 

������ѥ���
: make

���¹�
: skyeye.exe -e asp.exe
  ��tecs_package/bin/skyeye.exe�˥ѥ����̤�ɬ�פ����롥
  �ޤ���
: ../../bin/skyeye.exe -e asp.exe
  ���ѡ��ߥå���󥨥顼�ˤʤ���ϲ����Υ��ޥ�ɤ�¹Ԥ���
      chmod 500 ../../bin/skyeye.exe

�����꡼��
�����֥������ȥե�����κ��
: make clean

��TECS�Υ��󥿥ե����������ͥ졼�����������������ɡ���¸�ط��κ��
: make realclean

�ڼ��䡦�Х���ݡ��ȡ��ո������������

TECS�����ASP�����ͥ�����ɤ���Τˤ��뤿��Τ��ո����򴿷ޤ��ޤ���

TECS�˴ؤ�������Х���ݡ��ȡ����ո����ϡ�TOPPERS�桼�����᡼��󥰥ꥹ�� 
��user@toppers.jp�˰��ˤ��ꤤ���ޤ���TOPPERS����ϡ�TOPPERS����ݡ��ͥ�Ȼ���
WG�Υ᡼��󥰥ꥹ�ȡ�com-wg@toppers.jp�˰��ˤ���ƤǤ��ޤ���

�ʾ�
