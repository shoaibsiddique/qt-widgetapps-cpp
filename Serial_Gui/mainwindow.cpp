#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QtDebug>
#include<QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Available COM Ports Information");
    this->setFixedSize(420,200);

//   foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
//        {
//             ui->comportsComboBox->addItem(info.portName());
// }
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
    ui->comInfoText->append("Port Name:" +  selectedSerial.portName());
    ui->comInfoText->append("Location:" +  selectedSerial.systemLocation());
    ui->comInfoText->append("Description:" +  selectedSerial.description());
    ui->comInfoText->append("Manufacturer:" +  selectedSerial.manufacturer());
    ui->comInfoText->append("Vendor ID:" +  selectedSerial.vendorIdentifier());
    ui->comInfoText->append("Product ID:" +  selectedSerial.productIdentifier());
    ui->comInfoText->append("Busy Status" + QString::number(selectedSerial.isBusy()));

}

void MainWindow::on_checkPortsButton_clicked()
{
    ui->comportsComboBox->clear();

    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
         {
              ui->comportsComboBox->addItem(info.portName());
  }
}


