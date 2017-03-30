asp+tecs/
bin/
doc/
mruby/

create mrbc
 :cd mruby
 :make

select compiler
mruby/Makefile
TARGET = arm-none-eabi or TARGET = arm-elf

create mruby/lib/libmruby.a
 :cd mruby
 :make "TARGET_CPU=arm" clean
 :make "TARGET_CPU=arm"

compile sample (Hello World)
 :cd asp+tecs/sample_mruby
 :make tecs
 :make depend
 :make

If you have permission errors, do chmod command as below.
i.e.:chmod +x ../../bin/tecsgen.exe
    :chmod +x ../../bin/mrbc.exe
    :chmod +x ../../bin/skyeye.exe
    :chmod +x ../cfg/cfg/cfg.exe

run sample (Hello World)
 :cd asp+tecs/sample_mruby
 :../../bin/skyeye -e asp.exe

compile sample (MrubyBridge for Kernel Object)
 :cd asp+tecs/sample_mruby_kernel_obj
 :make tecs
 :make depend
 :make

run sample  (MrubyBridge for Kernel Object)
 :cd asp+tecs/sample_mruby_kernel_obj
 :../../bin/skyeye -e asp.exe



