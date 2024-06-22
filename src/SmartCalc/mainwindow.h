#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QInputDialog>
#include <QKeyEvent>
#include <QMainWindow>

#include "../Controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void TextFromButton();

  void on_pushButton_AC_clicked();

  void on_pushButton_C_clicked();

  void on_pushButton_equal_clicked();

  void on_pushButton_graph_clicked();

  void on_pushButton_credit_calc_clicked();

  void on_pushButton_deposit_calc_clicked();

  void press_dot_handler();

 protected:
  virtual void keyPressEvent(QKeyEvent *event);

 private:
  Ui::MainWindow *ui;
};

}  // namespace s21

#endif  // MAINWINDOW_H
