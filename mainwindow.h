#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
#include "client.h"
#include "server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    server * Server;
    client * Client;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void NewMessage(const QString& msg);

    void connected();

    void clientConnected();
private slots:
    void on_serverButton_clicked();

    void on_connectButton_clicked();

    void on_sendButton_clicked();
signals:
    void sendMessage(const QString& msg);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
