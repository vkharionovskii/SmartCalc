#ifndef SRC_TOKEN_H_
#define SRC_TOKEN_H_

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace s21 {

typedef enum types {
  NUMBER,
  ADD,
  SUBSTRUCT,
  MULTIPLIE,
  DIVISION,
  DIVISION_MOD,
  COSINUS,
  SINUS,
  TANGENS,
  ARCCOS,
  ARCSIN,
  ARCTAN,
  OPEN_BRACKET,
  CLOSE_BRACKET,
  LNX,
  LOGX,
  SQRT,
  POWER,
  UNAR_ADD,
  UNAR_SUBSTRUCT,
  DELIM,
  X
} t_type;

struct Token {
  double num_;
  t_type type_;
  int prio_;

  Token() : num_(-1), type_(NUMBER), prio_(-1) {}
  Token(double num, t_type type, size_t prio)
      : num_(num), type_(type), prio_(prio) {}
};

}  // namespace s21

#endif