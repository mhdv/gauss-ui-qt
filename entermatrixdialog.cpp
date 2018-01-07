#include "entermatrixdialog.h"
#include "ui_entermatrixdialog.h"

#include <QMessageBox>
#include <iostream>

EnterMatrixDialog::EnterMatrixDialog(QWidget *parent, int value) :
    QDialog(parent),
    ui(new Ui::EnterMatrixDialog)
{
    ui->setupUi(this);
    size=value;
    index=0;
    Equations<float> tmp(size);
    equation = tmp;
    ui->sizeLcd->display(double(size));
}

EnterMatrixDialog::~EnterMatrixDialog()
{
    delete ui;
}

void EnterMatrixDialog::on_okButton_clicked()
{
    QString stringvar = ui->textEdit->toPlainText();
    if(stringvar!=NULL){
    if(index<size*(size+1))
    {
        equation.addValue(stringvar.split(" ")[0].toFloat(), size);
        index++;
    }else{
        ui->actualElementLabel->setText("Wpisałeś już wszystkie liczby!");
    }
    ui->textEdit->clear();
    }
}

void EnterMatrixDialog::on_exitButton_clicked()
{
    delete ui;
    std::exit(0);
}

void EnterMatrixDialog::on_solveButton_clicked()
{
    if(equation.isEmpty(size)==0){
    equation.solveEquation(size);
    float* result = equation.returnResult();
    QString s;
    s = "Wyniki: [";
    for(int i=0; i<size; i++){
        if(i!=size-1)
        s = s + QString::number(result[i]) + " ;";
        if(i==size-1)
        s = s + QString::number(result[i]);
    }
    s = s + "]";
    QMessageBox box;
    box.information(this, "Oto Twoje wyniki!", s , QMessageBox::Ok);
    }else{
        QMessageBox warning;
        warning.warning(this, "UWAGA!", "NIE WYPELNILES MACIERZY!");
    }
}

void EnterMatrixDialog::on_backButton_clicked()
{
    this->close();
}
