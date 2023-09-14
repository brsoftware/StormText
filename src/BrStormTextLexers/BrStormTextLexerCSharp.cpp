/**
 * @brief BrStormTextLexerCPP.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerCSharp.hpp"

#include <QList>
#include <Qsci/qsciapis.h>
#include <QString>


BrStormTextLexerCSharp::BrStormTextLexerCSharp(QFont font, QColor color, QObject *parent)
    : QsciLexerCSharp(parent)
{
    QList<QString> listPreprocessor = {
        "#nullable",
        "#if",
        "#elif",
        "#else",
        "#endif",
        "#define",
        "#region",
        "#endregion",
        "#error",
        "#warning",
        "#line",
        "#pragma",
        "NETFRAMEWORK",
        "NET48",
        "NET472",
        "NET471",
        "NET47",
        "NET46",
        "NET452",
        "NET451",
        "NET45",
        "NET40",
        "NET35",
        "NET20",
        "NET48_OR_GREATER",
        "NET472_OR_GREATER",
        "NET471_OR_GREATER",
        "NET47_OR_GREATER",
        "NET462_OR_GREATER",
        "NET461_OR_GREATER",
        "NET46_OR_GREATER",
        "NET452_OR_GREATER",
        "NET451_OR_GREATER",
        "NET45_OR_GREATER",
        "NET40_OR_GREATER",
        "NET35_OR_GREATER",
        "NET20_OR_GREATER",
        "NETSTANDARD",
        "NETSTANDARD2_1",
        "NETSTANDARD2_0",
        "NETSTANDARD1_6",
        "NETSTANDARD1_5",
        "NETSTANDARD1_4",
        "NETSTANDARD1_3",
        "NETSTANDARD1_2",
        "NETSTANDARD1_1",
        "NETSTANDARD1_0",
        "NETSTANDARD2_1_OR_GREATER",
        "NETSTANDARD2_0_OR_GREATER",
        "NETSTANDARD1_6_OR_GREATER",
        "NETSTANDARD1_5_OR_GREATER",
        "NETSTANDARD1_4_OR_GREATER",
        "NETSTANDARD1_3_OR_GREATER",
        "NETSTANDARD1_2_OR_GREATER",
        "NETSTANDARD1_1_OR_GREATER",
        "NETSTANDARD1_0_OR_GREATER",
        "NET",
        "NET7_0",
        "NET6_0",
        "NET5_0",
        "NETCOREAPP",
        "NETCOREAPP3_1",
        "NETCOREAPP3_0",
        "NETCOREAPP2_2",
        "NETCOREAPP2_1",
        "NETCOREAPP2_0",
        "NETCOREAPP1_1",
        "NETCOREAPP1_0",
        "NET7_0_OR_GREATER",
        "NET6_0_OR_GREATER",
        "NET5_0_OR_GREATER",
        "NETCOREAPP3_1_OR_GREATER",
        "NETCOREAPP3_0_OR_GREATER",
        "NETCOREAPP2_2_OR_GREATER",
        "NETCOREAPP2_1_OR_GREATER",
        "NETCOREAPP2_0_OR_GREATER",
        "NETCOREAPP1_1_OR_GREATER",
        "NETCOREAPP1_0_OR_GREATER",
        "ANDROID",
        "IOS",
        "MACCATALYST",
        "MACOS",
        "TVOS",
        "WINDOWS"
    };

    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldAtElse(true);
    setFoldComments(true);
    setFoldCompact(true);
    setFoldPreprocessor(true);

    setColor(color, QsciLexerCPP::Default);
    setColor(QColor("#EA0000"), QsciLexerCPP::Comment);
    setColor(QColor("#EA0000"), QsciLexerCPP::CommentLine);
    setColor(QColor("#EA0000"), QsciLexerCPP::CommentDoc);
    setColor(QColor("#FF6D00"), QsciLexerCPP::Keyword);
    setColor(QColor("#39FF00"), QsciLexerCPP::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerCPP::SingleQuotedString);
    setColor(defaultColor(QsciLexerCPP::Number), QsciLexerCPP::UUID);
    setColor(QColor("#FF00FD"), QsciLexerCPP::PreProcessor);
    setColor(color, QsciLexerCPP::Operator);
    setColor(QColor("#3900FF"), QsciLexerCPP::Identifier);
    setColor(QColor("#06CC00"), QsciLexerCPP::UnclosedString);
    setColor(QColor("#17DD00"), QsciLexerCPP::VerbatimString);
    setColor(color, QsciLexerCPP::Regex);
    setColor(QColor("#EA0000"), QsciLexerCPP::CommentLineDoc);
    setColor(QColor("#FF6D00"), QsciLexerCPP::KeywordSet2);
    setColor(QColor("#999900"), QsciLexerCPP::CommentDocKeyword);
    setColor(QColor("#666699"), QsciLexerCPP::CommentDocKeywordError);
    setColor(QColor("#3900FF"), QsciLexerCPP::GlobalClass);
    setColor(QColor("#39FF00"), QsciLexerCPP::RawString);
    setColor(QColor("#39FF00"), QsciLexerCPP::TripleQuotedVerbatimString);
    setColor(QColor("#39FF00"), QsciLexerCPP::HashQuotedString);
    setColor(QColor("#AA33AA"), QsciLexerCPP::PreProcessorComment);
    setColor(QColor("#880088"), QsciLexerCPP::PreProcessorCommentLineDoc);
    setColor(color, QsciLexerCPP::UserLiteral);
    setColor(color, QsciLexerCPP::TaskMarker);
    setColor(color, QsciLexerCPP::EscapeSequence);
    setColor(color, QsciLexerCPP::InactiveDefault);
    setColor(QColor("#EA0000"), QsciLexerCPP::InactiveComment);
    setColor(QColor("#EA0000"), QsciLexerCPP::InactiveCommentLine);
    setColor(QColor("#EA0000"), QsciLexerCPP::InactiveCommentDoc);
    setColor(QColor("#FF6D00"), QsciLexerCPP::InactiveKeyword);
    setColor(QColor("#39FF00"), QsciLexerCPP::InactiveDoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerCPP::InactiveSingleQuotedString);
    setColor(defaultColor(QsciLexerCPP::InactiveNumber), QsciLexerCPP::InactiveUUID);
    setColor(QColor("#FF00FD"), QsciLexerCPP::InactivePreProcessor);
    setColor(color, QsciLexerCPP::InactiveOperator);
    setColor(QColor("#3900FF"), QsciLexerCPP::InactiveIdentifier);
    setColor(QColor("#06CC00"), QsciLexerCPP::InactiveUnclosedString);
    setColor(QColor("#17DD00"), QsciLexerCPP::InactiveVerbatimString);
    setColor(color, QsciLexerCPP::InactiveRegex);
    setColor(QColor("#EA0000"), QsciLexerCPP::InactiveCommentLineDoc);
    setColor(QColor("#FF6D00"), QsciLexerCPP::InactiveKeywordSet2);
    setColor(QColor("#999900"), QsciLexerCPP::InactiveCommentDocKeyword);
    setColor(QColor("#666699"), QsciLexerCPP::InactiveCommentDocKeywordError);
    setColor(QColor("#3900FF"), QsciLexerCPP::InactiveGlobalClass);
    setColor(QColor("#39FF00"), QsciLexerCPP::InactiveRawString);
    setColor(QColor("#39FF00"), QsciLexerCPP::InactiveTripleQuotedVerbatimString);
    setColor(QColor("#39FF00"), QsciLexerCPP::InactiveHashQuotedString);
    setColor(QColor("#AA33AA"), QsciLexerCPP::InactivePreProcessorComment);
    setColor(QColor("#880088"), QsciLexerCPP::InactivePreProcessorCommentLineDoc);
    setColor(color, QsciLexerCPP::InactiveUserLiteral);
    setColor(color, QsciLexerCPP::InactiveTaskMarker);
    setColor(color, QsciLexerCPP::InactiveEscapeSequence);

    setFont(font, QsciLexerCPP::Default);
    setFont(font, QsciLexerCPP::Comment);
    setFont(font, QsciLexerCPP::CommentLine);
    setFont(font, QsciLexerCPP::CommentDoc);
    setFont(font, QsciLexerCPP::Keyword);
    setFont(font, QsciLexerCPP::DoubleQuotedString);
    setFont(font, QsciLexerCPP::SingleQuotedString);
    setFont(font, QsciLexerCPP::UUID);
    setFont(font, QsciLexerCPP::PreProcessor);
    setFont(font, QsciLexerCPP::Operator);
    setFont(font, QsciLexerCPP::Identifier);
    setFont(font, QsciLexerCPP::UnclosedString);
    setFont(font, QsciLexerCPP::VerbatimString);
    setFont(font, QsciLexerCPP::Regex);
    setFont(font, QsciLexerCPP::CommentLineDoc);
    setFont(font, QsciLexerCPP::KeywordSet2);
    setFont(font, QsciLexerCPP::CommentDocKeyword);
    setFont(font, QsciLexerCPP::CommentDocKeywordError);
    setFont(font, QsciLexerCPP::GlobalClass);
    setFont(font, QsciLexerCPP::RawString);
    setFont(font, QsciLexerCPP::TripleQuotedVerbatimString);
    setFont(font, QsciLexerCPP::HashQuotedString);
    setFont(font, QsciLexerCPP::PreProcessorComment);
    setFont(font, QsciLexerCPP::PreProcessorCommentLineDoc);
    setFont(font, QsciLexerCPP::UserLiteral);
    setFont(font, QsciLexerCPP::TaskMarker);
    setFont(font, QsciLexerCPP::EscapeSequence);
    setFont(font, QsciLexerCPP::InactiveDefault);
    setFont(font, QsciLexerCPP::InactiveComment);
    setFont(font, QsciLexerCPP::InactiveCommentLine);
    setFont(font, QsciLexerCPP::InactiveCommentDoc);
    setFont(font, QsciLexerCPP::InactiveKeyword);
    setFont(font, QsciLexerCPP::InactiveDoubleQuotedString);
    setFont(font, QsciLexerCPP::InactiveSingleQuotedString);
    setFont(font, QsciLexerCPP::InactiveUUID);
    setFont(font, QsciLexerCPP::InactivePreProcessor);
    setFont(font, QsciLexerCPP::InactiveOperator);
    setFont(font, QsciLexerCPP::InactiveIdentifier);
    setFont(font, QsciLexerCPP::InactiveUnclosedString);
    setFont(font, QsciLexerCPP::InactiveVerbatimString);
    setFont(font, QsciLexerCPP::InactiveRegex);
    setFont(font, QsciLexerCPP::InactiveCommentLineDoc);
    setFont(font, QsciLexerCPP::InactiveKeywordSet2);
    setFont(font, QsciLexerCPP::InactiveCommentDocKeyword);
    setFont(font, QsciLexerCPP::InactiveCommentDocKeywordError);
    setFont(font, QsciLexerCPP::InactiveGlobalClass);
    setFont(font, QsciLexerCPP::InactiveRawString);
    setFont(font, QsciLexerCPP::InactiveTripleQuotedVerbatimString);
    setFont(font, QsciLexerCPP::InactiveHashQuotedString);
    setFont(font, QsciLexerCPP::InactivePreProcessorComment);
    setFont(font, QsciLexerCPP::InactivePreProcessorCommentLineDoc);
    setFont(font, QsciLexerCPP::InactiveUserLiteral);
    setFont(font, QsciLexerCPP::InactiveTaskMarker);
    setFont(font, QsciLexerCPP::InactiveEscapeSequence);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : listPreprocessor)
    {
        api->add(str + "?6");
    }

    api->prepare();
}
