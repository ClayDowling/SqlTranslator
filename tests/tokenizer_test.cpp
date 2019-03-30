#include "tokenizer.h"

#include <gtest/gtest.h>

using namespace ::testing;

TEST(Tokenizer, givenLeftParen_ReturnsLPAREN) {

  Tokenizer tokenizer("(");

  Token tok = tokenizer.GetNextToken();

  ASSERT_EQ(tok.token, LPAREN);
}

TEST(Tokenizer, givenRightParen_ReturnsRPAREN) {
  Tokenizer tokenizer(")");
  Token tok = tokenizer.GetNextToken();

  ASSERT_EQ(tok.token, RPAREN);
}

TEST(Tokenizer,
     givenLeftAndRigtParen_ReturnsLPARENAndRPARENOneSubsequentCalls) {
  Tokenizer tokenizer("( )");
  Token first = tokenizer.GetNextToken();
  Token second = tokenizer.GetNextToken();

  ASSERT_EQ(first.token, LPAREN);
  ASSERT_EQ(second.token, RPAREN);
}

TEST(Tokenizer, givenInsert_ReturnsINSERT) {
  Tokenizer tokenizer("INSERT");
  Token actual = tokenizer.GetNextToken();
  ASSERT_EQ(actual.token, INSERT);
}