/**
 * @brief BrStormTextLexerEDIFACT.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 9 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXEREDIFACT_HPP
#define BRSTORMTEXTLEXEREDIFACT_HPP


#include <Qsci/qscilexeredifact.h>


class BrStormTextLexerEDIFACT : public QsciLexerEDIFACT
{
    Q_OBJECT

public:

    BrStormTextLexerEDIFACT(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXEREDIFACT_HPP

