/**
 * @brief BrStormTextLexerFortran.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERFORTRAN_HPP
#define BRSTORMTEXTLEXERFORTRAN_HPP


#include <Qsci/qscilexerfortran.h>


class BrStormTextLexerFortran : public QsciLexerFortran
{
    Q_OBJECT

public:

    BrStormTextLexerFortran(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERFORTRAN_HPP

