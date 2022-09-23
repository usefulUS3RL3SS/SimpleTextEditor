#include "sdiprogram.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QElapsedTimer>

void LoadModules(QSplashScreen* psplash){
    QElapsedTimer time;
    time.start();
    for(int i=0; i<100 ; ){
        if(time.elapsed() > 40){
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: " + QString::number(i)+"%", Qt::AlignCenter | Qt::AlignBottom, Qt::black);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap picture("/unknown.png");
    QSplashScreen splash(picture);
    SDIprogram w;

    splash.show();
    LoadModules(&splash);
    splash.finish(&w);
    w.show();

    return a.exec();

}
