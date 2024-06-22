#ifndef CREDITCALC_H
#define CREDITCALC_H

#include <QDialog>

namespace Ui {
class CreditCalc;
}

namespace s21 {
class CreditCalc : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalc(QWidget *parent = nullptr);
  ~CreditCalc();

 private slots:
  void on_pushButton_calculate_credit_clicked();

 private:
  Ui::CreditCalc *ui;
};

}  // namespace s21
#endif  // CREDITCALC_H
