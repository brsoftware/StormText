/**
 * @brief BrStormTextLexerAVS.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 28 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERAVS_HPP
#define BRSTORMTEXTLEXERAVS_HPP


#include <Qsci/qscilexeravs.h>


class BrStormTextLexerAVS : public QsciLexerAVS
{
    Q_OBJECT

public:

    BrStormTextLexerAVS(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERAVS_HPP


