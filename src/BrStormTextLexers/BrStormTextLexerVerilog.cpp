/**
 * @brief BrStormVerilogtLexerVerilog.cpp: A file of the StormVerilogt project.
 * @author Bright Software Foundation
 * @date Jun 29 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerVerilog.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerVerilog::BrStormTextLexerVerilog(QFont font, QColor color, QObject *parent)
    : QsciLexerVerilog(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldAtElse(true);
    setFoldAtModule(true);
    setFoldComments(true);
    setFoldCompact(true);
    setFoldPreprocessor(true);

    setColor(color, QsciLexerVerilog::Default);
    setColor(QColor("#EA0000"), QsciLexerVerilog::Comment);
    setColor(QColor("#EA0000"), QsciLexerVerilog::CommentLine);
    setColor(QColor("#EA0000"), QsciLexerVerilog::CommentBang);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::Keyword);
    setColor(QColor("#39FF00"), QsciLexerVerilog::String);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::KeywordSet2);
    setColor(QColor("#3900FF"), QsciLexerVerilog::SystemTask);
    setColor(QColor("#FF00FD"), QsciLexerVerilog::Preprocessor);
    setColor(color, QsciLexerVerilog::Operator);
    setColor(color, QsciLexerVerilog::Identifier);
    setColor(QColor("#06DD00"), QsciLexerVerilog::UnclosedString);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::UserKeywordSet);
    setColor(QColor("#999900"), QsciLexerVerilog::CommentKeyword);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::DeclareInputPort);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::DeclareOutputPort);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::DeclareInputOutputPort);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::PortConnection);
    setColor(color, QsciLexerVerilog::InactiveDefault);
    setColor(QColor("#EA0000"), QsciLexerVerilog::InactiveComment);
    setColor(QColor("#EA0000"), QsciLexerVerilog::InactiveCommentLine);
    setColor(QColor("#EA0000"), QsciLexerVerilog::InactiveCommentBang);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::InactiveKeyword);
    setColor(QColor("#39FF00"), QsciLexerVerilog::InactiveString);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::InactiveKeywordSet2);
    setColor(QColor("#3900FF"), QsciLexerVerilog::InactiveSystemTask);
    setColor(QColor("#FF00FD"), QsciLexerVerilog::InactivePreprocessor);
    setColor(color, QsciLexerVerilog::InactiveOperator);
    setColor(color, QsciLexerVerilog::InactiveIdentifier);
    setColor(QColor("#06DD00"), QsciLexerVerilog::InactiveUnclosedString);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::InactiveUserKeywordSet);
    setColor(QColor("#999900"), QsciLexerVerilog::InactiveCommentKeyword);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::InactiveDeclareInputPort);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::InactiveDeclareOutputPort);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::InactiveDeclareInputOutputPort);
    setColor(QColor("#FF6D00"), QsciLexerVerilog::InactivePortConnection);

    setFont(font, QsciLexerVerilog::Default);
    setFont(font, QsciLexerVerilog::Comment);
    setFont(font, QsciLexerVerilog::CommentLine);
    setFont(font, QsciLexerVerilog::CommentBang);
    setFont(font, QsciLexerVerilog::Keyword);
    setFont(font, QsciLexerVerilog::String);
    setFont(font, QsciLexerVerilog::KeywordSet2);
    setFont(font, QsciLexerVerilog::SystemTask);
    setFont(font, QsciLexerVerilog::Preprocessor);
    setFont(font, QsciLexerVerilog::Operator);
    setFont(font, QsciLexerVerilog::Identifier);
    setFont(font, QsciLexerVerilog::UnclosedString);
    setFont(font, QsciLexerVerilog::UserKeywordSet);
    setFont(font, QsciLexerVerilog::CommentKeyword);
    setFont(font, QsciLexerVerilog::DeclareInputPort);
    setFont(font, QsciLexerVerilog::DeclareOutputPort);
    setFont(font, QsciLexerVerilog::DeclareInputOutputPort);
    setFont(font, QsciLexerVerilog::PortConnection);
    setFont(font, QsciLexerVerilog::InactiveDefault);
    setFont(font, QsciLexerVerilog::InactiveComment);
    setFont(font, QsciLexerVerilog::InactiveCommentLine);
    setFont(font, QsciLexerVerilog::InactiveCommentBang);
    setFont(font, QsciLexerVerilog::InactiveKeyword);
    setFont(font, QsciLexerVerilog::InactiveString);
    setFont(font, QsciLexerVerilog::InactiveKeywordSet2);
    setFont(font, QsciLexerVerilog::InactiveSystemTask);
    setFont(font, QsciLexerVerilog::InactivePreprocessor);
    setFont(font, QsciLexerVerilog::InactiveOperator);
    setFont(font, QsciLexerVerilog::InactiveIdentifier);
    setFont(font, QsciLexerVerilog::InactiveUnclosedString);
    setFont(font, QsciLexerVerilog::InactiveUserKeywordSet);
    setFont(font, QsciLexerVerilog::InactiveCommentKeyword);
    setFont(font, QsciLexerVerilog::InactiveDeclareInputPort);
    setFont(font, QsciLexerVerilog::InactiveDeclareOutputPort);
    setFont(font, QsciLexerVerilog::InactiveDeclareInputOutputPort);
    setFont(font, QsciLexerVerilog::InactivePortConnection);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
