#pragma once
#include <QString>
#include <QWidget>

class WindowsNotifier {
public:
    static void showNativeToast(const QString& title, const QString& message, QWidget* parent = nullptr);
};
