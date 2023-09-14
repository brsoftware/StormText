/**
 * @brief BrStormTextLexerTeX.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERTEX_HPP
#define BRSTORMTEXTLEXERTEX_HPP


#include <Qsci/qscilexertex.h>


class BrStormTextLexerTeX : public QsciLexerTeX
{
    Q_OBJECT

public:

    BrStormTextLexerTeX(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERTEX_HPP

