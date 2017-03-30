
#include "value.h"
#include "static.h"
#include "vm_config.h"

/*

  GLobal objects are stored in 'mrbc_global' array.
  'mrbc_global' array is decending order by sym_id.
  In case of searching a global object, binary search is used.
  In case of adding a global object, insertion sort is used.

*/

/* search */
static int search_global_object(mrb_sym sym_id)
{
  int left = 0, right = MAX_GLOBAL_OBJECT_SIZE-1;
  while( left <= right ){
    int mid = (left+right)/2;
    if( mrbc_global[mid].sym_id == sym_id ) return mid;
    if( mrbc_global[mid].sym_id < sym_id ){
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

static int search_const(mrb_sym sym_id) {
  int left = 0, right = MAX_CONST_COUNT-1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if ( mrbc_const[mid].sym_id == sym_id ) return mid;
    if ( mrbc_const[mid].sym_id < sym_id ) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

/* add */
void global_object_add(mrb_sym sym_id, mrb_object *obj)
{
  int index = search_global_object(sym_id);
  if( index == -1 ){
    index = MAX_GLOBAL_OBJECT_SIZE-1;
    while( index > 0 && mrbc_global[index].sym_id < sym_id ){
      mrbc_global[index] = mrbc_global[index-1];
      index--;
    }
  }
  mrbc_global[index].sym_id = sym_id;
  mrbc_global[index].obj = *obj;
}

void const_add(mrb_sym sym_id, mrb_object *obj)
{
  int index = search_const(sym_id);
  if( index == -1 ){
    index = MAX_CONST_COUNT-1;
    while(index > 0 && mrbc_const[index].sym_id < sym_id ){
      mrbc_const[index] = mrbc_const[index-1];
      index--;
    }
  }
  mrbc_const[index].sym_id = sym_id;
  mrbc_const[index].obj = *obj;
}

/* get */
mrb_object global_object_get(mrb_sym sym_id)
{
  int index = search_global_object(sym_id);
  if( index >= 0 ){
    return mrbc_global[index].obj;
  } else {
    /* nil */
    mrb_object obj;
    obj.tt = MRB_TT_FALSE;
    return obj;
  }
}

mrb_object const_get(mrb_sym sym_id) {
  int index = search_const(sym_id);
  if (index >= 0){
    return mrbc_const[index].obj;
  } else {
    mrb_object obj;
    obj.tt = MRB_TT_FALSE;
    return obj;
  }
}
