/**
 * @brief BrStormTextLexerProperties.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerProperties.hpp"


BrStormTextLexerProperties::BrStormTextLexerProperties(QFont font, QColor color, QObject *parent)
    : QsciLexerProperties(parent)
{    
    setFoldCompact(true);

    setColor(color, QsciLexerProperties::Default);
    setColor(QColor("#EA0000"), QsciLexerProperties::Comment);
    setColor(color, QsciLexerProperties::Section);
    setColor(color, QsciLexerProperties::Assignment);
    setColor(QColor("#FF00FD"), QsciLexerProperties::DefaultValue);
    setColor(QColor("#FF6D00"), QsciLexerProperties::Key);

    setFont(font, QsciLexerProperties::Default);
    setFont(font, QsciLexerProperties::Comment);
    setFont(font, QsciLexerProperties::Section);
    setFont(font, QsciLexerProperties::Assignment);
    setFont(font, QsciLexerProperties::DefaultValue);
    setFont(font, QsciLexerProperties::Key);

    setPaper(QsciLexer::defaultPaper());
}
