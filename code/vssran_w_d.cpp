#include "common.h"

v128 vssran_w_d(v128 a, v128 b) {
  v128 dst;
#include "vssran_w_d.h"
  return dst;
}

void test() { FUZZ2(vssran_w_d); }
