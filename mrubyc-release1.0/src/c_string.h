/*! @file
  @brief


  <pre>
  Copyright (C) 2015 Kyushu Institute of Technology.
  Copyright (C) 2015 Shimane IT Open-Innovation Center.

  This file is distributed under BSD 3-Clause License.


  </pre>
*/

#ifndef MRBC_SRC_C_STRING_H_
#define MRBC_SRC_C_STRING_H_

#include <stdint.h>
#include "vm.h"

#ifdef __cplusplus
extern "C" {
#endif


void mrbc_init_class_string(mrb_vm *vm);

char *mrbc_string_dup(mrb_vm *vm, const char *str);
char *mrbc_string_cat(mrb_vm *vm, char *s1, const char *s2);

#ifdef __cplusplus
}
#endif
#endif
