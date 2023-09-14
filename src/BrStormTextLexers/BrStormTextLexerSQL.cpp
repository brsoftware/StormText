/**
 * @brief BrStormTextLexerSQL.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerSQL.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerSQL::BrStormTextLexerSQL(QFont font, QColor color, QObject *parent)
    : QsciLexerSQL(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldAtElse(true);
    setFoldComments(true);
    setFoldCompact(true);
    setFoldOnlyBegin(false);

    setColor(color, QsciLexerSQL::Default);
    setColor(QColor("#EA0000"), QsciLexerSQL::Comment);
    setColor(QColor("#EA0000"), QsciLexerSQL::CommentLine);
    setColor(QColor("#EA0000"), QsciLexerSQL::CommentDoc);
    setColor(QColor("#FF6D00"), QsciLexerSQL::Keyword);
    setColor(QColor("#39FF00"), QsciLexerSQL::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerSQL::SingleQuotedString);
    setColor(QColor("#FF6D00"), QsciLexerSQL::PlusKeyword);
    setColor(QColor("#770000"), QsciLexerSQL::PlusPrompt);
    setColor(color, QsciLexerSQL::Operator);
    setColor(color, QsciLexerSQL::Identifier);
    setColor(QColor("#EA0000"), QsciLexerSQL::PlusComment);
    setColor(QColor("#EA0000"), QsciLexerSQL::CommentLineHash);
    setColor(QColor("#999900"), QsciLexerSQL::CommentDocKeyword);
    setColor(QColor("#666699"), QsciLexerSQL::CommentDocKeywordError);
    setColor(QColor("#FF6D00"), QsciLexerSQL::KeywordSet5);
    setColor(QColor("#FF6D00"), QsciLexerSQL::KeywordSet6);
    setColor(QColor("#FF6D00"), QsciLexerSQL::KeywordSet7);
    setColor(QColor("#FF6D00"), QsciLexerSQL::KeywordSet8);
    setColor(color, QsciLexerSQL::QuotedOperator);
    setColor(color, QsciLexerSQL::QuotedIdentifier);

    setFont(font, QsciLexerSQL::Default);
    setFont(font, QsciLexerSQL::Comment);
    setFont(font, QsciLexerSQL::CommentLine);
    setFont(font, QsciLexerSQL::CommentDoc);
    setFont(font, QsciLexerSQL::Keyword);
    setFont(font, QsciLexerSQL::DoubleQuotedString);
    setFont(font, QsciLexerSQL::SingleQuotedString);
    setFont(font, QsciLexerSQL::PlusKeyword);
    setFont(font, QsciLexerSQL::PlusPrompt);
    setFont(font, QsciLexerSQL::Operator);
    setFont(font, QsciLexerSQL::Identifier);
    setFont(font, QsciLexerSQL::PlusComment);
    setFont(font, QsciLexerSQL::CommentLineHash);
    setFont(font, QsciLexerSQL::CommentDocKeyword);
    setFont(font, QsciLexerSQL::CommentDocKeywordError);
    setFont(font, QsciLexerSQL::KeywordSet5);
    setFont(font, QsciLexerSQL::KeywordSet6);
    setFont(font, QsciLexerSQL::KeywordSet7);
    setFont(font, QsciLexerSQL::KeywordSet8);
    setFont(font, QsciLexerSQL::QuotedOperator);
    setFont(font, QsciLexerSQL::QuotedIdentifier);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(4)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(5)).split(" "))
    {
        api->add(str + "?3");
    }

    api->prepare();
}
