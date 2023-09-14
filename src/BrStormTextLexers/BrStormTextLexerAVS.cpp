/**
 * @brief BrStormTextLexerAVS.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 28 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerAVS.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerAVS::BrStormTextLexerAVS(QFont font,
                                         QColor color,
                                         QObject *parent)
    : QsciLexerAVS(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerAVS::Default);
    setColor(QColor("#EA0000"), QsciLexerAVS::BlockComment);
    setColor(QColor("#EA0000"), QsciLexerAVS::NestedBlockComment);
    setColor(QColor("#EA0000"), QsciLexerAVS::LineComment);
    setColor(color, QsciLexerAVS::Operator);
    setColor(QColor("#3900FF"), QsciLexerAVS::Identifier);
    setColor(QColor("#39FF00"), QsciLexerAVS::String);
    setColor(QColor("#39FF00"), QsciLexerAVS::TripleString);
    setColor(QColor("#FF6D00"), QsciLexerAVS::Keyword);
    setColor(QColor("#FF6D00"), QsciLexerAVS::Filter);
    setColor(QColor("#FF6D00"), QsciLexerAVS::Plugin);
    setColor(QColor("#3900FF"), QsciLexerAVS::Function);
    setColor(QColor("#FF6D00"), QsciLexerAVS::ClipProperty);
    setColor(QColor("#FF6D00"), QsciLexerAVS::KeywordSet6);

    setFont(font, QsciLexerAVS::Default);
    setFont(font, QsciLexerAVS::BlockComment);
    setFont(font, QsciLexerAVS::NestedBlockComment);
    setFont(font, QsciLexerAVS::LineComment);
    setFont(font, QsciLexerAVS::Number);
    setFont(font, QsciLexerAVS::Operator);
    setFont(font, QsciLexerAVS::Identifier);
    setFont(font, QsciLexerAVS::String);
    setFont(font, QsciLexerAVS::TripleString);
    setFont(font, QsciLexerAVS::Keyword);
    setFont(font, QsciLexerAVS::Filter);
    setFont(font, QsciLexerAVS::Plugin);
    setFont(font, QsciLexerAVS::Function);
    setFont(font, QsciLexerAVS::ClipProperty);
    setFont(font, QsciLexerAVS::KeywordSet6);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?2");
    }

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?5");
    }

    for (const QString &str : QString(keywords(4)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(5)).split(" "))
    {
        api->add(str + "?1");
    }

    api->prepare();
}

