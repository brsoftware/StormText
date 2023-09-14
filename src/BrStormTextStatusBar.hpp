/**
 * @brief BrStormTextStatusBar.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date Jul 1 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTSTATUSBAR_HPP
#define BRSTORMTEXTSTATUSBAR_HPP


#include <QStatusBar>


class BrStormTextStatusBar : public QStatusBar
{
    Q_OBJECT

public:

    BrStormTextStatusBar(QWidget *parent = nullptr);
};

#endif // BRSTORMTEXTSTATUSBAR_HPP

