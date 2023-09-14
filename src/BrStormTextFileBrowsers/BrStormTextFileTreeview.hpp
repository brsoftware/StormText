/**
 * @brief BrStormTextFileTreeview.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 10 Sep 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTFILETREEVIEW_HPP
#define BRSTORMTEXTFILETREEVIEW_HPP


#include <QTreeView>


class BrStormTextFileTreeview : public QTreeView
{

    friend class BrStormTextMainWindow;
    Q_OBJECT

public:

    BrStormTextFileTreeview(QWidget *parent = nullptr);
};

#endif // BRSTORMTEXTFILETREEVIEW_HPP

