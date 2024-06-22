#include "Model.h"

#include <cstring>

namespace s21 {

bool Model::Validator() {
  std::size_t len = str_.length();
  if (len > 255) return false;

  std::size_t o_br = 0;
  std::size_t c_br = 0;

  for (std::size_t i = 0; i < len; ++i) {
    if (ValidatorNumber(i) == false) return false;
    if (ValidatorOperators(i) == false) return false;
    if (ValidatoForLongFunc(i) == false) return false;
    if (str_[i] == '(') ++o_br;
    if (str_[i] == ')') ++c_br;
  }

  if (o_br != c_br) return false;

  return true;
}

bool Model::ValidatorNumber(std::size_t i) {
  if (strchr("0123456789", str_[i]) &&
      !strchr("0123456789e.,+-*/^%)", str_[i + 1])) {
    return false;
  }

  if (str_[i] == 'e' && (!strchr("+-)", str_[i + 1]) || !str_[i + 1]))
    return false;
  if (str_[i] == 'X' && !strchr("+-*/^%)", str_[i + 1])) return false;

  if (strchr(".,", str_[i]) &&
      (!strchr("0123456789", str_[i + 1]) || !str_[i + 1] || !i)) {
    return false;
  }

  return true;
}

bool Model::ValidatorOperators(std::size_t i) {
  if (strchr("+-*/%^", str_[i]) &&
      (!strchr("0123456789cstal(X", str_[i + 1]) || !str_[i + 1])) {
    return false;
  }

  if (strchr("(", str_[i]) && !strchr("0123456789cstal(+-X", str_[i + 1]))
    return false;
  if (strchr(")", str_[i]) && !strchr("+-*/%^)", str_[i + 1])) return false;

  return true;
}

bool Model::ValidatoForLongFunc(std::size_t i) {
  if (str_[i] == 'c' && (str_[i + 1] != 'o' || !str_[i + 1])) return false;
  if (str_[i] == 'i' && str_[i + 1] != 'n') return false;
  if (str_[i] == 'n' && str_[i + 1] != '(') return false;
  if (str_[i] == 'g' && str_[i + 1] != '(') return false;
  if (str_[i] == 'q' && str_[i + 1] != 'r') return false;
  if (str_[i] == 'r' && str_[i + 1] != 't') return false;
  if (str_[i] == 'o' && (!strchr("sg", str_[i + 1]) || !str_[i + 1]))
    return false;
  if (str_[i] == 't' && !strchr("a(", str_[i + 1])) return false;
  if (str_[i] == 'l' && (!strchr("on", str_[i + 1]) || !str_[i + 1]))
    return false;
  if (str_[i] == 's' && !strchr("iq(", str_[i + 1])) return false;
  if (str_[i] == 'a' && (!strchr("cstn", str_[i + 1]) || !str_[i + 1]))
    return false;
  if (strchr("sngt", str_[i]) && (!strchr("(iqa", str_[i + 1]) || !str_[i + 1]))
    return false;

  return true;
}

void Model::Parser() {
  std::size_t len = str_.length();

  for (std::size_t i = 0; i < len; ++i) {
    if (str_[i] == '-' && str_[i - 1] == '(') {
      tokens_.push_back(Token(0.0, UNAR_SUBSTRUCT, 1));
      ++i;
    }

    if (str_[i] == '+' && str_[i - 1] == '(') {
      tokens_.push_back(Token(0.0, UNAR_ADD, 1));
      ++i;
    }

    NumberHandler(i);
    BinaryOperation(i);
    LongFunction(i);
  }
}

void Model::NumberHandler(std::size_t &i) {
  if (strchr("0123456789", str_[i])) {
    std::size_t n = 0;
    tokens_.push_back(Token(std::stod(&str_[i], &n), NUMBER, -1));
    i += n;
  }
}

void Model::BinaryOperation(std::size_t &i) {
  if (str_[i] == 'X') tokens_.push_back(Token(x_, NUMBER, -1));

  if (str_[i] == '+') tokens_.push_back(Token(0.0, ADD, 1));
  if (str_[i] == '-') tokens_.push_back(Token(0.0, SUBSTRUCT, 1));
  if (str_[i] == '*') tokens_.push_back(Token(0.0, MULTIPLIE, 2));
  if (str_[i] == '/') tokens_.push_back(Token(0.0, DIVISION, 2));
  if (str_[i] == '%') tokens_.push_back(Token(0.0, DIVISION_MOD, 2));
  if (str_[i] == '^') tokens_.push_back(Token(0.0, POWER, 3));

  if (str_[i] == '(') tokens_.push_back(Token(0.0, OPEN_BRACKET, 0));
  if (str_[i] == ')') tokens_.push_back(Token(0.0, CLOSE_BRACKET, 0));
}

void Model::LongFunction(std::size_t &i) {
  if (str_.substr(i, 3) == "cos") tokens_.push_back(Token(0.0, COSINUS, 3));
  if (str_.substr(i, 3) == "sin") tokens_.push_back(Token(0.0, SINUS, 3));
  if (str_.substr(i, 3) == "tan") tokens_.push_back(Token(0.0, TANGENS, 3));
  if (str_.substr(i, 4) == "acos") tokens_.push_back(Token(0.0, ARCCOS, 3));
  if (str_.substr(i, 4) == "asin") tokens_.push_back(Token(0.0, ARCSIN, 3));
  if (str_.substr(i, 4) == "atan") tokens_.push_back(Token(0.0, ARCTAN, 3));
  if (str_.substr(i, 2) == "ln") tokens_.push_back(Token(0.0, LNX, 3));
  if (str_.substr(i, 3) == "log") tokens_.push_back(Token(0.0, LOGX, 3));
  if (str_.substr(i, 4) == "sqrt") tokens_.push_back(Token(0.0, SQRT, 3));
}

void Model::PostfixNotation() {
  for (auto it = tokens_.begin(); it != tokens_.end(); ++it) {
    if (it->type_ == NUMBER) {
      queue_.push_back(*it);
    }

    if (it->type_ == UNAR_ADD || it->type_ == UNAR_SUBSTRUCT)
      stack_.push_front(*it);

    if ((it->type_ >= COSINUS && it->type_ <= ARCTAN) ||
        (it->type_ >= LNX && it->type_ <= POWER)) {
      stack_.push_front(*it);
    }

    if (it->type_ >= ADD && it->type_ <= DIVISION_MOD) {
      if (!stack_.empty()) {
        auto it1 = stack_.begin();
        while (it1 != stack_.end() && it1->type_ != OPEN_BRACKET &&
               it1->prio_ >= it->prio_) {
          queue_.push_back(*it1);
          ++it1;
        }
        stack_.erase(stack_.begin(), it1);
      }
      stack_.push_front(*it);
    }

    if (it->type_ == OPEN_BRACKET) {
      stack_.push_front(*it);
    } else if (it->type_ == CLOSE_BRACKET) {
      auto it1 = stack_.begin();
      for (; it1 != stack_.end() && it1->type_ != OPEN_BRACKET; ++it1) {
        queue_.push_back(*it1);
      }
      stack_.erase(stack_.begin(), it1);
      stack_.pop_front();
    }
  }

  for (auto it = stack_.begin(); it != stack_.end(); ++it) {
    queue_.push_back(*it);
  }

  tokens_.clear();
}

double Model::CalculateExpression() {
  stack_.clear();
  double ans = 0.0;

  for (auto it = queue_.begin(); it != queue_.end(); ++it) {
    if (it->type_ == NUMBER) {
      stack_.push_front(*it);
    }

    if ((it->type_ >= ADD && it->type_ <= DIVISION_MOD) || it->type_ == POWER) {
      ValueCalc(it);
    }

    if ((it->type_ >= COSINUS && it->type_ <= ARCTAN) ||
        (it->type_ >= LNX && it->type_ <= UNAR_SUBSTRUCT &&
         it->type_ != POWER)) {
      FunctionCalc(it);
    }
  }
  ans = stack_.begin()->num_;
  stack_.clear();
  queue_.clear();

  return ans;
}

void Model::ValueCalc(std::list<Token>::iterator &it) {
  double res = 0;
  auto it0 = stack_.begin();
  auto it1 = it0;
  ++it1;

  if (it->type_ == ADD) res = it1->num_ + it0->num_;
  if (it->type_ == SUBSTRUCT) res = it1->num_ - it0->num_;
  if (it->type_ == MULTIPLIE) res = it1->num_ * it0->num_;
  if (it->type_ == DIVISION) res = it1->num_ / it0->num_;
  if (it->type_ == DIVISION_MOD) res = fmod(it1->num_, it0->num_);
  if (it->type_ == POWER) res = pow(it1->num_, it0->num_);

  stack_.pop_front();
  it1->num_ = res;
}

void Model::FunctionCalc(std::list<Token>::iterator &it) {
  double res = 0;
  if (it->type_ == COSINUS) res = cos(stack_.begin()->num_);
  if (it->type_ == SINUS) res = sin(stack_.begin()->num_);
  if (it->type_ == TANGENS) res = tan(stack_.begin()->num_);
  if (it->type_ == ARCCOS) res = acos(stack_.begin()->num_);
  if (it->type_ == ARCSIN) res = asin(stack_.begin()->num_);
  if (it->type_ == ARCTAN) res = atan(stack_.begin()->num_);
  if (it->type_ == LNX) res = log(stack_.begin()->num_);
  if (it->type_ == LOGX) res = log10(stack_.begin()->num_);
  if (it->type_ == SQRT) res = sqrt(stack_.begin()->num_);
  if (it->type_ == UNAR_ADD) res = +(stack_.begin()->num_);
  if (it->type_ == UNAR_SUBSTRUCT) res = -(stack_.begin()->num_);
  stack_.begin()->num_ = res;
}

t_credit_data Model::CreditCalc(double S, std::size_t time, double percent,
                                bool type) {
  t_credit_data data_credit;
  if (type == true) {
    double k = percent / 100.0 / 12.0;
    double month_pay = S * (k + (k / (pow((1 + k), time) - 1)));
    double total = month_pay * time;

    data_credit.total = total;
    data_credit.month_pay.push_back(month_pay);
    data_credit.overpayment = total - S;
  } else {
    DiffCredit(S, time, percent, data_credit);
  }

  return data_credit;
}

void Model::DiffCredit(double S, size_t n, double i, t_credit_data &data_cr) {
  double St = S / (n);
  double Sn = S;
  double sum = 0.0;

  while (n > 0) {
    double P;
    double In;
    In = (Sn * (i / 100.0)) / 12;
    Sn = Sn - St;
    P = St + In;
    sum += P;
    --n;
    data_cr.month_pay.push_back(P);
  }
  data_cr.total = sum;
  data_cr.overpayment = sum - S;
}

void Model::DepositCalc(t_deposit_data &data) {
  data.percent = data.percent / 100.0 / 12.0;
  data.tax = data.tax / 100.0;

  for (auto item : data.include_list) {
    data.S += item;
  }

  for (auto item : data.exclude_list) {
    data.S += item;
  }

  if (data.period_pay == MONTH) {
    data.period_pay = data.time * 12;
    data.percent /= 12.0;
  } else if (data.period_pay == QARTER) {
    data.period_pay = data.time * 4;
    data.percent /= 4.0;
  } else if (data.period_pay == YEAR) {
    data.period_pay = data.time;
  }

  double P = data.S;
  std::size_t i = data.period_pay;

  if (data.capital == true) {
    while (i > 0) {
      P = P * (1.0 + data.percent);
      --i;
    }

    data.total = P;
    data.payment_percent = P - data.S;
    data.tax_total = (P - data.S) * data.tax;
  } else {
    P = 0.0;
    while (i > 0) {
      P += data.S * data.percent;
      --i;
    }

    data.total = P + data.S;
    data.payment_percent = P;
    data.tax_total = P * data.tax;
  }
}

std::string Model::SmartCalc() {
  double ans = 0.0;
  if (Validator()) {
    Parser();
    PostfixNotation();
    ans = CalculateExpression();

    std::ostringstream os;
    os.precision(precision_);
    os << ans;

#if defined(__unix__)
    std::size_t pos = os.str().find(".");
    if (pos != std::string::npos) return os.str().replace(pos, 1, ",");
#endif

    return os.str();
  }
  return "Input error";
}

}  // namespace s21
