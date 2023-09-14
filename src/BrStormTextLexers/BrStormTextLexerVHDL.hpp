/**
 * @brief BrStormTextLexerVHDL.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERVHDL_HPP
#define BRSTORMTEXTLEXERVHDL_HPP


#include <Qsci/qscilexervhdl.h>


class BrStormTextLexerVHDL : public QsciLexerVHDL
{
    Q_OBJECT

public:

    BrStormTextLexerVHDL(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERVHDL_HPP

