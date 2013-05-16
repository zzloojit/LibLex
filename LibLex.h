#ifndef LIBLEX_H
#define LIBLEX_H
#include "Token.h"
#include <string>

using std::string;
class Lex
{
 public: 
  Lex(char* buf, int length);
  // return current tok
  int token();
  // return current tok length
  int length();
  // comsume current tok
  void next();
  // return current token string
  string name();
 private:
  void scanIdent();
  void scanNumber(int radix);
  char* start;
  char* cur;
  char* end;
  char* ptr;
  int len;
  int tok;
  int radix;
};

#endif
