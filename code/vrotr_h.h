for (int i = 0; i < 8; i++) {
  dst.half[i] = (a.half[i] >> (b.half[i] & 0xf)) |
                (a.half[i] << (16 - (b.half[i] & 0xf)));
}
