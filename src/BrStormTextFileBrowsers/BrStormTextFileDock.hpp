/**
 * @brief BrStormTextFileDock.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 10 Sep 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTFILEDOCK_HPP
#define BRSTORMTEXTFILEDOCK_HPP


#include <QDockWidget>


class BrStormTextFileDock : public QDockWidget
{

    friend class BrStormTextMainWindow;
    Q_OBJECT

public:

    BrStormTextFileDock(QWidget *parent = nullptr);
};

#endif // BRSTORMTEXTFILEDOCK_HPP

