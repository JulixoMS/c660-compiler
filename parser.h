#ifndef __PARSER
#define __PARSER
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define true 1
#define false 0

typedef char bool;

typedef struct token {
  char *str;
  int length;
} token;

typedef struct tokenizer {
  char *currstr;
  int length;
  char *divs;
  int divcnt;
  token *tokens;
  int tokcnt;
} tokenizer;

tokenizer *createTokenizer(char *str) {
  tokenizer *t = (tokenizer *)malloc(sizeof(tokenizer));
  t->length = strlen(str);
  t->currstr = str;
  t->divs = (char *)malloc(9);
  t->divcnt = 0;
  t->tokens = NULL;
  t->tokcnt = 0;
  return t;
}

void addDivider(char div, tokenizer *t) {
  if (t->divcnt >= 8) {
    printf(".PARSER_ERR: Too many dividers added!\n");
  } else {
    t->divs[t->divcnt++] = div;
  }
}

void clrDividers(tokenizer *t) {
  free(t->divs);
  t->divs = (char *)malloc(9);
}

void addToken(token *tk, tokenizer *t) {
  t->tokens = (token *)realloc(t->tokens, (t->tokcnt+1) * sizeof(token));
  t->tokens[t->tokcnt] = *tk;
  t->tokcnt++;
}

void updateTokens(tokenizer *t) {
  if (t->tokens != NULL) {
    free(t->tokens);
    t->tokcnt = 0;
  }
  addDivider('\0', t);
  char *currtok = malloc(1);
  int currsize = 0;
  currtok[0] = '\0';
  for (int i = 0; i < t->length + 1; i++) {
    char c = t->currstr[i];
    bool b = false;
    for (int j = 0; j < t->divcnt; j++) {
      b = b || (c == t->divs[j]);
    }
    if (b) {
      if (currtok[0] != '\0') {
        token *tk = (token *)malloc(sizeof(token));
        char *currtokclone = malloc(currsize+1);
        for (int j = 0; j < currsize; j++) {
          currtokclone[j] = currtok[j];
        }
        currtokclone[currsize] = '\0';
        tk->str = currtokclone;
        tk->length = strlen(currtok);
        addToken(tk, t);
        free(currtok);
        currtok = malloc(1);
        currtok[0] = '\0';
        currsize = 0;
      }
    } else {
      currtok = (char *)realloc(currtok, currsize + 2);
      currtok[currsize] = c;
      currtok[currsize + 1] = '\0';
      currsize++;
    }
  }
}

#endif