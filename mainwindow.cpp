#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QDebug>

int board[9][9];

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

bool isValid(int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i + startRow][j + startCol] == num)
                return false;
    return true;
}

bool MainWindow::solveSudoku() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku())
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void MainWindow::readBoardFromTable() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            QString value = item ? item->text() : "0";
            int num = value.toInt();
            board[row][col] = (num >= 1 && num <= 9) ? num : 0;
        }
    }
}

bool MainWindow::isInitialBoardValid() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int num = board[row][col];
            if (num != 0) {
                board[row][col] = 0;
                if (!isValid(row, col, num)) {
                    board[row][col] = num;
                    return false;
                }
                board[row][col] = num;
            }
        }
    }
    return true;
}

void MainWindow::on_pushButton_clicked()
{

    readBoardFromTable();

    if (!isInitialBoardValid()) {
        qInfo() << "Invalid input";
        return;
    }

    if (solveSudoku()) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                QString value = QString::number(board[row][col]);
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(value));
            }
        }
        qInfo() << "Sudoku solved";
    } else {
        qInfo() << "No solution found";
    }

}

void MainWindow::on_pushButton_2_clicked() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(""));
            board[row][col] = 0;
        }
    }
    qInfo() << "Board cleared";
}

