#ifndef LOGGER_H
#define LOGGER_H
#include<QObject>
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QTableWidget>


class Logger : public QObject
{
    Q_OBJECT
public:
    //inherit from QObject, has SIGNAL & SLOT method
    explicit Logger(QObject *parent = nullptr);
    ~Logger();

    void setColCount(int,QTableWidget *);
    void setHeader(QStringList,QTableWidget *);
    void addData(QStringList,QTableWidget *);
    void cleartable(QTableWidget *);
    int saveCSV(QString,QTableWidget *);
};

#endif // LOGGER_H
