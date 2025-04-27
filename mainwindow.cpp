#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>
#include <string>

// Constructor to set up the UI
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
// Destructor to clean UI
MainWindow::~MainWindow()
{
    delete ui;
}

// Function is called, when the "Lahenda" button is clicked in the UI
void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->setItem(3, 4, new QTableWidgetItem("9"));
    ui->tableWidget->setItem(3, 3, new QTableWidgetItem("6"));
    ui->tableWidget->setItem(4, 3, new QTableWidgetItem("4"));
    ui->tableWidget->setItem(4, 4, new QTableWidgetItem("2"));
    ui->tableWidget->setItem(4, 5, new QTableWidgetItem("0"));

// prints out each row in console
    for (int row = 0; row < 9; ++row) {
        std::string ridad;
        for (int col = 0; col < 9; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            QString value = item ? item->text() : "0";  // or "0" or "", depending on what you prefer
            ridad += value.toStdString();
        }
        qInfo() << ridad;
    }

}

