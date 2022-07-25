#ifndef TENSOR_H_INCLUDED
#define TENSOR_H_INCLUDED
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

#define TENSOR_init1(type) VEC(type)
#define TENSOR_init2(type) VEC(type) VEC(vector_##type)
#define TENSOR_init3(type) VEC(type) VEC(vector_##type)\
 VEC(vector_vector_##type)
#define TENSOR_init4(type) VEC(type) VEC(vector_##type)\
  VEC(vector_vector_##type) VEC(vector_vector_vector_##type)
#define TENSOR_init5(type) VEC(type) VEC(vector_##type)\
  VEC(vector_vector_##type) VEC(vector_vector_vector_##type)\
  VEC(vector_vector_vector_##type)
#define TENSOR_init6(type) VEC(type) VEC(vector_##type)\
  VEC(vector_vector_##type) VEC(vector_vector_vector_##type)\
  VEC(vector_vector_vector_##type)\
  VEC(vector_vector_vector_vector##type)
#define TENSOR_init7(type) VEC(type) VEC(vector_##type)\
  VEC(vector_vector_##type) VEC(vector_vector_vector_##type)\
  VEC(vector_vector_vector_##type)\
  VEC(vector_vector_vector_vector##type)\
  VEC(vector_vector_vector_vector_vector##type)

#define tensor(type, dim) tensor##dim (type)
#define tensor1(type) vector_##type
#define tensor2(type) vector_vector_##type
#define tensor3(type) vector_vector_vector_##type
#define tensor4(type) vector_vector_vector_vector##type
#define tensor5(type) vector_vector_vector_vector_vector##type
#define tensor6(type) vector_vector_vector_vector_vector_vector##type
#define tensor7(type) vector_vector_vector_vector_vector_vector_vector##type

#define tensor_cons1(type, init) vector_of_cc(type, init)
#define tensor_cons2(type, init) vector_of_cc(vector_##type, init)
#define tensor_cons3(type, init) vector_of_cc(vector_vector_##type, init)
#define tensor_cons4(type, init) vector_of_cc(vector_vector_vector_##type, init)
#define tensor_cons5(type, init)\
  vector_of_cc(vector_vector_vector_vector##type, init)
#define tensor_cons6(type, init)\
  vector_of_cc(vector_vector_vector_vector_vector##type, init)
#define tensor_cons7(type, init)\
  vector_of_cc(vector_vector_vector_vector_vector_vector##type, init)

#define tc_cs1(type, ...)\
  (vector_of_cc(type, ((type[]){__VA_ARGS__})))
#define tc_cs2(type, ...)\
  tc_cs1(vector_##type, __VA_ARGS__)
#define tc_cs3(type, ...)\
  tc_cs1(vector_vector_##type, __VA_ARGS__)
#define tc_cs4(type, ...)\
  tc_cs1(vector_vector_vector_##type, __VA_ARGS__)
#define tc_cs5(type, ...)\
  tc_cs1(vector_vector_vector_vector_##type, __VA_ARGS__)
#define tc_cs6(type, ...)\
  tc_cs1(vector_vector_vector_vector_vector_##type, __VA_ARGS__)
#define tc_cs7(type, ...)\
  tc_cs1(vector_vector_vector_vector_vector_vector_##type, __VA_ARGS__)
  //(vector_of_cc((vector_of_##type), ((vector_of##type []){__VA_ARGS__})))

#endif