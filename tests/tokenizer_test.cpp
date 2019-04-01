#include "tokenizer.h"

#include <gtest/gtest.h>
#include <string>

using namespace ::testing;
using namespace std;

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

  ASSERT_EQ(first.col, 0);
  ASSERT_EQ(first.token, LPAREN);

  ASSERT_EQ(second.col, 2);
  ASSERT_EQ(second.token, RPAREN);
}

TEST(Tokenizer, givenInsert_ReturnsINSERT) {
  Tokenizer tokenizer("INSERT");
  Token actual = tokenizer.GetNextToken();
  ASSERT_EQ(actual.token, INSERT);
}

TEST(Tokenizer, givenMixedCaseInsert_ReturnsINSERT) {
  Tokenizer tokenizer("InSeRt");
  Token actual = tokenizer.GetNextToken();
  ASSERT_EQ(actual.token, INSERT);
}

TEST(Tokenizer, givenInto_ReturnsINTO) {
  Tokenizer tokenizer("into");
  Token actual = tokenizer.GetNextToken();
  ASSERT_EQ(actual.token, INTO);
}

TEST(Tokenizer, givenValues_ReturnsVALUES) {
  Tokenizer tokenizer("Values");
  Token actual = tokenizer.GetNextToken();
  ASSERT_EQ(actual.token, VALUES);
}

TEST(Tokenizer, givenComma_returnsCOMMA) {
  Tokenizer tokenizer(",");
  Token actual = tokenizer.GetNextToken();
  ASSERT_EQ(actual.token, COMMA);
}

TEST(Tokenizer, givenIdentifier_ReturnsIDENTIFIER) {
  Tokenizer tokenizer(" Cat ");
  Token actual = tokenizer.GetNextToken();
  ASSERT_EQ(actual.token, IDENTIFIER);
}

TEST(Tokenizer, givenNumeric_ReturnsNUMERIC_CONSTANT) {
  Tokenizer tokenizer("2 123");
  Token first = tokenizer.GetNextToken();
  Token second = tokenizer.GetNextToken();
  ASSERT_EQ(first.token, NUMERIC_CONSTANT);
  ASSERT_EQ(first.literal, "2");

  ASSERT_EQ(second.token, NUMERIC_CONSTANT);
  ASSERT_EQ(second.literal, "123");
}