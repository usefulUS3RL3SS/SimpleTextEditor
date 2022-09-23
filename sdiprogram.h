#ifndef SDIPROGRAM_H
#define SDIPROGRAM_H

#include <QMainWindow>
#include <QMessageBox>
#include "docwindow.h"

class SDIprogram : public QMainWindow
{
    Q_OBJECT

public:
    SDIprogram(QWidget *parent = nullptr);
    ~SDIprogram();


public slots:
    void slotAbout();
    void slotChangeWindowTitle(const QString&);
};

#endif // SDIPROGRAM_H
