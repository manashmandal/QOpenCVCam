#include "camerathread.h"

#include <QImage>
#include <QDebug>
#include <QPixmap>

void CameraThread::run(){
    sleep(.1);
    while (camera.isOpened() && startCamera){
        Mat frame;
        camera >> frame;
        cv::flip(frame, frame, 1);
        convertImg(frame);
        sleep(0.1);
    }
}

void CameraThread::cameraControlListener(bool input){
    if (input) this->start();
    else this->terminate();
}

void CameraThread::convertImg(Mat &image){

    qDebug() << "sending image";

    QImage qImage;
    cv::Mat cvImage;

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

    QPixmap pixmap;
    pixmap.scaled(qImage.size());
    pixmap = QPixmap::fromImage(qImage);
    emit sendImage(pixmap);
}


