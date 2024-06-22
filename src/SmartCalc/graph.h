#ifndef GRAPH_H
#define GRAPH_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class graph;
}

namespace s21 {
class graph : public QDialog {
  Q_OBJECT

 public:
  explicit graph(QWidget *parent = nullptr);
  ~graph();

  void set_expr_label(QString expr);

 private slots:
  void on_pushButton_build_graph_clicked();

 protected:
  virtual void keyPressEvent(QKeyEvent *event);

 private:
  Ui::graph *ui;
  std::string expr;
};

}  // namespace s21

#endif  // GRAPH_H
