#include "tokenizer.h"
#include <cctype>
#include <cstring>

using namespace std;

Tokenizer::Tokenizer(string src) {
  buffer = src;
  point = 0;
}

token_t identify_keyword(string candidate) {
  string target = "";

  for (unsigned int i = 0; i < candidate.length(); ++i) {
    target += tolower(candidate[i]);
  }

  if (target == "insert") {
    return INSERT;
  }
  if (target == "into") {
    return INTO;
  }
  if (target == "values") {
    return VALUES;
  }

  bool isnumeric = true;
  for (unsigned int i = 0; isnumeric && i < candidate.length(); ++i) {
    if (!isdigit(candidate[i]))
      isnumeric = false;
  }
  if (isnumeric) {
    return NUMERIC_CONSTANT;
  }

  return IDENTIFIER;
}

Token Tokenizer::GetNextToken() {
  Token tok;
  string candidate;
  char cur;

  while (isspace(buffer[point]))
    point++;

  tok.col = point;
  while (tok.token == UNSET && point < buffer.length()) {

    cur = buffer[point++];
    switch (cur) {
    case '(':
      tok.token = LPAREN;
      break;
    case ')':
      tok.token = RPAREN;
      break;
    case ',':
      tok.token = COMMA;
      break;
    case ' ':
    case '\r':
    case '\t':
    case '\n':
    case 0:
      break;
    default:
      candidate += cur;
    }
  }

  if (tok.token == UNSET) {
    tok.token = identify_keyword(candidate);
    tok.literal = candidate;
  }

  return tok;
}