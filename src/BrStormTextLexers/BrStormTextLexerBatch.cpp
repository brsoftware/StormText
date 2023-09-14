/**
 * @brief BrStormTextLexerBatch.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date Jun 4 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerBatch.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerBatch::BrStormTextLexerBatch(QFont font,
                                             QColor color,
                                             QObject *parent)
    : QsciLexerBatch(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setColor(color, QsciLexerBatch::Default);
    setColor(QColor("#EA0000"), QsciLexerBatch::Comment);
    setColor(QColor("#FF6D00"), QsciLexerBatch::Keyword);
    setColor(color, QsciLexerBatch::Label);
    setColor(color, QsciLexerBatch::HideCommandChar);
    setColor(color, QsciLexerBatch::ExternalCommand);
    setColor(color, QsciLexerBatch::Variable);
    setColor(color, QsciLexerBatch::Operator);

    setFont(font, QsciLexerBatch::Default);
    setFont(font, QsciLexerBatch::Comment);
    setFont(font, QsciLexerBatch::Keyword);
    setFont(font, QsciLexerBatch::Label);
    setFont(font, QsciLexerBatch::HideCommandChar);
    setFont(font, QsciLexerBatch::ExternalCommand);
    setFont(font, QsciLexerBatch::Variable);
    setFont(font, QsciLexerBatch::Operator);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}

