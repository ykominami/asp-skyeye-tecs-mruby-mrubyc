#
# $Id: mrb_sample_kernel_obj.rb 1846 2012-07-22 02:35:54Z ritusm-takuya $
#

# mruby �� �^�X�N�̋N��
#  �^�X�N�Z���� mruby ���瑀�삷��

# �u���b�W�Z���� bridge �Ɋ���t����
p "creating bridge"
taskBridge = TECS::STask.new "TaskBridge"

# task �̋N��
#
taskBridge.activate

