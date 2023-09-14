/**
 * @brief BrStormTextTabBar.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 28 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextTabBar.hpp"


BrStormTextTabBar::BrStormTextTabBar(QWidget *parent)
    : QTabBar(parent)
{
    setAcceptDrops(true);
    setElideMode(Qt::ElideRight);
    setTabsClosable(true);
    setDocumentMode(true);
    setUsesScrollButtons(true);
}
