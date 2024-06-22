#include "graph.h"

#include "ui_graph.h"

namespace s21 {
graph::graph(QWidget *parent) : QDialog(parent), ui(new Ui::graph) {
  ui->setupUi(this);
  connect(ui->doubleSpinBox_x_min, SIGNAL(valueChanged(double)), this,
          SLOT(on_pushButton_build_graph_clicked()));
  connect(ui->doubleSpinBox_x_max, SIGNAL(valueChanged(double)), this,
          SLOT(on_pushButton_build_graph_clicked()));
}

graph::~graph() { delete ui; }

void graph::set_expr_label(QString expr) {
  ui->label_input_expr->setText(expr);
}

void graph::on_pushButton_build_graph_clicked() {
  expr = ui->label_input_expr->text().toStdString();
  double x_min = std::min(ui->doubleSpinBox_x_min->value(),
                          ui->doubleSpinBox_x_max->value());
  double x_max = std::max(ui->doubleSpinBox_x_min->value(),
                          ui->doubleSpinBox_x_max->value());
  double y_min = 0.0;
  double y_max = 0.0;
  ui->widget->clearGraphs();
  QVector<double> x, y;
  ui->widget->addGraph();

  ui->widget->xAxis->setLabel("X");
  ui->widget->yAxis->setLabel("Y");
  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->setAutoFillBackground(true);

  unsigned long long N = (std::fabs(x_min) + std::fabs(x_max)) * 10;
  for (unsigned long long i = 0; i < N; ++i) {
    s21::Controller control(expr, x_min);
    if (control.ValidExpression()) {
      double y_result = std::stod(control.Calculate());
      x.push_back(x_min);
      y.push_back(y_result);

      if (y_min > y_result) {
        y_min = y_result;
      }

      if (y_max < y_result) {
        y_max = y_result;
      }

      x_min += 0.1;
    } else {
      QMessageBox::information(this, "Error", "Input error");
      break;
    }
  }

  y_min += y_min * 0.1;
  y_max += y_max * 0.1;

  ui->widget->yAxis->setRange(y_min, y_max);

  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
  x.clear();
  y.clear();
}

void graph::keyPressEvent(QKeyEvent *event) {
  if (strchr("0123456789(,)+-*/%^sincotaqrlgXe",
             event->text().toStdString()[0])) {
    ui->label_input_expr->setText(ui->label_input_expr->text() + event->text());
  } else if (event->key() == Qt::Key_Backspace) {
    ui->label_input_expr->setText(ui->label_input_expr->text().left(
        ui->label_input_expr->text().size() - 1));
  } else if (event->key() == Qt::Key_Delete) {
    ui->label_input_expr->clear();
  } else if (event->key() == Qt::Key_Enter || event->key() == 16777220) {
    on_pushButton_build_graph_clicked();
  }
  //    space???
}

}  // namespace s21
