/**
 * @brief BrStormTextLexerFortran77.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERFORTRAN77_HPP
#define BRSTORMTEXTLEXERFORTRAN77_HPP


#include <Qsci/qscilexerfortran77.h>


class BrStormTextLexerFortran77 : public QsciLexerFortran77
{
    Q_OBJECT

public:

    BrStormTextLexerFortran77(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERFORTRAN77_HPP

