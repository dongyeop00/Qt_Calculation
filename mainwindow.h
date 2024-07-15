#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private :
    char operation_flag = 0;
    char reset_mode = 0;
    double first_num = 0;
    char plus_minus_flag = 0;
    char dot_flag = 0;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ProceessNum(int num);
    void ProcessOperation(char operation_flag);

private slots:
    void on_Number0_button_clicked();

    void on_Number1_button_clicked();

    void on_Number2_button_clicked();

    void on_Number3_button_clicked();

    void on_Number4_button_clicked();

    void on_Number5_button_clicked();

    void on_Number6_button_clicked();

    void on_Number7_button_clicked();

    void on_Number8_button_clicked();

    void on_Number9_button_clicked();

    void on_Reciprocal_clicked();

    void on_Square_button_clicked();

    void on_quareRoot_button_clicked();

    void on_CE_button_clicked();

    void on_C_button_clicked();

    void on_PlusMinus_button_clicked();

    void on_Sum_button_clicked();

    void on_Sub_button_clicked();

    void on_Mul_button_clicked();

    void on_Div_button_clicked();

    void on_Back_button_clicked();

    void on_Equal_button_clicked();

    void on_Dot_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
