#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->hide();
    dialog = new Dialog(this);
    dialog->show();
}

