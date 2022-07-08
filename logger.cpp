#include "logger.h"

Logger::Logger(QObject *parent) : QObject(parent)
{

}

Logger::~Logger(){

}

void Logger::setColCount(int size,QTableWidget *datatable){
    datatable->setColumnCount(size);
}

void Logger::setHeader(QStringList Datalist,QTableWidget *datatable){
    datatable->setHorizontalHeaderLabels(Datalist);
}

void Logger::addData(QStringList Datalist,QTableWidget *datatable){
    int row_count = datatable -> rowCount();
    datatable ->insertRow(row_count);

    QTableWidgetItem* item;

    for (int i = 0; i < Datalist.size(); i++){
        item = new QTableWidgetItem();
        item->setText(Datalist[i]);
        datatable->setItem(row_count,i,item);
    }

}

void Logger::cleartable(QTableWidget *datatable){
    for (int  i = datatable->rowCount()-1 ; i >= 0 ;i--){
        datatable->removeRow(i);
    }

}

int Logger::saveCSV(QString filename,QTableWidget *datatable){
    QFile f("./"+filename+".csv");
    if (f.open(QFile::WriteOnly | QFile::Truncate)){
         QTextStream data( &f );
         QStringList strList;

         int row_count = datatable->rowCount();
         int col_count = datatable->columnCount();

         for( int c = 0; c < col_count ; ++c )
         {
             strList<< datatable->horizontalHeaderItem(c)->data(Qt::DisplayRole).toString();
         }

         data << strList.join(",") << "\n";

         for( int r = 0; r < row_count; ++r )
         {
             strList.clear();
             for( int c = 0; c < col_count; ++c )
             {
                 strList << datatable->item( r, c )->text();
             }
             data << strList.join( "," )+"\n";
         }
    }
    else{
        qDebug()<<"Save failed";
        return 0;
    }
    f.close();
    return 1;
}
