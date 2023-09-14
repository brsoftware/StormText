/**
 * @brief BrStormTextLexerYAML.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 30 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerYAML.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerYAML::BrStormTextLexerYAML(QFont font, QColor color, QObject *parent)
    : QsciLexerYAML(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);

    setColor(color, QsciLexerYAML::Default);
    setColor(QColor("#EA0000"), QsciLexerYAML::Comment);
    setColor(color, QsciLexerYAML::Identifier);
    setColor(QColor("#FF6D00"), QsciLexerYAML::Keyword);
    setColor(QColor("#3900FF"), QsciLexerYAML::Reference);
    setColor(color, QsciLexerYAML::DocumentDelimiter);
    setColor(color, QsciLexerYAML::TextBlockMarker);
    setColor(QColor("#FF7777"), QsciLexerYAML::SyntaxErrorMarker);
    setColor(color, QsciLexerYAML::Operator);

    setFont(font, QsciLexerYAML::Default);
    setFont(font, QsciLexerYAML::Comment);
    setFont(font, QsciLexerYAML::Identifier);
    setFont(font, QsciLexerYAML::Keyword);
    setFont(font, QsciLexerYAML::Reference);
    setFont(font, QsciLexerYAML::DocumentDelimiter);
    setFont(font, QsciLexerYAML::TextBlockMarker);
    setFont(font, QsciLexerYAML::SyntaxErrorMarker);
    setFont(font, QsciLexerYAML::Operator);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
