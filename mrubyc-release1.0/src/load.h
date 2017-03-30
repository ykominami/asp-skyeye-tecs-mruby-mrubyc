/*! @file
  @brief
  mruby bytecode loader.

  <pre>
  Copyright (C) 2015 Kyushu Institute of Technology.
  Copyright (C) 2015 Shimane IT Open-Innovation Center.

  This file is distributed under BSD 3-Clause License.

  </pre>
*/

#ifndef MRBC_SRC_LOAD_H_
#define MRBC_SRC_LOAD_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


int loca_mrb_array(struct VM *vm, const uint8_t *ptr);
int load_mrb(struct VM *vm);


#ifdef __cplusplus
}
#endif
#endif
