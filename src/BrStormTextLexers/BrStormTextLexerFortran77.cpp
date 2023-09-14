/**
 * @brief BrStormTextLexerFortran77.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 25 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerFortran77.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerFortran77::BrStormTextLexerFortran77(QFont font, QColor color, QObject *parent)
    : QsciLexerFortran77(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldCompact(true);

    setColor(color, QsciLexerFortran77::Default);
    setColor(QColor("#EA0000"), QsciLexerFortran77::Comment);
    setColor(QColor("#39FF00"), QsciLexerFortran77::SingleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerFortran77::DoubleQuotedString);
    setColor(QColor("#06CC00"), QsciLexerFortran77::UnclosedString);
    setColor(color, QsciLexerFortran77::Operator);
    setColor(color, QsciLexerFortran77::Identifier);
    setColor(QColor("#FF6D00"), QsciLexerFortran77::Keyword);
    setColor(QColor("#3900FD"), QsciLexerFortran77::IntrinsicFunction);
    setColor(QColor("#3900FD"), QsciLexerFortran77::ExtendedFunction);
    setColor(QColor("#FF00FD"), QsciLexerFortran77::PreProcessor);
    setColor(color, QsciLexerFortran77::DottedOperator);
    setColor(color, QsciLexerFortran77::Label);
    setColor(color, QsciLexerFortran77::Continuation);

    setFont(font, QsciLexerFortran77::Default);
    setFont(font, QsciLexerFortran77::Comment);
    setFont(font, QsciLexerFortran77::SingleQuotedString);
    setFont(font, QsciLexerFortran77::DoubleQuotedString);
    setFont(font, QsciLexerFortran77::UnclosedString);
    setFont(font, QsciLexerFortran77::Operator);
    setFont(font, QsciLexerFortran77::Identifier);
    setFont(font, QsciLexerFortran77::Keyword);
    setFont(font, QsciLexerFortran77::IntrinsicFunction);
    setFont(font, QsciLexerFortran77::ExtendedFunction);
    setFont(font, QsciLexerFortran77::PreProcessor);
    setFont(font, QsciLexerFortran77::DottedOperator);
    setFont(font, QsciLexerFortran77::Label);
    setFont(font, QsciLexerFortran77::Continuation);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
