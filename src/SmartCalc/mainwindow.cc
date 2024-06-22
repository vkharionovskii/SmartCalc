#include "mainwindow.h"

#include "creditcalc.h"
#include "depositcalc.h"
#include "graph.h"
#include "ui_mainwindow.h"

namespace s21 {
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_one, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_two, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_three, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_four, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_five, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_six, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_seven, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_eight, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_nine, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_zero, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->pushButton_substruct, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_multiplie, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_division, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_division_mod, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_power, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_open_bracket, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(press_dot_handler()));
  connect(ui->pushButton_close_bracket, SIGNAL(clicked()), this,
          SLOT(TextFromButton()));
  connect(ui->pushButton_X, SIGNAL(clicked()), this, SLOT(TextFromButton()));
  connect(ui->spinBox_precision, SIGNAL(valueChanged(int)), this,
          SLOT(on_pushButton_equal_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::TextFromButton() {
  QPushButton *button = static_cast<QPushButton *>(sender());
  ui->Input_label->setText(ui->Input_label->text() + button->text());
}

void MainWindow::press_dot_handler() {
#if defined(__unix__)
  ui->Input_label->setText(ui->Input_label->text() + ",");
#elif defined(__APPLE__)
  ui->Input_label->setText(ui->Input_label->text() + ".");
#endif
}

void MainWindow::on_pushButton_AC_clicked() { ui->Input_label->clear(); }

void MainWindow::on_pushButton_C_clicked() {
  ui->Input_label->setText(
      ui->Input_label->text().left(ui->Input_label->text().size() - 1));
}

void MainWindow::on_pushButton_equal_clicked() {
  if (ui->Input_label->text() != "") {
    double x = 0.0;
    if (ui->Input_label->text().contains('X')) {
      bool ok;
      x = QInputDialog::getDouble(this, tr("Введите значение Х"), tr("Х = "),
                                  0.0, -MAXFLOAT, MAXFLOAT, 8, &ok);
    }

    std::string expression = ui->Input_label->text().toStdString();
    s21::Controller calc(expression, x, ui->spinBox_precision->value());
    ui->Input_label->setText(QString::fromStdString(calc.Calculate()));
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  graph graph_window;
  graph_window.set_expr_label(ui->Input_label->text());
  graph_window.setModal(true);
  graph_window.exec();
}

void MainWindow::on_pushButton_credit_calc_clicked() {
  CreditCalc credit_window;
  credit_window.setModal(true);
  credit_window.exec();
}

void MainWindow::on_pushButton_deposit_calc_clicked() {
  DepositCalc deposit_window;
  deposit_window.setModal(true);
  deposit_window.exec();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (strchr("0123456789()+-*/%^sincotaqrlgXe",
             event->text().toStdString()[0])) {
    ui->Input_label->setText(ui->Input_label->text() + event->text());
  } else if (strchr(".,", event->text().toStdString()[0])) {
    press_dot_handler();
  } else if (event->key() == Qt::Key_Backspace) {
    on_pushButton_C_clicked();
  } else if (event->key() == Qt::Key_Delete) {
    on_pushButton_AC_clicked();
  } else if (event->key() == Qt::Key_Enter || event->key() == 16777220) {
    on_pushButton_equal_clicked();
  }
  //    space???
}

}  // namespace s21
