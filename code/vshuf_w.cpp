#include "common.h"

v128 vshuf_w(v128 a, v128 b, v128 c) {
  v128 dst;
  for (int i = 0; i < 4; i++) {
    if ((a.word[i] % 256) >= 64) {
      // Caveat: observed in 3C5000, but not in QEMU
      dst.word[i] = 0;
    } else if ((a.word[i] % 8) < 4) {
      dst.word[i] = c.word[a.word[i] % 4];
    } else {
      dst.word[i] = b.word[a.word[i] % 4];
    }
  }
  return dst;
}

void test() {
  __m128i b = {0x123456789ABCDEF0, 0x0FEDCBA987654321};
  __m128i c = {0x1122334455667788, 0x1212343456567878};
  __m128i a = {0x0001020304050607, 0x0001020304050607};
  PRINT(a);
  PRINT(b);
  PRINT(c);
  PRINT(__lsx_vshuf_w(a, b, c));

  a = __m128i{0x08090A0B0C0D0E0F, 0x08090A0B0C0D0E0F};
  PRINT(a);
  PRINT(__lsx_vshuf_w(a, b, c));

  a = __m128i{0x1011121314151617, 0x1011121314151617};
  PRINT(a);
  PRINT(__lsx_vshuf_w(a, b, c));

  a = __m128i{0x18191A1B1C1D1E1F, 0x18191A1B1C1D1E1F};
  PRINT(a);
  PRINT(__lsx_vshuf_w(a, b, c));

  a = __m128i{0x2021FFFFFFFFFFFF, 0x2223FFFFFFFFFFFF};
  PRINT(a);
  PRINT(__lsx_vshuf_w(a, b, c));

  a = __m128i{0x0706050403020100, 0x1F1E1D1C1B1A1918};
  PRINT(a);
  PRINT(__lsx_vshuf_w(a, b, c));

  b = __m128i{0x0000000500000004, 0x0000000700000006};
  c = __m128i{0x0000000100000000, 0x0000000300000002};

  for (int i = 0; i < 64; i++) {
    a = __m128i{i, 0};
    PRINT(a);
    PRINT(__lsx_vshuf_w(a, b, c));
  }

  for (int i = 0; i < 64; i++) {
    v128 a, b, c;
    assert(vshuf_w(a, b, c) == __lsx_vshuf_w(a, b, c));
  }
}
