#include "tokenizer.h"
#include <cstring>

using namespace std;

Tokenizer::Tokenizer(string src) {
  buffer = src;
  point = 0;
}

Token Tokenizer::GetNextToken() {
  Token tok;
  string current;

  while (isspace(buffer[point]))
    point++;

  while (point < buffer.length()) {

    current += buffer[point++];

    if (current == "(") {
      tok.token = LPAREN;
      break;
    }
    if (current == ")") {
      tok.token = RPAREN;
      break;
    }
    if (current == "INSERT") {
      tok.token = INSERT;
      break;
    }
  }

  return tok;
}