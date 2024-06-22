#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include "Model.h"

namespace s21 {
class Controller {
 private:
  Model model_;

 public:
  Controller() {}
  Controller(std::string &str, double x = 0.0, int prec = 6)
      : model_(str, x, prec) {}
  Controller(const Controller &other) = delete;
  Controller(Controller &&other) = delete;
  Controller &operator=(const Controller &other) = delete;
  Controller &operator=(Controller &&other) = delete;
  ~Controller() {}

  bool ValidExpression() { return model_.Validator(); }
  std::string Calculate();
  static t_credit_data CalculateCredit(double S, std::size_t time,
                                       double percent, bool type);
  static void CalculateDeposit(t_deposit_data &data);
};

}  // namespace s21

#endif