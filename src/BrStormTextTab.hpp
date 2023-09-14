/**
 * @brief BrStormTextTab.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 28 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTTAB_HPP
#define BRSTORMTEXTTAB_HPP


#include <QTabWidget>
#include "BrStormTextEditor.hpp"


class BrStormTextTab : public QTabWidget
{
    Q_OBJECT

public:

    BrStormTextTab(QWidget *parent = nullptr);

public:

    BrStormTextEditor *currentTab();
};

#endif // BRSTORMTEXTTAB_HPP

