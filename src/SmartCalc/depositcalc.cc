#include "depositcalc.h"

#include "ui_depositcalc.h"

namespace s21 {
DepositCalc::DepositCalc(QWidget *parent)
    : QDialog(parent), ui(new Ui::DepositCalc) {
  ui->setupUi(this);
}

DepositCalc::~DepositCalc() { delete ui; }

void DepositCalc::on_pushButton_include_clicked() {
  bool ok;
  data.include_list.push_back(
      QInputDialog::getDouble(this, tr("Include payment:"), tr("Value = "), 0.0,
                              -MAXFLOAT, MAXFLOAT, 8, &ok));
}

void DepositCalc::on_pushButton_exclude_clicked() {
  bool ok;
  data.exclude_list.push_back(
      QInputDialog::getDouble(this, tr("Exclude payment:"), tr("Value = "), 0.0,
                              -MAXFLOAT, MAXFLOAT, 8, &ok));
}

void DepositCalc::on_pushButton_clicked() {
  ui->result_depos->clear();
  if (ui->amount_deposit->value() > 0 && ui->period_deposit->value() > 0 &&
      ui->rate_interest->value() > 0) {
    data.S = ui->amount_deposit->value();
    data.time = ui->period_deposit->value();
    data.percent = ui->rate_interest->value();
    data.tax = ui->rate_tax->value();
    data.period_pay = ui->comboBox_per->currentIndex();
    data.capital = ui->checkBox_capital->isChecked();

    s21::Controller::CalculateDeposit(data);
    ui->result_depos->setText("Total Payment: " + QString::number(data.total) +
                              '\n');
    ui->result_depos->setText(ui->result_depos->toPlainText() +
                              "Total Percent Payment: " +
                              QString::number(data.payment_percent) + '\n');
    ui->result_depos->setText(ui->result_depos->toPlainText() +
                              "Total Tax: " + QString::number(data.tax_total));
    data.include_list.clear();
    data.exclude_list.clear();
  }
}

}  // namespace s21
