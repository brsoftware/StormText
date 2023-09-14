/**
 * @brief BrStormTextApplication.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 27 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTAPPLICATION_HPP
#define BRSTORMTEXTAPPLICATION_HPP


#include <QApplication>
#include <QEvent>


class BrStormTextApplication : public QApplication
{
    Q_OBJECT

public:

    BrStormTextApplication(int &argc, char *argv[]);

public slots:

    void handleApplicationStateChanged(Qt::ApplicationState st);
    void setConstructed(bool c) {m_c = c;}

public:

    bool event(QEvent *event) override;

signals:

    void fileOpened(QString file);

private:

    bool m_c = false;
};

#endif // BRSTORMTEXTAPPLICATION_HPP

