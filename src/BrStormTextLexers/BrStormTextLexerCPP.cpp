/**
 * @brief BrStormTextLexerCPP.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerCPP.hpp"

#include <QList>
#include <Qsci/qsciapis.h>
#include <QString>


BrStormTextLexerCPP::BrStormTextLexerCPP(QFont font, QColor color, QObject *parent)
    : QsciLexerCPP(parent)
{
    QList<QString> listPreprocessor = {
        "#if",
        "#elif",
        "#else",
        "#endif",
        "#ifdef",
        "#ifndef",
        "#elifdef",
        "#elifndef",
        "#define",
        "#undef",
        "#include",
        "#line",
        "#error",
        "#warning",
        "#pragma",
        "#defined",
        "#__has_include",
        "#__has_cpp_attribute",
        "#export",
        "#import",
        "#module"
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

    for (const QString &str : QString(m_keywordSet1).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : listPreprocessor)
    {
        api->add(str + "?6");
    }

    api->prepare();
}

const char *BrStormTextLexerCPP::keywords(int set) const
{
    if (set == 1)
        return m_keywordSet1;

    if (set == 2)
        return "emit foreach signals SIGNAL slots SLOT";

    if (set == 3)
        return m_keywordSet3;

    return 0;
}
