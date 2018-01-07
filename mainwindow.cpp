#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entermatrixdialog.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->matrixSize->setValue(1);
    size=2;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_matrixSize_valueChanged(int value)
{
    ui->matrixLcd->display(double(value+1));
    size=value+1;
}

void MainWindow::on_exitButton_clicked()
{
    delete ui;
    std::exit(0);
}

void MainWindow::on_nextButton_clicked()
{
    EnterMatrixDialog entermatrixdialog(this, size);
    entermatrixdialog.setModal(true);
    entermatrixdialog.exec();
}
