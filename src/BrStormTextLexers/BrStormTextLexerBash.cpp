/**
 * @brief BrStormTextLexerBash.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 30 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerBash.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerBash::BrStormTextLexerBash(QFont font,
                                           QColor color,
                                           QObject *parent)
    : QsciLexerBash(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerBash::Default);
    setColor(QColor("#FF0000"), QsciLexerBash::Error);
    setColor(QColor("#EA0000"), QsciLexerBash::Comment);
    setColor(QColor("#FF6D00"), QsciLexerBash::Keyword);
    setColor(QColor("#39FF00"), QsciLexerBash::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerBash::SingleQuotedString);
    setColor(color, QsciLexerBash::Operator);
    setColor(QColor("#3900FF"), QsciLexerBash::Identifier);
    setColor(QColor("#7D7D7D"), QsciLexerBash::ParameterExpansion);
    setColor(QColor("#FFFF6C"), QsciLexerBash::Backticks);
    setColor(QColor("#39FF00"), QsciLexerBash::SingleQuotedHereDocument);

    setFont(font, QsciLexerBash::Default);
    setFont(font, QsciLexerBash::Error);
    setFont(font, QsciLexerBash::Comment);
    setFont(font, QsciLexerBash::Number);
    setFont(font, QsciLexerBash::Keyword);
    setFont(font, QsciLexerBash::DoubleQuotedString);
    setFont(font, QsciLexerBash::SingleQuotedString);
    setFont(font, QsciLexerBash::Operator);
    setFont(font, QsciLexerBash::Identifier);
    setFont(font, QsciLexerBash::Scalar);
    setFont(font, QsciLexerBash::ParameterExpansion);
    setFont(font, QsciLexerBash::Backticks);
    setFont(font, QsciLexerBash::HereDocumentDelimiter);
    setFont(font, QsciLexerBash::SingleQuotedHereDocument);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}

