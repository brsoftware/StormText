/**
 * @brief BrStormTextLexerProperties.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPROPERTIES_HPP
#define BRSTORMTEXTLEXERPROPERTIES_HPP


#include <Qsci/qscilexerproperties.h>


class BrStormTextLexerProperties : public QsciLexerProperties
{
    Q_OBJECT

public:

    BrStormTextLexerProperties(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERPROPERTIES_HPP

