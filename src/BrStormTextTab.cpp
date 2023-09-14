/**
 * @brief BrStormTextTab.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 28 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextTab.hpp"
#include "BrStormTextTabBar.hpp"
#include <QDebug>


BrStormTextTab::BrStormTextTab(QWidget *parent)
    : QTabWidget(parent)
{
    BrStormTextTabBar *tabbar;
    tabbar = new BrStormTextTabBar(this);
    setTabBar(tabbar);
}

BrStormTextEditor *BrStormTextTab::currentTab()
{
    return qobject_cast<BrStormTextEditor*> (currentWidget());
}
