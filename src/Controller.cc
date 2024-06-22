#include "Controller.h"

namespace s21 {
std::string Controller::Calculate() { return model_.SmartCalc(); }

t_credit_data Controller::CalculateCredit(double S, std::size_t time,
                                          double percent, bool type) {
  return s21::Model::CreditCalc(S, time, percent, type);
}

void Controller::CalculateDeposit(t_deposit_data &data) {
  s21::Model::DepositCalc(data);
}

}  // namespace s21
