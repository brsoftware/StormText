/**
 * @brief BrStormTextLexerPostScript.hpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#ifndef BRSTORMTEXTLEXERPOSTSCRIPT_HPP
#define BRSTORMTEXTLEXERPOSTSCRIPT_HPP


#include <Qsci/qscilexerpostscript.h>


class BrStormTextLexerPostScript : public QsciLexerPostScript
{
    Q_OBJECT

public:

    BrStormTextLexerPostScript(QFont font, QColor color, QObject *parent = nullptr);
};

#endif // BRSTORMTEXTLEXERPOSTSCRIPT_HPP

