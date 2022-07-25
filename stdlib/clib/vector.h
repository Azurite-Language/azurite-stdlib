#ifndef META_VEC_H_INCLUDED
#define META_VEC_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#define VEC(type) typedef struct {\
  size_t element_count;\
  size_t allocated;\
  type * data;\
} vector_##type;\
vector_##type vector_of_##type (size_t size){\
  vector_##type to_return;\
  to_return.element_count = 0;\
  to_return.allocated = size;\
  to_return.data = (type *)malloc(size * sizeof(type));\
  return to_return;\
}\
vector_##type __construct_of_##type (type v[], size_t size){\
  vector_##type to_return = vector_of_##type (size + 5);\
  to_return.element_count = size;\
  for(int i = 0; i < size; i++){\
    to_return.data[i] = v[i];\
  }\
  return to_return;\
}\
void push_back_for_##type ( vector_##type * v, type value){\
  if(v->allocated <= v->element_count){\
    v->allocated += 5;\
    v->data = (type *)realloc(v->data, (v->allocated + 5) * sizeof(type));\
  }\
  v->element_count++;\
  v->data[v->element_count-1] = value;\
}\
void pop_back_for_##type (vector_##type * v){\
  v->element_count--;\
}\
void iter_ref_for_##type (vector_##type * v, void(*fn)(type *)){\
  for(int i = 0; i < v->element_count; i++){\
    (*fn)(&(v->data[i]));\
  }\
}\
void iter_val_for_##type (vector_##type * v, void(*fn)(type)){\
  for(int i = 0; i < v->element_count; i++){\
    (*fn)(v->data[i]);\
  }\
}

#define delete_vec(to_free) free((to_free).data);
#define nth(v, i) (v).data[i]
#define nth2(v, row, col) (v).data[row].data[col]
#define nth3(v, row, col, z) (v).data[row].data[col].data[z]
#define vector_of_cc(type, ARRAY) (__construct_of_##type\
  (ARRAY, sizeof(ARRAY)/sizeof(ARRAY[0])))



#endif