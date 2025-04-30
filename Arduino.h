#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>

class Arduino : public QObject
{
    Q_OBJECT
public:
    explicit Arduino(QObject *parent = nullptr);
    ~Arduino();

    bool connect_arduino();
    bool disconnect_arduino();
    bool isConnected() const;
    void write_to_arduino(const QByteArray &data);
    QByteArray read_from_arduino();
    QString portName() const;

private:
    QSerialPort *serial;
    static const quint16 ARDUINO_UNO_VENDOR_ID = 9025;
    static const quint16 ARDUINO_UNO_PRODUCT_ID = 67;
    QString arduino_port_name;
    bool arduino_is_available = false;
};

#endif // ARDUINO_H
