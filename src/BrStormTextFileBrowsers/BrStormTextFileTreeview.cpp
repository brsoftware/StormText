/**
 * @brief BrStormTextFileTreeview.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 10 Sep 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextFileTreeview.hpp"

#include <QFileSystemModel>
#include <QHeaderView>
#include <QLineEdit>
#include <QMenu>


BrStormTextFileTreeview::BrStormTextFileTreeview(QWidget *parent)
    : QTreeView(parent)
{
    setAcceptDrops(false);
    setContextMenuPolicy(Qt::CustomContextMenu);

    header()->setStretchLastSection(false);
    header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    //connect(this, &QTreeView::collapsed,
    //        this, [=](){resizeColumnToContents(0);});
}
