#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <ctime>
#include "timecontrol.h"

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
    void on_pushButton_clicked();
    void decrementTimer();
    void updateTime();

private:
    TimeControl *timeControl;
    time_t time;
    Ui::MainWindow *ui;
    QTimer *actualTime;
    QSystemTrayIcon *trIcon;

    TimeMode mode;

};

#endif // MAINWINDOW_H
