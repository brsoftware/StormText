/**
 * @brief BrStormTextLexerSpice.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERSPICE_HPP
#define BRSTORMTEXTLEXERSPICE_HPP


#include <Qsci/qscilexerspice.h>


class BrStormTextLexerSpice : public QsciLexerSpice
{
    Q_OBJECT

public:

    BrStormTextLexerSpice(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERSPICE_HPP

