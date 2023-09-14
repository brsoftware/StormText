/**
 * @brief BrStormTextLexerRuby.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerRuby.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerRuby::BrStormTextLexerRuby(QFont font, QColor color, QObject *parent)
    : QsciLexerRuby(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerRuby::Default);
    setColor(QColor("#FF7777"), QsciLexerRuby::Error);
    setColor(QColor("#EA0000"), QsciLexerRuby::Comment);
    setColor(QColor("#EA0000"), QsciLexerRuby::POD);
    setColor(QColor("#FF6D00"), QsciLexerRuby::Keyword);
    setColor(QColor("#39FF00"), QsciLexerRuby::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerRuby::SingleQuotedString);
    setColor(QColor("#3900FF"), QsciLexerRuby::ClassName);
    setColor(QColor("#3900FF"), QsciLexerRuby::FunctionMethodName);
    setColor(color, QsciLexerRuby::Operator);
    setColor(color, QsciLexerRuby::Identifier);
    setColor(color, QsciLexerRuby::Regex);
    setColor(color, QsciLexerRuby::Global);
    setColor(color, QsciLexerRuby::Symbol);
    setColor(color, QsciLexerRuby::ModuleName);
    setColor(color, QsciLexerRuby::InstanceVariable);
    setColor(color, QsciLexerRuby::ClassVariable);
    setColor(QColor("#AAAA00"), QsciLexerRuby::Backticks);
    setColor(color, QsciLexerRuby::DataSection);
    setColor(QColor("#EA0000"), QsciLexerRuby::HereDocumentDelimiter);
    setColor(QColor("#EA0000"), QsciLexerRuby::HereDocument);
    setColor(QColor("#39FF00"), QsciLexerRuby::PercentStringq);
    setColor(QColor("#39FF00"), QsciLexerRuby::PercentStringQ);
    setColor(QColor("#39FF00"), QsciLexerRuby::PercentStringx);
    setColor(QColor("#39FF00"), QsciLexerRuby::PercentStringr);
    setColor(QColor("#39FF00"), QsciLexerRuby::PercentStringw);
    setColor(QColor("#FF6D00"), QsciLexerRuby::DemotedKeyword);
    setColor(color, QsciLexerRuby::Stdin);
    setColor(color, QsciLexerRuby::Stdout);
    setColor(QColor("#FF7777"), QsciLexerRuby::Stderr);

    setFont(font, QsciLexerRuby::Default);
    setFont(font, QsciLexerRuby::Error);
    setFont(font, QsciLexerRuby::Comment);
    setFont(font, QsciLexerRuby::POD);
    setFont(font, QsciLexerRuby::Keyword);
    setFont(font, QsciLexerRuby::DoubleQuotedString);
    setFont(font, QsciLexerRuby::SingleQuotedString);
    setFont(font, QsciLexerRuby::ClassName);
    setFont(font, QsciLexerRuby::FunctionMethodName);
    setFont(font, QsciLexerRuby::Operator);
    setFont(font, QsciLexerRuby::Identifier);
    setFont(font, QsciLexerRuby::Regex);
    setFont(font, QsciLexerRuby::Global);
    setFont(font, QsciLexerRuby::Symbol);
    setFont(font, QsciLexerRuby::ModuleName);
    setFont(font, QsciLexerRuby::InstanceVariable);
    setFont(font, QsciLexerRuby::ClassVariable);
    setFont(font, QsciLexerRuby::Backticks);
    setFont(font, QsciLexerRuby::DataSection);
    setFont(font, QsciLexerRuby::HereDocumentDelimiter);
    setFont(font, QsciLexerRuby::HereDocument);
    setFont(font, QsciLexerRuby::PercentStringq);
    setFont(font, QsciLexerRuby::PercentStringQ);
    setFont(font, QsciLexerRuby::PercentStringx);
    setFont(font, QsciLexerRuby::PercentStringr);
    setFont(font, QsciLexerRuby::PercentStringw);
    setFont(font, QsciLexerRuby::DemotedKeyword);
    setFont(font, QsciLexerRuby::Stdin);
    setFont(font, QsciLexerRuby::Stdout);
    setFont(font, QsciLexerRuby::Stderr);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
