#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    actualTime  = new QTimer(this);
    connect(actualTime, SIGNAL(timeout()), this, SLOT(decrementTimer()));

    timeControl = new TimeControl(25*60, 5*60);
    mode = tmLoss;
    time = timeControl->getWorkTime();
    trIcon = new QSystemTrayIcon();
    trIcon->setIcon(QIcon("icon.png"));
    trIcon->show();
    updateTime();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete actualTime;
    delete timeControl;
}

void MainWindow::on_pushButton_clicked()
{
    switch(mode) {
    case tmWork:
        actualTime->stop();
        break;
    case tmLoss:
        actualTime->start(1000);
        mode = tmWork;
        ui->progressBar->setMaximum(timeControl->getWorkTime());
        ui->pushButton->setText("Stop");
        break;
    }
    updateTime();

}

void MainWindow::decrementTimer() {
    time--;
    if (time == 0) {
        actualTime->stop();
    }
    updateTime();
}


void MainWindow::updateTime() {
    int value = timeControl->getWorkTime() - time;

    QString str  = QString("%1:%2").
            arg(time/60, 2, 10, QChar('0')).
            arg(time%60, 2, 10, QChar('0'));
    ui->lTimer->setText(str);
    ui->progressBar->setValue(value);
}
