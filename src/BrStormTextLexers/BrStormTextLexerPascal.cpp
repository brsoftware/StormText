/**
 * @brief BrStormTextLexerPascal.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerPascal.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerPascal::BrStormTextLexerPascal(QFont font, QColor color, QObject *parent)
    : QsciLexerPascal(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);
    setFoldPreprocessor(true);

    setColor(color, QsciLexerPascal::Default);
    setColor(color, QsciLexerPascal::Identifier);
    setColor(QColor("#EA0000"), QsciLexerPascal::Comment);
    setColor(QColor("#EA0000"), QsciLexerPascal::CommentParenthesis);
    setColor(QColor("#EA0000"), QsciLexerPascal::CommentLine);
    setColor(QColor("#FF00FD"), QsciLexerPascal::PreProcessor);
    setColor(QColor("#FF00FD"), QsciLexerPascal::PreProcessorParenthesis);
    setColor(QColor("#FF6D00"), QsciLexerPascal::Keyword);
    setColor(QColor("#39FF00"), QsciLexerPascal::SingleQuotedString);
    setColor(QColor("#06DD00"), QsciLexerPascal::UnclosedString);
    setColor(QColor("#39FF00"), QsciLexerPascal::Character);
    setColor(color, QsciLexerPascal::Operator);
    setColor(QColor("#3900FF"), QsciLexerPascal::Asm);

    setFont(font, QsciLexerPascal::Default);
    setFont(font, QsciLexerPascal::Identifier);
    setFont(font, QsciLexerPascal::Comment);
    setFont(font, QsciLexerPascal::CommentParenthesis);
    setFont(font, QsciLexerPascal::CommentLine);
    setFont(font, QsciLexerPascal::PreProcessor);
    setFont(font, QsciLexerPascal::PreProcessorParenthesis);
    setFont(font, QsciLexerPascal::Keyword);
    setFont(font, QsciLexerPascal::SingleQuotedString);
    setFont(font, QsciLexerPascal::UnclosedString);
    setFont(font, QsciLexerPascal::Character);
    setFont(font, QsciLexerPascal::Operator);
    setFont(font, QsciLexerPascal::Asm);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
