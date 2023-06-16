#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include<QWidget>
#include <QDebug>

#include <QByteArray>
#include <QBitArray>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Detect Arduino COM Port");
    this->setFixedSize(420,200);
    arduino_is_available = false;
    arduino_port_name = "";


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){



        if(serialPortInfo.hasVendorIdentifier() ){
            if(serialPortInfo.vendorIdentifier() == ch340_vendor_id || serialPortInfo.vendorIdentifier() == ftdi_vendor_id ||
                  serialPortInfo.vendorIdentifier() == arduino_vendorID  ){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                    ui->comInfoText->append("Arduino Available on: " + arduino_port_name);
                    qDebug() << "Arduino Available on: " + arduino_port_name;


            }
        }
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comportsComboBox_currentIndexChanged(const QString &arg1)
{
    QString currentSerial;
    currentSerial = ui->comportsComboBox->currentText();
    QSerialPortInfo selectedSerial(currentSerial);
    ui->comInfoText->clear();
//    if(selectedSerial.hasVendorIdentifier() && selectedSerial.hasProductIdentifier()){
//        if(selectedSerial.vendorIdentifier() == ch340_vendor_id || selectedSerial.vendorIdentifier() == ftdi_vendor_id){
//            if(selectedSerial.productIdentifier() == ch340_product_id || selectedSerial.productIdentifier() == ftdi_product_id){
//                arduino_port_name = selectedSerial.portName();
//                arduino_is_available = true;
//            }
//        }
//    }
    if(selectedSerial.hasVendorIdentifier() ){
        if(selectedSerial.vendorIdentifier() == ch340_vendor_id || selectedSerial.vendorIdentifier() == ftdi_vendor_id ||
              selectedSerial.vendorIdentifier() == arduino_vendorID  ){
                arduino_port_name = selectedSerial.portName();
                arduino_is_available = true;

        }
    }
    ui->comInfoText->append("Port Name:" +  selectedSerial.portName());
    ui->comInfoText->append("Location:" +  selectedSerial.systemLocation());
    ui->comInfoText->append("Description:" +  selectedSerial.description());
    ui->comInfoText->append("Manufacturer:" +  selectedSerial.manufacturer());
    ui->comInfoText->append("Vendor ID:" +  QString::number(selectedSerial.vendorIdentifier()));
    ui->comInfoText->append("Product ID:" +  QString::number(selectedSerial.productIdentifier()));
    ui->comInfoText->append("Busy Status" + QString::number(selectedSerial.isBusy()));
    if(arduino_is_available){
        arduino_is_available = false;
        ui->comInfoText->append("Arduino Available on: " + selectedSerial.portName());

    }
}

void MainWindow::on_checkPortsButton_clicked()
{
    ui->comportsComboBox->clear();

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
         {
              ui->comportsComboBox->addItem(info.portName());
  }
}


