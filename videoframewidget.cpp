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

void VideoFrameWidget::showImage(const cv::Mat &image){

    switch(image.type()){
    case CV_8UC1:
        cv::cvtColor(image, cvImage, CV_GRAY2RGB);
        break;
    case CV_8UC3:
        cv::cvtColor(image, cvImage, CV_BGR2RGB);
        break;
    }

    assert(cvImage.isContinuous());

    qImage = QImage(cvImage.data, cvImage.cols, cvImage.rows, cvImage.cols * 3, QImage::Format_RGB888);

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
