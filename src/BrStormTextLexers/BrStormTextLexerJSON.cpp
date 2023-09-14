/**
 * @brief BrStormTextLexerJSON.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerJSON.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerJSON::BrStormTextLexerJSON(QFont font, QColor color, QObject *parent)
    : QsciLexerJSON(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setColor(color, QsciLexerJSON::Default);
    setColor(QColor("#39FF00"), QsciLexerJSON::String);
    setColor(QColor("#06DD00"), QsciLexerJSON::UnclosedString);
    setColor(QColor("#FF00FD"), QsciLexerJSON::Property);
    setColor(color, QsciLexerJSON::EscapeSequence);
    setColor(QColor("#EA0000"), QsciLexerJSON::CommentLine);
    setColor(QColor("#EA0000"), QsciLexerJSON::CommentBlock);
    setColor(color, QsciLexerJSON::Operator);
    setColor(QColor("#FF00FD"), QsciLexerJSON::IRI);
    setColor(QColor("#FF00FD"), QsciLexerJSON::IRICompact);
    setColor(QColor("#FF6D00"), QsciLexerJSON::Keyword);
    setColor(QColor("#3900FF"), QsciLexerJSON::KeywordLD);
    setColor(QColor("#FF7777"), QsciLexerJSON::Error);

    setFont(font, QsciLexerJSON::Default);
    setFont(font, QsciLexerJSON::String);
    setFont(font, QsciLexerJSON::UnclosedString);
    setFont(font, QsciLexerJSON::Property);
    setFont(font, QsciLexerJSON::EscapeSequence);
    setFont(font, QsciLexerJSON::CommentLine);
    setFont(font, QsciLexerJSON::CommentBlock);
    setFont(font, QsciLexerJSON::Operator);
    setFont(font, QsciLexerJSON::IRI);
    setFont(font, QsciLexerJSON::IRICompact);
    setFont(font, QsciLexerJSON::Keyword);
    setFont(font, QsciLexerJSON::KeywordLD);
    setFont(font, QsciLexerJSON::Error);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?6");
    }

    api->prepare();
}
