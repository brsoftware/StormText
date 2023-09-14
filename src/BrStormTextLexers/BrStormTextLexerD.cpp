/**
 * @brief BrStormTextLexerD.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 9 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerD.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerD::BrStormTextLexerD(QFont font, QColor color, QObject *parent)
    : QsciLexerD(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldAtElse(true);
    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerD::Default);
    setColor(QColor("#EA0000"), QsciLexerD::Comment);
    setColor(QColor("#EA0000"), QsciLexerD::CommentDoc);
    setColor(QColor("#EA0000"), QsciLexerD::CommentNested);
    setColor(QColor("#FF6D00"), QsciLexerD::Keyword);
    setColor(QColor("#FF6D00"), QsciLexerD::KeywordSecondary);
    setColor(QColor("#880088"), QsciLexerD::KeywordDoc);
    setColor(QColor("#3900FF"), QsciLexerD::Typedefs);
    setColor(QColor("#39FF00"), QsciLexerD::String);
    setColor(QColor("#06CC00"), QsciLexerD::UnclosedString);
    setColor(QColor("#17DD00"), QsciLexerD::Character);
    setColor(color, QsciLexerD::Operator);
    setColor(QColor("#3900FF"), QsciLexerD::Identifier);
    setColor(QColor("#EA0000"), QsciLexerD::CommentLineDoc);
    setColor(QColor("#999900"), QsciLexerD::CommentDocKeyword);
    setColor(QColor("#666699"), QsciLexerD::CommentDocKeywordError);
    setColor(QColor("#39FF00"), QsciLexerD::BackquoteString);
    setColor(QColor("#39FF00"), QsciLexerD::RawString);
    setColor(QColor("#FF6D00"), QsciLexerD::KeywordSet5);
    setColor(QColor("#FF6D00"), QsciLexerD::KeywordSet6);
    setColor(QColor("#FF6D00"), QsciLexerD::KeywordSet7);

    setFont(font, QsciLexerD::Default);
    setFont(font, QsciLexerD::Comment);
    setFont(font, QsciLexerD::CommentDoc);
    setFont(font, QsciLexerD::CommentNested);
    setFont(font, QsciLexerD::Keyword);
    setFont(font, QsciLexerD::KeywordSecondary);
    setFont(font, QsciLexerD::KeywordDoc);
    setFont(font, QsciLexerD::Typedefs);
    setFont(font, QsciLexerD::String);
    setFont(font, QsciLexerD::UnclosedString);
    setFont(font, QsciLexerD::Character);
    setFont(font, QsciLexerD::Operator);
    setFont(font, QsciLexerD::Identifier);
    setFont(font, QsciLexerD::CommentLineDoc);
    setFont(font, QsciLexerD::CommentDocKeyword);
    setFont(font, QsciLexerD::CommentDocKeywordError);
    setFont(font, QsciLexerD::BackquoteString);
    setFont(font, QsciLexerD::RawString);
    setFont(font, QsciLexerD::KeywordSet5);
    setFont(font, QsciLexerD::KeywordSet6);
    setFont(font, QsciLexerD::KeywordSet7);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
