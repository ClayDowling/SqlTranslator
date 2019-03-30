#include "tokenizer.h"

using namespace std;

Tokenizer::Tokenizer(string src) { buffer = src; }

Token Tokenizer::GetNextToken() {
  Token tok;

  if (buffer[0] == '(')
    tok.token = LPAREN;
  else
    tok.token = RPAREN;

  return tok;
}