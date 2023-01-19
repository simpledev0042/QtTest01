#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QEvent>

namespace Ui {
    class Test;
}

class Test : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = 0);
    QString mFilePath;
    void displayImage();
    ~Test();
public slots:
    void on_actionActionOpen_triggered();
private:
    Ui::Test *ui;
public:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // TEST_H
