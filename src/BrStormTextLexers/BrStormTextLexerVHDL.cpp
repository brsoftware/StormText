/**
 * @brief BrStormVHDLtLexerVHDL.cpp: A file of the StormVHDLt project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerVHDL.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerVHDL::BrStormTextLexerVHDL(QFont font, QColor color, QObject *parent)
    : QsciLexerVHDL(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldAtBegin(true);
    setFoldAtElse(true);
    setFoldAtParenthesis(true);
    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerVHDL::Default);
    setColor(QColor("#EA0000"), QsciLexerVHDL::Comment);
    setColor(QColor("#EA0000"), QsciLexerVHDL::CommentLine);
    setColor(QColor("#39FF00"), QsciLexerVHDL::String);
    setColor(color, QsciLexerVHDL::Operator);
    setColor(color, QsciLexerVHDL::Identifier);
    setColor(QColor("#06DD00"), QsciLexerVHDL::UnclosedString);
    setColor(QColor("#FF6D00"), QsciLexerVHDL::Keyword);
    setColor(color, QsciLexerVHDL::StandardOperator);
    setColor(QColor("#3966FF"), QsciLexerVHDL::Attribute);
    setColor(QColor("#FF00FD"), QsciLexerVHDL::StandardFunction);
    setColor(QColor("#3900FF"), QsciLexerVHDL::StandardPackage);
    setColor(QColor("#900090"), QsciLexerVHDL::StandardType);
    setColor(QColor("#FF6D00"), QsciLexerVHDL::KeywordSet7);
    setColor(QColor("#EA0000"), QsciLexerVHDL::CommentBlock);

    setFont(font, QsciLexerVHDL::Default);
    setFont(font, QsciLexerVHDL::Comment);
    setFont(font, QsciLexerVHDL::CommentLine);
    setFont(font, QsciLexerVHDL::String);
    setFont(font, QsciLexerVHDL::Operator);
    setFont(font, QsciLexerVHDL::Identifier);
    setFont(font, QsciLexerVHDL::UnclosedString);
    setFont(font, QsciLexerVHDL::Keyword);
    setFont(font, QsciLexerVHDL::StandardOperator);
    setFont(font, QsciLexerVHDL::Attribute);
    setFont(font, QsciLexerVHDL::StandardFunction);
    setFont(font, QsciLexerVHDL::StandardPackage);
    setFont(font, QsciLexerVHDL::StandardType);
    setFont(font, QsciLexerVHDL::KeywordSet7);
    setFont(font, QsciLexerVHDL::CommentBlock);

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

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?7");
    }

    api->prepare();
}
