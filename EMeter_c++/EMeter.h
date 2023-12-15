#ifndef EMETER_H
#define EMETER_H

#include <QMainWindow>
#include <QCloseEvent>
class Controler;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class EMeter : public QMainWindow
{
    Q_OBJECT

public:
    EMeter(QWidget *parent = nullptr);
    virtual ~EMeter();
protected:

private slots:

private:
    Ui::MainWindow *ui;
    Controler * controler = NULL;
};
#endif // EMETER_H
