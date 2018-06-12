#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ICQ beta v0.1");
    setWindowIcon(QIcon(":/resources/icon.png"));
    ui->chatBox->setReadOnly(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_serverButton_clicked()
{
    QString ip = ui->serverIP->text();
    QString port = ui->serverPort->text();
    server * Server = new server(ip, port);
    connect(Server, SIGNAL(connection()), this, SLOT(clientConnected()));
    connect(Server, SIGNAL(message(QString)), this, SLOT(NewMessage(QString)));
    ui->chatBox->append("Your server started");
    ui->chatBox->append("");
}

void MainWindow::on_connectButton_clicked()
{
    QString ip = ui->conncectIP->text();
    QString port = ui->connectPort->text();
    client * Client = new client(ip, port);
    connect(Client, SIGNAL(ClientConnectedToServer()), this, SLOT(connected()));
    connect(this, SIGNAL(sendMessage(QString)), Client, SLOT(slSendMessage(QString)));
}

void MainWindow::on_sendButton_clicked()
{
    QString message = ui->chatLine->text();
    QString sys_message = QTime::currentTime().toString("hh:mm:ss") + " You : ";
    ui->chatBox->append(sys_message + message);
    emit sendMessage(message);
    ui->chatLine->clear();
}

void MainWindow::NewMessage(const QString &msg) {
    QSound::play(":/resources/eoy.wav");
    ui->chatBox->append(msg);
}

void MainWindow::clientConnected() {
    ui->chatBox->append("Client connected");
    ui->chatBox->append("");
}

void MainWindow::connected() {
    ui->chatBox->append("Connected to the server");
    ui->chatBox->append("");
}



