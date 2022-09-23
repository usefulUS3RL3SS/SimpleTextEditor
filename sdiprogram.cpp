#include "sdiprogram.h"
#include "qapplication.h"
#include "ui_sdiprogram.h"
#include "docwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>

SDIprogram::SDIprogram(QWidget *parent) : QMainWindow(parent)
{
    QMenu *pmnuFile = new QMenu("&File");
    QMenu *pmnuHelp = new QMenu("&Help");

    DocWindow* pdoc = new DocWindow;

    pmnuFile->addAction("&Open...",
                       pdoc,
                       SLOT(slotLoad()),
                       QKeySequence("CTRL+O")
                       );
    pmnuFile->addAction("&Save",
                       pdoc,
                       SLOT(slotSave()),
                       QKeySequence("CTRL+S")
                       );
    pmnuFile->addAction("&Save As...",
                       pdoc,
                       SLOT(slotSaveAs()),
                       QKeySequence("CTRL+Shift+S")
                       );
    pmnuFile->addSeparator();
    pmnuFile->addAction("&Quit",
                       qApp,
                       SLOT(quit()),
                       QKeySequence("CTRL+Q")
                       );
    pmnuHelp->addAction("&Help",
                        this,
                        SLOT(slotAbout()),
                        QKeySequence(Qt::Key_F1)
                        );

    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);

    setCentralWidget(pdoc);

    connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));

    statusBar()->showMessage("Ready",2000);
}

void SDIprogram::slotAbout(){
    QMessageBox::about(this, "About", "This program is simple text redactor");
}

void SDIprogram::slotChangeWindowTitle(const QString& str){
    setWindowTitle(str);
}


SDIprogram::~SDIprogram()
{
}

