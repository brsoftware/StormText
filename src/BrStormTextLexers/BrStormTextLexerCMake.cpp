/**
 * @brief BrStormTextLexerCMake.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerCMake.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerCMake::BrStormTextLexerCMake(QColor color, QFont font, QObject *parent)
    : QsciLexerCMake(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldAtElse(true);

    setColor(color, QsciLexerCMake::Default);
    setColor(QColor("#EA0000"), QsciLexerCMake::Comment);
    setColor(QColor("#39FF00"), QsciLexerCMake::String);
    setColor(QColor("#39FF00"), QsciLexerCMake::StringLeftQuote);
    setColor(QColor("#39FF00"), QsciLexerCMake::StringRightQuote);
    setColor(QColor("#3900FF"), QsciLexerCMake::Function);
    setColor(QColor("#FF00FD"), QsciLexerCMake::Variable);
    setColor(color, QsciLexerCMake::Label);
    setColor(QColor("#FF6D00"), QsciLexerCMake::KeywordSet3);
    setColor(QColor("#FF6D00"), QsciLexerCMake::BlockWhile);
    setColor(QColor("#FF6D00"), QsciLexerCMake::BlockForeach);
    setColor(QColor("#FF6D00"), QsciLexerCMake::BlockIf);
    setColor(QColor("#FF6D00"), QsciLexerCMake::BlockMacro);
    setColor(color, QsciLexerCMake::StringVariable);

    setFont(font, QsciLexerCMake::Default);
    setFont(font, QsciLexerCMake::Comment);
    setFont(font, QsciLexerCMake::String);
    setFont(font, QsciLexerCMake::StringLeftQuote);
    setFont(font, QsciLexerCMake::StringRightQuote);
    setFont(font, QsciLexerCMake::Function);
    setFont(font, QsciLexerCMake::Variable);
    setFont(font, QsciLexerCMake::Label);
    setFont(font, QsciLexerCMake::KeywordSet3);
    setFont(font, QsciLexerCMake::BlockWhile);
    setFont(font, QsciLexerCMake::BlockForeach);
    setFont(font, QsciLexerCMake::BlockIf);
    setFont(font, QsciLexerCMake::BlockMacro);
    setFont(font, QsciLexerCMake::StringVariable);
    setFont(font, QsciLexerCMake::Number);

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
