#include "common.h"

v128 vsrl_d(v128 a, v128 b) {
  v128 dst;
#include "vsrl_d.h"
  return dst;
}

void test() { FUZZ2(vsrl_d); }
