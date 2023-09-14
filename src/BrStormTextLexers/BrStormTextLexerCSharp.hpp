/**
 * @brief BrStormTextLexerCSharp.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERCSHARP_HPP
#define BRSTORMTEXTLEXERCSHARP_HPP


#include <Qsci/qscilexercsharp.h>


class BrStormTextLexerCSharp : public QsciLexerCSharp
{
    Q_OBJECT

public:

    BrStormTextLexerCSharp(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERCSHARP_HPP

