#ifndef SRC_MODEL_H_
#define SRC_MODEL_H_

#include <cmath>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include "Token.h"

using std::cin;
using std::cout;
using std::endl;

const bool ANN = true;
const bool DIF = false;

typedef struct {
  std::vector<double> month_pay;
  double overpayment;
  double total;
} t_credit_data;

typedef enum { MONTH, QARTER, YEAR } t_period_pay;

typedef struct {
  double S;
  std::size_t time;
  double percent;
  double tax;
  std::size_t period_pay;
  bool capital;
  std::vector<double> include_list;
  std::vector<double> exclude_list;

  double payment_percent;
  double tax_total;
  double total;

} t_deposit_data;

namespace s21 {
class Model {
 private:
 public:
  std::string str_;
  double x_;
  std::list<Token> tokens_;
  std::list<Token> stack_;
  std::list<Token> queue_;
  int precision_ = 6;

 public:
  Model() : str_(""), x_(0.0) {}
  Model(const std::string &str) : str_(str), x_(0.0) {}
  Model(const std::string &str, const double &x) : str_(str), x_(x) {}
  Model(const std::string &str, const double &x, int precision = 6)
      : str_(str), x_(x), precision_(precision) {}

  // SmartCalc
  std::string SmartCalc();
  // End smartCalc

  bool Validator();
  bool ValidatorNumber(std::size_t i);
  bool ValidatorOperators(std::size_t i);
  bool ValidatoForLongFunc(std::size_t i);
  // PARSER
  void Parser();
  void NumberHandler(std::size_t &i);
  void BinaryOperation(std::size_t &i);
  void LongFunction(std::size_t &i);
  // END PARSER

  // CONVERSION TO POSTFIX NOTATION
  void PostfixNotation();
  // END CONVERSION TO POSTFIX NOTATION

  // CALCULATE EXPRESSION
  double CalculateExpression();
  void ValueCalc(std::list<Token>::iterator &it);
  void FunctionCalc(std::list<Token>::iterator &it);
  // END CALCULATE EXPRESSION

  // CREDIT CALCULATION
  static t_credit_data CreditCalc(double S, std::size_t time, double percent,
                                  bool type);
  static void DiffCredit(double S, size_t n, double i, t_credit_data &data_cr);
  // END CREDIT CACLULATION

  // DEPOSIT CACLULATION
  static void DepositCalc(t_deposit_data &data);
  // END DEPOSIT CACLULATION
  void DisplayList();
};

};  // namespace s21

#endif
