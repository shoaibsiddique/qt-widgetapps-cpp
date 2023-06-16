#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_checkPortsButton_clicked();


    void on_comportsComboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;

        QByteArray serialData;
        QString serialBuffer;
        QString parsed_data;
        double temperature_value;

        static const quint16 ch340_vendor_id = 6790;
        static const quint16 ch340_product_id = 29987;

        static const quint16 ftdi_vendor_id = 1027;
        static const quint16 ftdi_product_id = 24577;

        static const quint16 arduino_vendorID = 2341;
        QString arduino_port_name;
        bool arduino_is_available;
};

#endif // MAINWINDOW_H
