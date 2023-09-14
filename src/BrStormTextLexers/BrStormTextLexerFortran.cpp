/**
 * @brief BrStormTextLexerFortran.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerFortran.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerFortran::BrStormTextLexerFortran(QFont font, QColor color, QObject *parent)
    : QsciLexerFortran(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldCompact(true);

    setColor(color, QsciLexerFortran::Default);
    setColor(QColor("#EA0000"), QsciLexerFortran::Comment);
    setColor(QColor("#39FF00"), QsciLexerFortran::SingleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerFortran::DoubleQuotedString);
    setColor(QColor("#06CC00"), QsciLexerFortran::UnclosedString);
    setColor(color, QsciLexerFortran::Operator);
    setColor(color, QsciLexerFortran::Identifier);
    setColor(QColor("#FF6D00"), QsciLexerFortran::Keyword);
    setColor(QColor("#3900FD"), QsciLexerFortran::IntrinsicFunction);
    setColor(QColor("#3900FD"), QsciLexerFortran::ExtendedFunction);
    setColor(QColor("#FF00FD"), QsciLexerFortran::PreProcessor);
    setColor(color, QsciLexerFortran::DottedOperator);
    setColor(color, QsciLexerFortran::Label);
    setColor(color, QsciLexerFortran::Continuation);

    setFont(font, QsciLexerFortran::Default);
    setFont(font, QsciLexerFortran::Comment);
    setFont(font, QsciLexerFortran::SingleQuotedString);
    setFont(font, QsciLexerFortran::DoubleQuotedString);
    setFont(font, QsciLexerFortran::UnclosedString);
    setFont(font, QsciLexerFortran::Operator);
    setFont(font, QsciLexerFortran::Identifier);
    setFont(font, QsciLexerFortran::Keyword);
    setFont(font, QsciLexerFortran::IntrinsicFunction);
    setFont(font, QsciLexerFortran::ExtendedFunction);
    setFont(font, QsciLexerFortran::PreProcessor);
    setFont(font, QsciLexerFortran::DottedOperator);
    setFont(font, QsciLexerFortran::Label);
    setFont(font, QsciLexerFortran::Continuation);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?3");
    }

    api->prepare();
}
