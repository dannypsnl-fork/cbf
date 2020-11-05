#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void run(const char *const input) {
  // Initialize the tape with 30,000 zeroes.
  uint8_t tape[30000] = {0};
  // Set the pointer to point at the left most cell of the tape.
  uint8_t *ptr = tape;

  char cur;
  for (int i = 0; (cur = input[i]) != '\0'; ++i) {
    switch (cur) {
    case '>':
      ++ptr;
      break;
    case '<':
      --ptr;
      break;
    case '+':
      ++(*ptr);
      break;
    case '-':
      --(*ptr);
      break;
    case '.':
      putchar(*ptr);
      break;
    case ',':
      *ptr = getchar();
      break;
    case '[':
      if (!(*ptr)) {
        int loop = 1;
        while (loop > 0) {
          cur = input[++i];
          if (cur == ']')
            --loop;
          else if (cur == '[')
            ++loop;
        }
      }
      break;
    case ']':
      if (*ptr) {
        int loop = 1;
        while (loop > 0) {
          cur = input[--i];
          if (cur == '[')
            --loop;
          else if (cur == ']')
            ++loop;
        }
      }
      break;
    }
  }
}
