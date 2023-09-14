/**
 * @brief BrStormTextLexerPascal.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPASCAL_HPP
#define BRSTORMTEXTLEXERPASCAL_HPP


#include <Qsci/qscilexerpascal.h>


class BrStormTextLexerPascal : public QsciLexerPascal
{
    Q_OBJECT

public:

    BrStormTextLexerPascal(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERPASCAL_HPP

