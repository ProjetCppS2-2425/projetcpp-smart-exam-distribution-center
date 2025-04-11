#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QSystemTrayIcon>
#include <QString>

class Notification : public QObject
{
    Q_OBJECT
public:
    explicit Notification(QSystemTrayIcon *trayIcon, QObject *parent = nullptr);

    void showExamReminder(const QString &examTitle, const QString &deliveryPerson);

private:
    QSystemTrayIcon *m_trayIcon;
};

#endif // NOTIFICATION_H
