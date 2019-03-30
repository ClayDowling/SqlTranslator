#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

typedef enum {
  COMMA,
  LPAREN,
  RPAREN,
  IDENTIFIER,
  QUOTED_CONSTANT,
  UNQUOTED_CONSTANT,
  INSERT,
  INTO,
  VALUES,
  COMMENT,
  GO
} token_t;

class Token {
  int line;
  int col;
  token_t token;
  std::string literal;
};

#endif