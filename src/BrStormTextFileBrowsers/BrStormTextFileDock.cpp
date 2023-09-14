/**
 * @brief BrStormTextFileDock.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 10 Sep 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextFileDock.hpp"


BrStormTextFileDock::BrStormTextFileDock(QWidget *parent)
    : QDockWidget(parent)
{
    setWindowTitle(tr("File &Browser"));
    setHidden(true);
}
