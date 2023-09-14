/**
 * @brief BrStormTextLexerPython3.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerPython3.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerPython3::BrStormTextLexerPython3(QFont font, QColor color, QObject *parent)
    : QsciLexerPython(parent)
{
    setV2UnicodeAllowed(false);
    setV3BinaryOctalAllowed(true);
    setV3BytesAllowed(true);

    setFoldComments(true);
    setFoldCompact(true);
    setFoldQuotes(true);

    setIndentationWarning(QsciLexerPython::Inconsistent);

    setColor(color, QsciLexerPython::Default);
    setColor(QColor("#EA0000"), QsciLexerPython::Comment);
    setColor(QColor("#39FF00"), QsciLexerPython::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerPython::SingleQuotedString);
    setColor(QColor("#FF6D00"), QsciLexerPython::Keyword);
    setColor(QColor("#39FF00"), QsciLexerPython::TripleSingleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerPython::TripleDoubleQuotedString);
    setColor(QColor("#3900FF"), QsciLexerPython::ClassName);
    setColor(QColor("#3900FF"), QsciLexerPython::FunctionMethodName);
    setColor(color, QsciLexerPython::Operator);
    setColor(color, QsciLexerPython::Identifier);
    setColor(QColor("#EA0000"), QsciLexerPython::CommentBlock);
    setColor(QColor("#06DD00"), QsciLexerPython::UnclosedString);
    setColor(QColor("#FF00FD"), QsciLexerPython::HighlightedIdentifier);
    setColor(QColor("#39FF00"), QsciLexerPython::DoubleQuotedFString);
    setColor(QColor("#39FF00"), QsciLexerPython::SingleQuotedFString);
    setColor(QColor("#39FF00"), QsciLexerPython::TripleSingleQuotedFString);
    setColor(QColor("#39FF00"), QsciLexerPython::TripleDoubleQuotedFString);

    setFont(font, QsciLexerPython::Default);
    setFont(font, QsciLexerPython::Comment);
    setFont(font, QsciLexerPython::DoubleQuotedString);
    setFont(font, QsciLexerPython::SingleQuotedString);
    setFont(font, QsciLexerPython::Keyword);
    setFont(font, QsciLexerPython::TripleSingleQuotedString);
    setFont(font, QsciLexerPython::TripleDoubleQuotedString);
    setFont(font, QsciLexerPython::ClassName);
    setFont(font, QsciLexerPython::FunctionMethodName);
    setFont(font, QsciLexerPython::Operator);
    setFont(font, QsciLexerPython::Identifier);
    setFont(font, QsciLexerPython::CommentBlock);
    setFont(font, QsciLexerPython::UnclosedString);
    setFont(font, QsciLexerPython::HighlightedIdentifier);
    setFont(font, QsciLexerPython::DoubleQuotedFString);
    setFont(font, QsciLexerPython::SingleQuotedFString);
    setFont(font, QsciLexerPython::TripleSingleQuotedFString);
    setFont(font, QsciLexerPython::TripleDoubleQuotedFString);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(set1).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(set2).split(" "))
    {
        api->add(str + "?3");
    }

    api->prepare();
}
