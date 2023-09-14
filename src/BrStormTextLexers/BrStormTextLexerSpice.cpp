/**
 * @brief BrStormTextLexerSpice.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerSpice.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerSpice::BrStormTextLexerSpice(QFont font, QColor color, QObject *parent)
    : QsciLexerSpice(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setColor(color, QsciLexerSpice::Default);
    setColor(color, QsciLexerSpice::Identifier);
    setColor(QColor("#FF6D00"), QsciLexerSpice::Command);
    setColor(QColor("#FF00FD"), QsciLexerSpice::Function);
    setColor(QColor("#3900FF"), QsciLexerSpice::Parameter);
    setColor(QColor("#39FF00"), QsciLexerSpice::Delimiter);
    setColor(QColor("#39FF00"), QsciLexerSpice::Value);
    setColor(QColor("#EA0000"), QsciLexerSpice::Comment);

    setFont(font, QsciLexerSpice::Default);
    setFont(font, QsciLexerSpice::Identifier);
    setFont(font, QsciLexerSpice::Command);
    setFont(font, QsciLexerSpice::Function);
    setFont(font, QsciLexerSpice::Parameter);
    setFont(font, QsciLexerSpice::Delimiter);
    setFont(font, QsciLexerSpice::Value);
    setFont(font, QsciLexerSpice::Comment);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?3");
    }

    api->prepare();
}
