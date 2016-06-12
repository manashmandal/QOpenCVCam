#ifndef VIDEOFRAMEWIDGET_H
#define VIDEOFRAMEWIDGET_H

#include <QWidget>
#include <QImage>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

namespace Ui {
class VideoFrameWidget;
}

class VideoFrameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoFrameWidget(QWidget *parent = 0);
    ~VideoFrameWidget();

public slots:
    void getImage(QPixmap image);

signals:
    void cameraControlSignal(bool status);

private slots:
    void on_cameraButton_toggled(bool checked);

private:
    QImage qImage;
    Mat cvImage;
    Ui::VideoFrameWidget *ui;
};

#endif // VIDEOFRAMEWIDGET_H
