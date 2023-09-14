/**
 * @brief BrStormTextLexerRuby.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERRUBY_HPP
#define BRSTORMTEXTLEXERRUBY_HPP


#include <Qsci/qscilexerruby.h>


class BrStormTextLexerRuby : public QsciLexerRuby
{
    Q_OBJECT

public:

    BrStormTextLexerRuby(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERRUBY_HPP

