#include "tokenizer.h"

using namespace std;

Tokenizer::Tokenizer(string src) { buffer = src; }

Token Tokenizer::GetNextToken() { return Token(); }