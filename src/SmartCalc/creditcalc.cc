#include "creditcalc.h"

#include "mainwindow.h"
#include "ui_creditcalc.h"

namespace s21 {
CreditCalc::CreditCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::CreditCalc) {
  ui->setupUi(this);
}

CreditCalc::~CreditCalc() { delete ui; }

void CreditCalc::on_pushButton_calculate_credit_clicked() {
  if (ui->amount_cr->value() > 0 && ui->period_cr->value() > 0 &&
      ui->rate_interest->value() > 0) {
    t_credit_data data = s21::Controller::CalculateCredit(
        ui->amount_cr->value(), ui->period_cr->value(),
        ui->rate_interest->value(), ui->radioButton_ann->isChecked());

    ui->doubleSpinBox_total_payment->setValue(data.total);
    std::size_t i = 1;
    for (auto item : data.month_pay) {
      ui->textEdit_month_payment->setText(
          ui->textEdit_month_payment->toPlainText() + "Month " +
          QString::number(i++) + ": " + QString::number(item) + "\n");
    }
    ui->doubleSpinBox_overpayment->setValue(data.overpayment);
  }
}

}  // namespace s21
