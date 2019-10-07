#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "parser.h"
#include "mcode.h"
#include "cstring.h"

int main() {
  /*
  char *test = "lda 0\nada 1\nldx a\nldy 100\nljl 0\nljh 0\njeq j";
  tokenizer *tok = createTokenizer(test);
  addDivider(' ', tok);
  addDivider('\n', tok);
  updateTokens(tok);
  for (int i = 0; i < tok->tokcnt; i++) {
    printf("%s\n", tok->tokens[i].str);
  }
  */

  // TODO: Add replace function and replace #### with 2-digit hex code 
  int pc = 0;
  for (int i = 0; i < 64; i++) {
    if (ilen[i] == 1) {
      printf("%04x: %02x -- %s\n", pc, i, istr[i]);
    } else if (ilen[i] == 2) {
      char *barg = malloc(3);
      itoa(0xde, barg, 16);
      if (strlen(barg) < 2) {
        if (strlen(barg) < 1) {
          printf("%04x: %02x 00 %s\n", pc, i, istr[i]);
        } else {
          printf("%04x: %02x 0%s %s\n", pc, i, barg, istr[i]);
        }
      } else {
        printf("%04x: %02x %s %s\n", pc, i, barg, istr[i]);
      }
    }
    pc += ilen[i];
  }
  return 0;
}