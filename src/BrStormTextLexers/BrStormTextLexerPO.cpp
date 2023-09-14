/**
 * @brief BrStormTextLexerPO.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerPO.hpp"


BrStormTextLexerPO::BrStormTextLexerPO(QFont font, QColor color, QObject *parent)
    : QsciLexerPO(parent)
{    
    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerPO::Default);
    setColor(QColor("#EA0000"), QsciLexerPO::Comment);
    setColor(color, QsciLexerPO::MessageId);
    setColor(QColor("#FF6D00"), QsciLexerPO::MessageIdText);
    setColor(QColor("#39FF00"), QsciLexerPO::MessageString);
    setColor(QColor("#39FF00"), QsciLexerPO::MessageStringText);
    setColor(QColor("#FF00FD"), QsciLexerPO::MessageContext);
    setColor(QColor("#FF00FD"), QsciLexerPO::MessageContextText);
    setColor(QColor("#3900FF"), QsciLexerPO::Fuzzy);
    setColor(QColor("#EA0000"), QsciLexerPO::ProgrammerComment);
    setColor(color, QsciLexerPO::Reference);
    setColor(QColor("#FF7777"), QsciLexerPO::Flags);
    setColor(color, QsciLexerPO::MessageIdTextEOL);
    setColor(QColor("#39FF00"), QsciLexerPO::MessageStringTextEOL);
    setColor(color, QsciLexerPO::MessageContextTextEOL);

    setFont(font, QsciLexerPO::Default);
    setFont(font, QsciLexerPO::Comment);
    setFont(font, QsciLexerPO::MessageId);
    setFont(font, QsciLexerPO::MessageIdText);
    setFont(font, QsciLexerPO::MessageString);
    setFont(font, QsciLexerPO::MessageStringText);
    setFont(font, QsciLexerPO::MessageContext);
    setFont(font, QsciLexerPO::MessageContextText);
    setFont(font, QsciLexerPO::Fuzzy);
    setFont(font, QsciLexerPO::ProgrammerComment);
    setFont(font, QsciLexerPO::Reference);
    setFont(font, QsciLexerPO::Flags);
    setFont(font, QsciLexerPO::MessageIdTextEOL);
    setFont(font, QsciLexerPO::MessageStringTextEOL);
    setFont(font, QsciLexerPO::MessageContextTextEOL);

    setPaper(QsciLexer::defaultPaper());
}
