for (int i = 0; i < 4; i++) {
  if (i < 2) {
    s64 temp = (s64)a.dword[i] >> (b.dword[i] & 63);
    dst.word[i] = clamp<s64>(temp, -2147483648, 2147483647);
  } else {
    dst.word[i] = 0;
  }
}
