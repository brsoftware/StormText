/**
 * @brief BrStormTextLexerPerl.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerPerl.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerPerl::BrStormTextLexerPerl(QFont font, QColor color, QObject *parent)
    : QsciLexerPerl(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerPerl::Default);
    setColor(QColor("#FF7777"), QsciLexerPerl::Error);
    setColor(QColor("#EA0000"), QsciLexerPerl::Comment);
    setColor(QColor("#EA0000"), QsciLexerPerl::POD);
    setColor(QColor("#FF6D00"), QsciLexerPerl::Keyword);
    setColor(QColor("#39FF00"), QsciLexerPerl::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerPerl::SingleQuotedString);
    setColor(color, QsciLexerPerl::Operator);
    setColor(color, QsciLexerPerl::Identifier);
    setColor(color, QsciLexerPerl::Scalar);
    setColor(color, QsciLexerPerl::Array);
    setColor(color, QsciLexerPerl::Hash);
    setColor(color, QsciLexerPerl::SymbolTable);
    setColor(color, QsciLexerPerl::Regex);
    setColor(color, QsciLexerPerl::Substitution);
    setColor(QColor("#AAAA7D"), QsciLexerPerl::Backticks);
    setColor(color, QsciLexerPerl::DataSection);
    setColor(QColor("#7A0000"), QsciLexerPerl::HereDocumentDelimiter);
    setColor(QColor("#7A0000"), QsciLexerPerl::SingleQuotedHereDocument);
    setColor(QColor("#7A0000"), QsciLexerPerl::DoubleQuotedHereDocument);
    setColor(QColor("#77774A"), QsciLexerPerl::BacktickHereDocument);
    setColor(QColor("#39FF00"), QsciLexerPerl::QuotedStringQ);
    setColor(QColor("#39FF00"), QsciLexerPerl::QuotedStringQQ);
    setColor(QColor("#39FF00"), QsciLexerPerl::QuotedStringQX);
    setColor(QColor("#39FF00"), QsciLexerPerl::QuotedStringQR);
    setColor(QColor("#39FF00"), QsciLexerPerl::QuotedStringQW);
    setColor(QColor("#EA0000"), QsciLexerPerl::PODVerbatim);
    setColor(color, QsciLexerPerl::SubroutinePrototype);
    setColor(color, QsciLexerPerl::FormatIdentifier);
    setColor(color, QsciLexerPerl::FormatBody);
    setColor(QColor("#39FF00"), QsciLexerPerl::DoubleQuotedStringVar);
    setColor(color, QsciLexerPerl::Translation);
    setColor(color, QsciLexerPerl::RegexVar);
    setColor(color, QsciLexerPerl::SubstitutionVar);
    setColor(QColor("#AAAA7D"), QsciLexerPerl::BackticksVar);
    setColor(QColor("#39FF00"), QsciLexerPerl::DoubleQuotedHereDocumentVar);
    setColor(QColor("#AAAA7D"), QsciLexerPerl::BacktickHereDocumentVar);
    setColor(QColor("#39FF00"), QsciLexerPerl::QuotedStringQXVar);
    setColor(QColor("#39FF00"), QsciLexerPerl::QuotedStringQRVar);

    setFont(font, QsciLexerPerl::Default);
    setFont(font, QsciLexerPerl::Error);
    setFont(font, QsciLexerPerl::Comment);
    setFont(font, QsciLexerPerl::POD);
    setFont(font, QsciLexerPerl::Keyword);
    setFont(font, QsciLexerPerl::DoubleQuotedString);
    setFont(font, QsciLexerPerl::SingleQuotedString);
    setFont(font, QsciLexerPerl::Operator);
    setFont(font, QsciLexerPerl::Identifier);
    setFont(font, QsciLexerPerl::Scalar);
    setFont(font, QsciLexerPerl::Array);
    setFont(font, QsciLexerPerl::Hash);
    setFont(font, QsciLexerPerl::SymbolTable);
    setFont(font, QsciLexerPerl::Regex);
    setFont(font, QsciLexerPerl::Substitution);
    setFont(font, QsciLexerPerl::Backticks);
    setFont(font, QsciLexerPerl::DataSection);
    setFont(font, QsciLexerPerl::HereDocumentDelimiter);
    setFont(font, QsciLexerPerl::SingleQuotedHereDocument);
    setFont(font, QsciLexerPerl::DoubleQuotedHereDocument);
    setFont(font, QsciLexerPerl::BacktickHereDocument);
    setFont(font, QsciLexerPerl::QuotedStringQ);
    setFont(font, QsciLexerPerl::QuotedStringQQ);
    setFont(font, QsciLexerPerl::QuotedStringQX);
    setFont(font, QsciLexerPerl::QuotedStringQR);
    setFont(font, QsciLexerPerl::QuotedStringQW);
    setFont(font, QsciLexerPerl::PODVerbatim);
    setFont(font, QsciLexerPerl::SubroutinePrototype);
    setFont(font, QsciLexerPerl::FormatIdentifier);
    setFont(font, QsciLexerPerl::FormatBody);
    setFont(font, QsciLexerPerl::DoubleQuotedStringVar);
    setFont(font, QsciLexerPerl::Translation);
    setFont(font, QsciLexerPerl::RegexVar);
    setFont(font, QsciLexerPerl::SubstitutionVar);
    setFont(font, QsciLexerPerl::BackticksVar);
    setFont(font, QsciLexerPerl::DoubleQuotedHereDocumentVar);
    setFont(font, QsciLexerPerl::BacktickHereDocumentVar);
    setFont(font, QsciLexerPerl::QuotedStringQXVar);
    setFont(font, QsciLexerPerl::QuotedStringQRVar);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
