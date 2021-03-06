#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <secdialog.h>
#include <logger.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Logger* logger;

private slots:
    void on_Insertbtn_clicked();
    void on_Savebtn_clicked();


    void on_Clearbtn_clicked();

private:
    Ui::MainWindow *ui;
    SecDialog *secdialog;
};
#endif // MAINWINDOW_H
