#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the button click to the slot
    connect(ui->btnSubmit, &QPushButton::clicked, this, &MainWindow::submitReclamation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Function to handle submit reclamation button click
void MainWindow::submitReclamation()
{
    // Add your reclamation submission logic here
}
