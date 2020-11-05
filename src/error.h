#pragma once
#include <stdio.h>

static inline void err(const char *const msg) {
  fprintf(stderr, "%s\n", msg);
  exit(1);
}
