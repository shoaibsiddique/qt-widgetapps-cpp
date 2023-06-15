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
};

#endif // MAINWINDOW_H
