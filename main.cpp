#include "LibLex.h"
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <iostream>

int main(int argc , char** argv) {
  FILE* f = fopen(argv[1], "r");
  fseek(f, 0, SEEK_END);
  int len = ftell(f);
  fseek(f, 0, SEEK_SET);
  
  char* m = (char*)malloc(len + 1);
  fread(m, 1, len , f);
  m[len] = EOF;
  
  Lex l(m, len);
  do {
    l.next();
    std::cout << l.name();
  }while (l.token() != EOF);
}
