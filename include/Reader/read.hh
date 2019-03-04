#pragma once

#include "library.hh"

Object read_object();
void change_lexer_input(FILE *stream);
FILE *get_lexer_input();
