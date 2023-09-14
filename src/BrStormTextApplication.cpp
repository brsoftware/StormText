/**
 * @brief BrStormTextApplication.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 27 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextApplication.hpp"
#include "BrStormTextMainWindow.hpp"

#include <QFile>
#include <QFileOpenEvent>
#include <QDebug>

#include <vector>
#include <string>


BrStormTextApplication::BrStormTextApplication(int &argc, char *argv[])
    : QApplication(argc, argv)
{
    setApplicationDisplayName(tr("StormText"));
    setApplicationName("BrStormText");
    setApplicationVersion(tr("1.0.0"));
    // setQuitOnLastWindowClosed(false);
    setObjectName("BrStormTextApplication");

    // connect(this, &QApplication::applicationStateChanged,
    //         this, &BrStormTextApplication::handleApplicationStateChanged);
}

void BrStormTextApplication::handleApplicationStateChanged(Qt::ApplicationState st)
{
    bool isAllNotVisible = true;

    for (const auto *w : topLevelWidgets())
    {
        if (w->isVisible()) {isAllNotVisible = false; break;}
    }

    if (st == Qt::ApplicationActive
        && isAllNotVisible)
    {
        try
        {
            BrStormTextMainWindow mw({}, this);
            mw.showMaximized();
        }

        catch (std::exception &e)
        {
            Q_UNUSED(e)
        }
    }
}

bool BrStormTextApplication::event(QEvent *event)
{
    if (event->type() == QEvent::FileOpen && m_c)
    {
        QFileOpenEvent *e = static_cast<QFileOpenEvent*>(event);
        emit fileOpened(e->file());
    }

    return QApplication::event(event);
}
