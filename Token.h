#ifndef TOKEN_H
#define TOKEN_H
enum Token{
  EOF = -1, // end of file
  ERROR, 
  SPACE,    // ' ' '\t'
  LINE,     // \n \r \r\n
  IDENTIFIER, 

  LPAREN,    // (
  RPAREN,    // )
  LBRACE,    // {
  RBRACE,    // }
  LBRACKET,  // [
  RBRACKET,  // ]
  SEMI,      // ;
  COMMA,     // ,
  DOT,       // .
  ELLIPSIS,  // ...
  EQ,        // =
  GT,        // >
  LT,        // <
  BANG,      // !
  TILDE,     // ~
  QUES,      // ?
  COLON,     // :
  EQEQ,      // ==
  LTEQ,      // <=
  GTEQ,      // >=
  BANGEQ,    // !=
  POUND,     // #
  AMPAMP,    // &&
  BARBAR,    // ||
  PLUSPLUS,  // ++
  SUBSUB,    // --
  PLUS,      // +
  SUB,       // -
  STAR,      // *
  SLASH,     // /
  AMP,       // &
  BAR,       // |
  CARET,     // ^
  PERCENT,   // %
  LTLT,      // <<
  GTGT,      // >>
  PLUSEQ,    // +=
  SUBEQ,     // -=
  STAREQ,    // *=
  SLASHEQ,   // /=
  AMPEQ,     // &=
  BAREQ,     // |=
  CARETEQ,   // ^=
  PERCENTEQ, // %=
  LTLTEQ,    // <<=
  GTGTEQ,    // >>=
  
  /* INT,       // int */
  /* DOUBLE,    // double */
  /* VOID,      // void */
  /* CHAR,      // char */
  /* UNSIGNED,  // unsigned */
  /* TYPEDEF,   // typedef */
  /* FOR,       // for */
  /* WHILE,     // while */
  /* IF,        // if */
  /* ELSE,      // else */
};
#endif
