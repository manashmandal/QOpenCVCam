#include <QApplication>
#include "videoframewidget.h"
#include "camerathread.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    VideoFrameWidget videoFrame;
    CameraThread cameraThread;

    QObject::connect(&cameraThread, SIGNAL(sendImage(QPixmap)), &videoFrame, SLOT(getImage(QPixmap)));

    QObject::connect(&videoFrame, SIGNAL(cameraControlSignal(bool)), &cameraThread, SLOT(cameraControlListener(bool)));

    cameraThread.start();
    videoFrame.show();
    return app.exec();
}
