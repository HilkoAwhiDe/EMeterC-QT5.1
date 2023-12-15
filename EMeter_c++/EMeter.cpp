#include "skala.h"
#include "nedel.h"
#include "EMeter.h"
#include "QLayout"
#include "QPainter"
#include <QDial>
#include <QObject>
#include "ui_EMeter.h"
#include <QtGui>
#include "controler.h"

EMeter::EMeter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Rons Org Quality Meter");

    Skala* sk = new Skala(ui->centralwidget);
    sk->setFixedHeight(ui->Skala->height());
    sk->setFixedWidth(ui->Skala->width());
    ui->Skala->hide();
    sk->move(ui->Skala->pos());
    ui->Skala = sk;

    controler = new Controler(ui->TA, ui->TACounter
                           , ui->sense, ui->lcdSense, sk->nedel()
                    , ui->countOnOff, ui->autoManuel
                    , ui->btnSet1, ui->btnSet2
                    , ui->onOff, ui->balNedel, this);
    //sk->setVisible(TRUE);
    QObject::connect(ui->sense, SIGNAL(valueChanged(int)), ui->lcdSense, SLOT(display(int)));


    // Test Code

    QPixmap display;
    //bool loadded = display.load(":/Display.png");
    //setFixedSize(display.size());
    //QPalette palette;
    //palette.setBrush(QPalette::Window, display);
    //this->setPalette(palette);

    //Nedel* nedel = new Nedel(ui->centralwidget);
    //nedel->move(width() - nedel->width() - 18,18);



//    display = display.scaled(ui->centralwidget->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    ui->frame->setStyleSheet("QFrame{ background-image: url(:/Display.png }");
//    QPalette palette;
//    palette.setBrush(QPalette::Window, display);
//    ui->centralwidget->setPalette(palette);
//    ui->skala->setStyleSheet(
//               "background-image:url(\":/Display.png\"); background-position: center;" );
}

EMeter::~EMeter()
{
    delete controler;
    delete ui;
}

