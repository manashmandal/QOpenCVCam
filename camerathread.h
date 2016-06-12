#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QPixmap>

using namespace cv;

class CameraThread : public QThread
{
    Q_OBJECT
public:
    CameraThread():camera(0), startCamera(true){}
    void run();
    void convertImg(Mat &image);
public slots:
    void cameraControlListener(bool input);
signals:
    void sendImage(QPixmap img);
private:
    VideoCapture camera;
    bool startCamera;

};

#endif // CAMERATHREAD_H
