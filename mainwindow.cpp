#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
    ui->current_lineEdit->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ProceessNum(int num){
    QString current = ui->lineEdit->text();

    if (!reset_mode) {
        if(current == "0"){
            ui->lineEdit->setText(QString::number(num));
        }else{
            ui->lineEdit->setText(current + QString::number(num));
        }
    } else {  // reset_mode == 0
        reset_mode = 0;
        ui->lineEdit->setText(QString::number(num));
    }

    int value = ui->lineEdit->text().toInt();

    QString binaryString = QString::number(value, 2);
    int padding = 4 - (binaryString.length() % 4);
    if (padding != 4) {
        binaryString = QString(padding, '0') + binaryString;
    }
    for (int i = 4; i < binaryString.length(); i += 5) {
        binaryString.insert(i, ' ');
    }
    ui->Bin_lineEdit->setText(binaryString);

    QString octalString = QString::number(value, 8);
    ui->Oct_lineEdit->setText(octalString);

    QString hexString = QString::number(value, 16).toUpper();
    ui->Hex_lineEdit->setText(hexString);

}

void MainWindow::ProcessOperation(char get_operation_flag){
    operation_flag = get_operation_flag;
    reset_mode = 1;
    first_num = ui->lineEdit->text().toDouble();

    switch(get_operation_flag){
    case 1:
        ui->current_lineEdit->setText(QString::number(first_num) + " + ");
        break;
    case 2:
        ui->current_lineEdit->setText(QString::number(first_num) + " - ");
        break;
    case 3:
        ui->current_lineEdit->setText(QString::number(first_num) + " * ");
        break;
    case 4:
        ui->current_lineEdit->setText(QString::number(first_num) + " % ");
        break;
    }
}

// 0
void MainWindow::on_Number0_button_clicked()
{
    ProceessNum(0);
}

// 1
void MainWindow::on_Number1_button_clicked()
{
    ProceessNum(1);
}

// 2
void MainWindow::on_Number2_button_clicked()
{
    ProceessNum(2);
}

// 3
void MainWindow::on_Number3_button_clicked()
{
    ProceessNum(3);
}

// 4
void MainWindow::on_Number4_button_clicked()
{
    ProceessNum(4);
}

// 5
void MainWindow::on_Number5_button_clicked()
{
    ProceessNum(5);
}

// 6
void MainWindow::on_Number6_button_clicked()
{
    ProceessNum(6);
}

// 7
void MainWindow::on_Number7_button_clicked()
{
    ProceessNum(7);
}

// 8
void MainWindow::on_Number8_button_clicked()
{
    ProceessNum(8);
}

// 9
void MainWindow::on_Number9_button_clicked()
{
    ProceessNum(9);
}

// 1/x
void MainWindow::on_Reciprocal_clicked()
{
    double num = 1.0 / ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(num,'f',5));
}

// x^2
void MainWindow::on_Square_button_clicked()
{
    double num = ui->lineEdit->text().toDouble();
    ui->lineEdit->setText(QString::number(num*num));
}

// √x
void MainWindow::on_quareRoot_button_clicked()
{
    double num = ui->lineEdit->text().toDouble();
    double root = 1.0;

    for(int i=0; i<100; i++){
        root = 0.5 * (root + num/root);
    }

    ui->lineEdit->setText(QString::number(root));
}

// CE
void MainWindow::on_CE_button_clicked()
{
    ui->lineEdit->setText("0");
    ui->current_lineEdit->setText("0");
    ui->Bin_lineEdit->setText("0");
    ui->Oct_lineEdit->setText("0");
    ui->Hex_lineEdit->setText("0");

    operation_flag = 0;
    first_num = 0;
    reset_mode = 0;
}

// C
void MainWindow::on_C_button_clicked()
{
    ui->lineEdit->setText("0");
    ui->Bin_lineEdit->setText("0");
    ui->Oct_lineEdit->setText("0");
    ui->Hex_lineEdit->setText("0");

}

// +/-
void MainWindow::on_PlusMinus_button_clicked()
{
    double num = ui->lineEdit->text().toDouble();
    if(!plus_minus_flag){
        num = -num;
        ui->lineEdit->setText(QString::number(num));
    }else{
        num = +num;
        ui->lineEdit->setText(QString::number(num));
    }
}

// +
void MainWindow::on_Sum_button_clicked()
{
    ProcessOperation(1);
}

// -
void MainWindow::on_Sub_button_clicked()
{
    ProcessOperation(2);
}

// *
void MainWindow::on_Mul_button_clicked()
{
    ProcessOperation(3);
}

// %
void MainWindow::on_Div_button_clicked()
{
    ProcessOperation(4);
}

// <-
void MainWindow::on_Back_button_clicked()
{
    int num = ui->lineEdit->text().toInt() / 10;
    ui->lineEdit->setText(QString::number(num));

    int value = ui->lineEdit->text().toInt();

    QString binaryString = QString::number(value, 2);
    int padding = 4 - (binaryString.length() % 4);
    if (padding != 4) {
        binaryString = QString(padding, '0') + binaryString;
    }
    for (int i = 4; i < binaryString.length(); i += 5) {
        binaryString.insert(i, ' ');
    }
    ui->Bin_lineEdit->setText(binaryString);

    QString octalString = QString::number(value, 8);
    ui->Oct_lineEdit->setText(octalString);

    QString hexString = QString::number(value, 16).toUpper();
    ui->Hex_lineEdit->setText(hexString);
}

// .
void MainWindow::on_Dot_button_clicked()
{
    QString current = ui->lineEdit->text();

    dot_flag = 1;

    if(!current.contains('.')){
        ui->lineEdit->setText(current + ".");
    }
}

// =
void MainWindow::on_Equal_button_clicked()
{
    double second_num = ui->lineEdit->text().toDouble();
    double result = 0;
    QString operation;

    switch(operation_flag){
    case 1: // add
        result = first_num + second_num;
        operation = QString(" + ");
        break;
    case 2: // sub
        result = first_num - second_num;
        operation = QString(" - ");
        break;
    case 3: // mul
        result = first_num * second_num;
        operation = QString(" * ");
        break;
    case 4: // div
        result = first_num / second_num;
        operation = QString(" % ");
        break;
    }

    ui->lineEdit->setText(QString::number(result));
    ui->current_lineEdit->setText(QString::number(first_num) + operation + QString::number(second_num) + " = ");

    int value = ui->lineEdit->text().toInt();

    QString binaryString = QString::number(value, 2);
    int padding = 4 - (binaryString.length() % 4);
    if (padding != 4) {
        binaryString = QString(padding, '0') + binaryString;
    }
    for (int i = 4; i < binaryString.length(); i += 5) {
        binaryString.insert(i, ' ');
    }
    ui->Bin_lineEdit->setText(binaryString);

    QString octalString = QString::number(value, 8);
    ui->Oct_lineEdit->setText(octalString);

    QString hexString = QString::number(value, 16).toUpper();
    ui->Hex_lineEdit->setText(hexString);

    reset_mode = 1;
}

