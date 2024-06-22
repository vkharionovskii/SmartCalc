#ifndef SRC_G_TEST_H_
#define SRC_G_TEST_H_

#include <gtest/gtest.h>

#include "Controller.h"

class Test : public ::testing::Test {
 protected:
  std::string ans;
  t_deposit_data deposit;

 public:
  Test() {}
  ~Test() {}
  void SetUp() {
    deposit.S = 10000.0;
    deposit.time = 12;
    deposit.percent = 18;
    deposit.tax = 1;
    deposit.period_pay = YEAR;
    deposit.capital = false;
  }
  void TearDown() {
    deposit.S = 10000.0;
    deposit.time = 12;
    deposit.percent = 18;
    deposit.tax = 1;
    deposit.period_pay = YEAR;
    deposit.capital = false;
  }
};

#endif  // SRC_G_TEST_H_
