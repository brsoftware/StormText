/**
 * @brief BrStormTextLexerLua.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerLua.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerLua::BrStormTextLexerLua(QFont font, QColor color, QObject *parent)
    : QsciLexerLua(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldCompact(true);

    setColor(color, QsciLexerLua::Default);
    setColor(QColor("#EA0000"), QsciLexerLua::Comment);
    setColor(QColor("#EA0000"), QsciLexerLua::LineComment);
    setColor(QColor("#FF6D00"), QsciLexerLua::Keyword);
    setColor(QColor("#39FF00"), QsciLexerLua::String);
    setColor(QColor("#39FF00"), QsciLexerLua::Character);
    setColor(QColor("#39FF00"), QsciLexerLua::LiteralString);
    setColor(QColor("#FF00FD"), QsciLexerLua::Preprocessor);
    setColor(color, QsciLexerLua::Operator);
    setColor(color, QsciLexerLua::Identifier);
    setColor(QColor("#06DD00"), QsciLexerLua::UnclosedString);
    setColor(QColor("#3900FF"), QsciLexerLua::BasicFunctions);
    setColor(QColor("#3900FF"), QsciLexerLua::StringTableMathsFunctions);
    setColor(QColor("#3900FF"), QsciLexerLua::CoroutinesIOSystemFacilities);
    setColor(QColor("#FF6D00"), QsciLexerLua::KeywordSet5);
    setColor(QColor("#FF6D00"), QsciLexerLua::KeywordSet6);
    setColor(QColor("#FF6D00"), QsciLexerLua::KeywordSet7);
    setColor(QColor("#FF6D00"), QsciLexerLua::KeywordSet8);
    setColor(color, QsciLexerLua::Label);

    setFont(font, QsciLexerLua::Default);
    setFont(font, QsciLexerLua::Comment);
    setFont(font, QsciLexerLua::LineComment);
    setFont(font, QsciLexerLua::Keyword);
    setFont(font, QsciLexerLua::String);
    setFont(font, QsciLexerLua::Character);
    setFont(font, QsciLexerLua::LiteralString);
    setFont(font, QsciLexerLua::Preprocessor);
    setFont(font, QsciLexerLua::Operator);
    setFont(font, QsciLexerLua::Identifier);
    setFont(font, QsciLexerLua::UnclosedString);
    setFont(font, QsciLexerLua::BasicFunctions);
    setFont(font, QsciLexerLua::StringTableMathsFunctions);
    setFont(font, QsciLexerLua::CoroutinesIOSystemFacilities);
    setFont(font, QsciLexerLua::KeywordSet5);
    setFont(font, QsciLexerLua::KeywordSet6);
    setFont(font, QsciLexerLua::KeywordSet7);
    setFont(font, QsciLexerLua::KeywordSet8);
    setFont(font, QsciLexerLua::Label);

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

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(4)).split(" "))
    {
        api->add(str + "?3");
    }
}
