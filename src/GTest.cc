#include "GTest.h"

TEST_F(Test, Calculate) {
  double x = 0.0;
  std::string str = "cos(X)";
  s21::Controller control(str, 34.65);
  ans = "-0,995727";

#if defined(__APPLE__)
  ans.replace(2, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate1) {
  double x = 0.0;
  std::string str = "cos(23)+sin(tan(2))";
  s21::Controller control(str, 34.65);
  ans = "-1,35004";

#if defined(__APPLE__)
  ans.replace(2, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate2) {
  double x = 0.0;
  std::string str = "X+5";
  s21::Controller control(str, 34.65);
  ans = "39,65";

#if defined(__APPLE__)
  ans.replace(2, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate3) {
  double x = 0.0;
  std::string str = "cos(sin(tan(X^2)))+log(34,57%12,56)";
  s21::Controller control(str, 34.65);
  ans = "58,0792";

#if defined(__APPLE__)
  ans.replace(2, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate4) {
  double x = 0.0;
  std::string str = "2^2^3";
  s21::Controller control(str, 34.65);
  ans = "256";

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate5) {
  double x = 0.0;
  std::string str = "7-1+3*2/4^3%6";
  s21::Controller control(str, 34.65);
  ans = "6,09375";

#if defined(__APPLE__)
  ans.replace(1, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate6) {
  double x = 0.0;
  std::string str = "cos(ln(12^5))";
  s21::Controller control(str, 34.65);
  ans = "0,989958";

#if defined(__APPLE__)
  ans.replace(1, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate7) {
  double x = 0.0;
  std::string str = "cos(X)^2-34%12,76";
  s21::Controller control(str, 34.65);
  ans = "22";

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate8) {
  double x = 0.0;
  std::string str = "cos(X)*sin(X)";
  s21::Controller control(str, 34.65);
  ans = "0,0919544";

#if defined(__APPLE__)
  ans.replace(1, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate9) {
  double x = 0.0;
  std::string str = "tan(cos(sin(ln(log(sqrt(45))))))";
  s21::Controller control(str, 34.65);

  ans = "1,49788";

#if defined(__APPLE__)
  ans.replace(1, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate10) {
  double x = 0.0;
  std::string str = "-5-(-5)";
  s21::Controller control(str, 34.65);
  ans = "-8,88178e-16";

#if defined(__APPLE__)
  ans.replace(2, 1, ".");
#endif

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, Calculate11) {
  double x = 0.0;
  std::string str = "+5+(+5)";
  s21::Controller control(str, 34.65);
  ans = "10";

  ASSERT_EQ(control.Calculate(), ans);
}

TEST_F(Test, CalculateError) {
  double x = 0.0;
  std::string str = "tan";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError1) {
  double x = 0.0;
  std::string str = "5,,3";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError2) {
  double x = 0.0;
  std::string str = "tan(3";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError3) {
  double x = 0.0;
  std::string str = "sin()";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError4) {
  double x = 0.0;
  std::string str = "5-3*(1))";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError5) {
  double x = 0.0;
  std::string str = "-";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError6) {
  double x = 0.0;
  std::string str = "1(";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError7) {
  double x = 0.0;
  std::string str = ")1";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError8) {
  double x = 0.0;
  std::string str = ",5";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError9) {
  double x = 0.0;
  std::string str = "si5";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError10) {
  double x = 0.0;
  std::string str = "l1";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError11) {
  double x = 0.0;
  std::string str = "a";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError12) {
  double x = 0.0;
  std::string str = "si(7)";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError13) {
  double x = 0.0;
  std::string str = "co(";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError14) {
  double x = 0.0;
  std::string str = "t";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CalculateError15) {
  double x = 0.0;
  std::string str = "e";
  s21::Controller control(str, 34.65);

  ASSERT_EQ(control.Calculate(), "Input error");
}

TEST_F(Test, CreditCalc) {
  std::string str = "-";
  s21::Controller control;
  t_credit_data credit = control.CalculateCredit(1000, 12, 15, false);

  ASSERT_DOUBLE_EQ(credit.total, 1081.25);
  ASSERT_DOUBLE_EQ(credit.month_pay[0], 95.833333333333329);
  ASSERT_DOUBLE_EQ(credit.overpayment, 81.25);
}

TEST_F(Test, CreditCalc1) {
  std::string str = "-";
  s21::Controller control;
  t_credit_data credit = control.CalculateCredit(1000, 12, 15, true);

  ASSERT_DOUBLE_EQ(credit.total, 1083.0997481418867);
  ASSERT_DOUBLE_EQ(credit.month_pay[0], 90.258312345157236);
  ASSERT_DOUBLE_EQ(credit.overpayment, 83.099748141886721);
}

TEST_F(Test, DepositCalc) {
  std::string str = "-";
  s21::Controller control;

  control.CalculateDeposit(deposit);

  ASSERT_DOUBLE_EQ(deposit.total, 11800);
  ASSERT_DOUBLE_EQ(deposit.tax_total, 18);
  ASSERT_DOUBLE_EQ(deposit.payment_percent, 1800);
}

TEST_F(Test, DepositCalc2) {
  std::string str = "-";
  s21::Controller control;
  deposit.period_pay = QARTER;
  deposit.capital = true;
  deposit.tax = 0.0;

  control.CalculateDeposit(deposit);

  ASSERT_DOUBLE_EQ(deposit.total, 11968.143774194567);
  ASSERT_DOUBLE_EQ(deposit.tax_total, 0);
  ASSERT_DOUBLE_EQ(deposit.payment_percent, 1968.1437741945665);
}

TEST_F(Test, DepositCalc1) {
  std::string str = "-";
  s21::Controller control;
  deposit.period_pay = MONTH;
  deposit.include_list.push_back(1000);
  deposit.exclude_list.push_back(500);

  control.CalculateDeposit(deposit);

  ASSERT_DOUBLE_EQ(deposit.total, 13570);
  ASSERT_DOUBLE_EQ(deposit.tax_total, 20.699999999999999);
  ASSERT_DOUBLE_EQ(deposit.payment_percent, 2070);
}

// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);

//     return RUN_ALL_TESTS();
// }
