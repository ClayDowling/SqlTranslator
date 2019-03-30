#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>

typedef enum {
  UNSET,
  COMMA,
  LPAREN,
  RPAREN,
  IDENTIFIER,
  INSERT,
  INTO,
  VALUES,
  COMMENT,
  GO
} token_t;

class Token {
public:
  Token() : line(0), col(0), token(UNSET), literal("") {}
  int line;
  int col;
  token_t token;
  std::string literal;
};

#endif