/**
 * @brief BrStormTextLexerOctave.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerOctave.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerOctave::BrStormTextLexerOctave(QFont font, QColor color, QObject *parent)
    : QsciLexerOctave(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setColor(color, QsciLexerMatlab::Default);
    setColor(QColor("#EA0000"), QsciLexerMatlab::Comment);
    setColor(QColor("#3900FF"), QsciLexerMatlab::Command);
    setColor(QColor("#FF6D00"), QsciLexerMatlab::Keyword);
    setColor(QColor("#39FF00"), QsciLexerMatlab::SingleQuotedString);
    setColor(color, QsciLexerMatlab::Operator);
    setColor(color, QsciLexerMatlab::Identifier);
    setColor(QColor("#39FF00"), QsciLexerMatlab::DoubleQuotedString);

    setFont(font, QsciLexerMatlab::Default);
    setFont(font, QsciLexerMatlab::Comment);
    setFont(font, QsciLexerMatlab::Command);
    setFont(font, QsciLexerMatlab::Keyword);
    setFont(font, QsciLexerMatlab::SingleQuotedString);
    setFont(font, QsciLexerMatlab::Operator);
    setFont(font, QsciLexerMatlab::Identifier);
    setFont(font, QsciLexerMatlab::DoubleQuotedString);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
