#include "videoframewidget.h"
#include "ui_videoframewidget.h"

VideoFrameWidget::VideoFrameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoFrameWidget)
{
    ui->setupUi(this);
    ui->cameraButton->setChecked(true);
}

VideoFrameWidget::~VideoFrameWidget()
{
    delete ui;
}

void VideoFrameWidget::getImage(QPixmap image){
    ui->videoFrame->setMaximumSize(image.width(), image.height());
    ui->videoFrame->setGeometry(0, 0, image.width(), image.height());
    ui->videoFrame->setPixmap(image);
}


void VideoFrameWidget::on_cameraButton_toggled(bool checked)
{
    emit cameraControlSignal(checked);
    if (checked){
        ui->cameraButton->setText("Camera Turn OFF");
    } else {
        ui->cameraButton->setText("Camera Turn ON");
    }
}
