#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include <QListWidgetItem>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_delete_sm_btn_clicked();
    void on_view_more_clicked();
    void onTabChanged(int index);
    void loadServicesForLastMonth();

    void on_add_transaction_clicked();
    void on_edit_transaction_clicked();
    void on_delete_transaction_clicked();
    void loadTransactions();
    void loadEmployees();
    void editSalary();
    void sortTransactions();
    void searchTransactions();
    void sortEmployees();
    void searchEmployees();
    void exportToPdf();
    void loadFichDePay();
    void loadStatistics();
    void printStatistics();
    void onTransactionSelected();
    void handleSerialData(); // Slot to handle data from Arduino

private:
    Ui::MainWindow *ui;
    QSerialPort *serial; // Serial port for Arduino communication
    void setupSerialPort(); // Function to initialize the serial port
};

#endif // MAINWINDOW_H
