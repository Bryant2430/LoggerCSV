#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secdialog.h"
#include "logger.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    logger = new Logger(this);

    ui -> tableWidget -> horizontalHeader()->setStretchLastSection(true);

    // Change the header name of the table
    QStringList header;
    header << tr("one") << tr("two") << tr("three") << tr("four");

    int numOffield = header.size();

    logger->setColCount(numOffield,ui->tableWidget);
    logger->setHeader(header,ui->tableWidget);

}

MainWindow::~MainWindow()
{
    delete logger;
    delete ui;
}

void MainWindow::on_Insertbtn_clicked()
{
    ui->State->setText("Inserting");

    QStringList dialoglist;
    SecDialog secdialog;


    secdialog.setModal(true);
    auto status = secdialog.exec();

    if (status == QDialog::Accepted){
        auto data = secdialog.getdata();

        dialoglist.clear();
        dialoglist<<data.data1<<data.data2<<data.data3<<data.data4;

        logger->addData(dialoglist,ui->tableWidget);

        ui->State->setText("Insert success");
    }
    else{
        qDebug() << "reject";
        ui->State->setText("Insert failed");
    }
}

void MainWindow::on_Savebtn_clicked()
{
    int saveflag = logger->saveCSV("output",ui->tableWidget);
    if (saveflag){
            ui->State->setText("Save success");
       }
    else{
            ui->State->setText("Save failed");
    }
}

void MainWindow::on_Clearbtn_clicked()
{
    logger->cleartable(ui->tableWidget);
}

