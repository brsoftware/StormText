/**
 * @brief BrStormTextLexerPerl.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPERL_HPP
#define BRSTORMTEXTLEXERPERL_HPP


#include <Qsci/qscilexerperl.h>


class BrStormTextLexerPerl : public QsciLexerPerl
{
    Q_OBJECT

public:

    BrStormTextLexerPerl(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERPERL_HPP

