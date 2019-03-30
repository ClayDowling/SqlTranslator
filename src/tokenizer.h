#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include "token.h"

class Tokenizer {
public:
  Tokenizer(std::string);

  Token GetNextToken();

private:
  std::string buffer;
  unsigned int point;
};

#endif