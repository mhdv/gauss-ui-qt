#ifndef ENTERMATRIXDIALOG_H
#define ENTERMATRIXDIALOG_H

#include <QDialog>
#include "equations.h"

namespace Ui {
class EnterMatrixDialog;
}

class EnterMatrixDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnterMatrixDialog(QWidget *parent = 0, int value = 0);
//    explicit EnterMatrixDialog(int size);
    ~EnterMatrixDialog();

private slots:
    void on_okButton_clicked();

    void on_exitButton_clicked();

    void on_solveButton_clicked();

    void on_backButton_clicked();

private:
    Ui::EnterMatrixDialog *ui;
    int size, index;
    Equations<float> equation;
};

#endif // ENTERMATRIXDIALOG_H
