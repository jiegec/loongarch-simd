for (int i = 0; i < 8; i++) {
  dst.half[i] = ((s16)a.half[i]) >> (b.half[i] & 0xf);
}
