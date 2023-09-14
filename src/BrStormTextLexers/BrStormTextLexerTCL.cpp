/**
 * @brief BrStormTextLexerTCL.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerTCL.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerTCL::BrStormTextLexerTCL(QFont font, QColor color, QObject *parent)
    : QsciLexerTCL(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);

    setColor(color, QsciLexerTCL::Default);
    setColor(QColor("#EA0000"), QsciLexerTCL::Comment);
    setColor(QColor("#EA0000"), QsciLexerTCL::CommentLine);
    setColor(QColor("#FF6D00"), QsciLexerTCL::QuotedKeyword);
    setColor(QColor("#39FF00"), QsciLexerTCL::QuotedString);
    setColor(color, QsciLexerTCL::Operator);
    setColor(color, QsciLexerTCL::Identifier);
    setColor(color, QsciLexerTCL::Substitution);
    setColor(color, QsciLexerTCL::SubstitutionBrace);
    setColor(color, QsciLexerTCL::Modifier);
    setColor(QColor("#FF6D00"), QsciLexerTCL::ExpandKeyword);
    setColor(QColor("#FF6D00"), QsciLexerTCL::TCLKeyword);
    setColor(QColor("#FF6D00"), QsciLexerTCL::TkKeyword);
    setColor(QColor("#FF6D00"), QsciLexerTCL::ITCLKeyword);
    setColor(QColor("#3900FF"), QsciLexerTCL::TkCommand);
    setColor(QColor("#FF6D00"), QsciLexerTCL::KeywordSet6);
    setColor(QColor("#FF6D00"), QsciLexerTCL::KeywordSet7);
    setColor(QColor("#FF6D00"), QsciLexerTCL::KeywordSet8);
    setColor(QColor("#FF6D00"), QsciLexerTCL::KeywordSet9);
    setColor(QColor("#EA0000"), QsciLexerTCL::CommentBox);
    setColor(QColor("#EA0000"), QsciLexerTCL::CommentBlock);

    setFont(font, QsciLexerTCL::Default);
    setFont(font, QsciLexerTCL::Comment);
    setFont(font, QsciLexerTCL::CommentLine);
    setFont(font, QsciLexerTCL::QuotedKeyword);
    setFont(font, QsciLexerTCL::QuotedString);
    setFont(font, QsciLexerTCL::Operator);
    setFont(font, QsciLexerTCL::Identifier);
    setFont(font, QsciLexerTCL::Substitution);
    setFont(font, QsciLexerTCL::SubstitutionBrace);
    setFont(font, QsciLexerTCL::Modifier);
    setFont(font, QsciLexerTCL::ExpandKeyword);
    setFont(font, QsciLexerTCL::TCLKeyword);
    setFont(font, QsciLexerTCL::TkKeyword);
    setFont(font, QsciLexerTCL::ITCLKeyword);
    setFont(font, QsciLexerTCL::TkCommand);
    setFont(font, QsciLexerTCL::KeywordSet6);
    setFont(font, QsciLexerTCL::KeywordSet7);
    setFont(font, QsciLexerTCL::KeywordSet8);
    setFont(font, QsciLexerTCL::KeywordSet9);
    setFont(font, QsciLexerTCL::CommentBox);
    setFont(font, QsciLexerTCL::CommentBlock);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?5");
    }

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?6");
    }

    for (const QString &str : QString(keywords(4)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(5)).split(" "))
    {
        api->add(str + "?6");
    }

    api->prepare();
}
