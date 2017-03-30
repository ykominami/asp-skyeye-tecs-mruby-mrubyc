#
# $Id: mrb_sample_kernel_obj.rb 1846 2012-07-22 02:35:54Z ritusm-takuya $
#

# mruby 版 タスクの起動
#  タスクセルを mruby から操作する

# ブリッジセルを bridge に割り付ける
p "creating bridge"
taskBridge = TECS::STask.new "TaskBridge"

# task の起動
#
taskBridge.activate

