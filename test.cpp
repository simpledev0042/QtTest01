#include "test.h"
#include "ui_test.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>

Test::Test(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    ui->textMousePosition->setText("");
    this->installEventFilter(this);
}

Test::~Test()
{
    delete ui;
}

void Test::on_actionActionOpen_triggered(){
    QString filePath = QFileDialog::getOpenFileName(this, tr("Opem Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if( QFile::exists(filePath) ) {
        this->mFilePath = filePath;
        this->displayImage();
    }
}

void Test::displayImage(){
    QPixmap img(this->mFilePath);
    ui->vLabelImage->setPixmap(img);
}

bool Test::eventFilter(QObject *obj, QEvent *event){
    if (event->type() == QEvent::HoverMove)
    {
        QMouseEvent *e = (QMouseEvent*)(event);
        ui->textMousePosition->setText(QString("Mouse Position: X=%1 Y=%2").arg(e->pos().x()).arg(e->pos().y()));
    }
    return false;
}
