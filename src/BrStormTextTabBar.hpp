/**
 * @brief BrStormTextTabBar.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 28 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTTABBAR_HPP
#define BRSTORMTEXTTABBAR_HPP


#include <QTabBar>


class BrStormTextTabBar : public QTabBar
{
    Q_OBJECT

public:

    BrStormTextTabBar(QWidget *parent = nullptr);
};

#endif // BRSTORMTEXTTABBAR_HPP

