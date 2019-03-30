#include "tokenizer.h"

#include <gtest/gtest.h>

using namespace ::testing;

TEST(Tokenizer, givenLeftParen_ReturnsLPAREN) {

  Tokenizer tokenizer("(");

  Token tok = tokenizer.GetNextToken();

  ASSERT_EQ(tok.token, LPAREN);
}