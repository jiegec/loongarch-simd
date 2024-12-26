#include "common.h"

int xbz_d(v256 a) {
  int dst;
#include "xvsetanyeqz_d.h"
  return dst;
}

void test() {
  __m256i a = {0, 0};
  assert(__lasx_xbz_d(a));
  assert(__lasx_xbz_d(a) == xbz_d(a));

  a = __m256i{1, 0};
  assert(__lasx_xbz_d(a));
  assert(__lasx_xbz_d(a) == xbz_d(a));

  a = __m256i{0, 1};
  assert(__lasx_xbz_d(a));
  assert(__lasx_xbz_d(a) == xbz_d(a));

  a = __m256i{0x1111111111111111, 0x1111111111111111, 0x1111111111111111,
              0x1111111111111111};
  assert(!__lasx_xbz_d(a));
  assert(__lasx_xbz_d(a) == xbz_d(a));

  a = __m256i{0x0000000000000000, 0x1111111111111111, 0x1111111111111111,
              0x1111111111111111};
  assert(__lasx_xbz_d(a));
  assert(__lasx_xbz_d(a) == xbz_d(a));
}