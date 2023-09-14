/**
 * @brief BrStormTextFileModel.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date 10 Sep 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTFILEMODEL_HPP
#define BRSTORMTEXTFILEMODEL_HPP


#include <QFileSystemModel>


class BrStormTextFileModel : public QFileSystemModel
{

    friend class BrStormTextMainWindow;
    Q_OBJECT

public:

    BrStormTextFileModel();
};

#endif // BRSTORMTEXTFILEMODEL_HPP

