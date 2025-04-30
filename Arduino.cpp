#include "Arduino.h"
#include <QDebug>

Arduino::Arduino(QObject *parent) : QObject(parent),
    serial(new QSerialPort(this)),
    arduino_is_available(false)
{
}

Arduino::~Arduino()
{
    disconnect_arduino();
}

bool Arduino::connect_arduino()
{
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if(info.vendorIdentifier() == ARDUINO_UNO_VENDOR_ID &&
            info.productIdentifier() == ARDUINO_UNO_PRODUCT_ID) {
            arduino_port_name = info.portName();
            arduino_is_available = true;
            break;
        }
    }

    if(!arduino_is_available) {
        qWarning() << "Arduino not found";
        return false;
    }

    serial->setPortName(arduino_port_name);
    if(!serial->open(QIODevice::ReadWrite)) {
        qWarning() << "Failed to open port" << arduino_port_name << ":" << serial->errorString();
        return false;
    }

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    return true;
}

bool Arduino::disconnect_arduino()
{
    if(serial->isOpen()) {
        serial->close();
        arduino_is_available = false;
        return true;
    }
    return false;
}

bool Arduino::isConnected() const
{
    return serial->isOpen();
}

void Arduino::write_to_arduino(const QByteArray &data)
{
    if(serial->isOpen() && serial->isWritable()) {
        serial->write(data);
        if(!serial->waitForBytesWritten(1000)) {
            qWarning() << "Write operation timed out";
        }
    }
}

QByteArray Arduino::read_from_arduino()
{
    if(serial->isOpen() && serial->isReadable()) {
        if(serial->waitForReadyRead(1000)) {
            return serial->readAll();
        }
        qWarning() << "Read operation timed out";
    }
    return QByteArray();
}

QString Arduino::portName() const
{
    return arduino_port_name;
}
