#ifndef DEPOSITCALC_H
#define DEPOSITCALC_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class DepositCalc;
}

namespace s21 {
class DepositCalc : public QDialog {
  Q_OBJECT

 public:
  explicit DepositCalc(QWidget *parent = nullptr);
  ~DepositCalc();

  t_deposit_data data;

 private slots:
  void on_pushButton_include_clicked();

  void on_pushButton_exclude_clicked();

  void on_pushButton_clicked();

 private:
  Ui::DepositCalc *ui;
};

}  // namespace s21

#endif  // DEPOSITCALC_H
