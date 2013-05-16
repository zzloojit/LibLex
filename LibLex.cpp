#include "LibLex.h"

Lex::Lex(char* buf, int length) {
  start = buf;
  cur = buf;
  end = buf + length;
  len = 0;
}

void  Lex::next() {
  cur += len;
  ptr = cur;
  char ch;
  ch = *ptr++;
  switch(ch) {
  case ' ':
  case '\t':
    ch = *ptr;
    while (ch == ' ' || ch == '\t') {
      ch = *ptr++;
    }
    len = ptr - cur;
    tok = SPACE;
    break;

  case '\n':
    ptr++;
    len = ptr - cur;
    tok = LINE;
    break;

  case '\r':
    ptr++;
    if (*ptr == '\n')
      ptr++;
    len = ptr - cur;
    tok = LINE;
    break;
    
  case 'A': case 'B': case 'C': case 'D': case 'E':
  case 'F': case 'G': case 'H': case 'I': case 'J':
  case 'K': case 'L': case 'M': case 'N': case 'O':
  case 'P': case 'Q': case 'R': case 'S': case 'T':
  case 'U': case 'V': case 'W': case 'X': case 'Y':
  case 'Z':
  case 'a': case 'b': case 'c': case 'd': case 'e':
  case 'f': case 'g': case 'h': case 'i': case 'j':
  case 'k': case 'l': case 'm': case 'n': case 'o':
  case 'p': case 'q': case 'r': case 's': case 't':
  case 'u': case 'v': case 'w': case 'x': case 'y':
  case 'z':
  case '$': case '_':
    scanIdent();
    break;

  case '0':
    ch = *ptr;
    if (ch == 'x' || ch == 'X') {
      ch = *++ptr;
      //if (ch == '.') {
      //}
    }else {
      scanNumber(8);
    }
    break;
  case '1': case '2': case '3': case '4':
  case '5': case '6': case '7': case '8': case '9':
    scanNumber(10);
    break;
    
  case ',':
    len = ptr - cur; tok = COMMA; break;
  case ';':
    len = ptr - cur; tok = SEMI; break;
  case '(':
    len = ptr - cur; tok = LPAREN; break;
  case ')':
    len = ptr - cur; tok = RPAREN; break;
  case '[':
    len = ptr - cur; tok = LBRACKET; break;
  case ']':
    len = ptr - cur; tok = RBRACKET; break;
  case '{':
    len = ptr - cur; tok = LBRACE; break;
  case '}':
    len = ptr - cur; tok = RBRACE; break;
  case '/':
    ch = *ptr;
    if (ch == '/') {
      do{
        ch = *++ptr;
      }while (ch != '\r' && ch != '\n' && ch != EOF);
      cur = ptr;
      len = 0;
      next();
      break;
    }else if (ch == '*') {
      ch = *++ptr;
      while (ch != EOF) {
        if (ch == '*' && ptr[1] == '/')
          break;
        ch = *++ptr;
      }
      cur = ptr + 2;
      len = 0;
      next();
    }else if (ch == '=') {
      ptr++;
      len = ptr - cur;
      tok = SLASHEQ;
    }else {
      len = ptr - cur;
      tok = SLASH;
    }
    break;
  case '\377':
    tok = EOF;
    len = 1;
    break;
  }
}

int Lex::token() {
  return tok;
}

int Lex::length() {
  return len;
}

string Lex::name() {
  return string(cur, len);
}

void Lex::scanIdent() {
  tok = IDENTIFIER;
  do {
    char ch = *ptr;
    switch(ch) {
    case 'A': case 'B': case 'C': case 'D': case 'E':
    case 'F': case 'G': case 'H': case 'I': case 'J':
    case 'K': case 'L': case 'M': case 'N': case 'O':
    case 'P': case 'Q': case 'R': case 'S': case 'T':
    case 'U': case 'V': case 'W': case 'X': case 'Y':
    case 'Z':
    case 'a': case 'b': case 'c': case 'd': case 'e':
    case 'f': case 'g': case 'h': case 'i': case 'j':
    case 'k': case 'l': case 'm': case 'n': case 'o':
    case 'p': case 'q': case 'r': case 's': case 't':
    case 'u': case 'v': case 'w': case 'x': case 'y':
    case 'z':
    case '$': case '_':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      break;

    default:
      len = ptr - cur;
      return;
    }
    ptr++;
  }while (true);
}

void Lex::scanNumber(int radix) {
  int digitRadix = (radix <= 10) ? 10 : 16;
  bool seendigit = false;
  
  // while (digit(digitRadix) >= 0) {
  //   seendigit = true;
  //   ++ptr;
  // }
}
