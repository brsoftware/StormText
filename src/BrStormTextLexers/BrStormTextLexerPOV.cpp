/**
 * @brief BrStormTextLexerPOV.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerPOV.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerPOV::BrStormTextLexerPOV(QFont font, QColor color, QObject *parent)
    : QsciLexerPOV(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);
    setFoldDirectives(true);

    setColor(color, QsciLexerPOV::Default);
    setColor(QColor("#EA0000"), QsciLexerPOV::Comment);
    setColor(QColor("#EA0000"), QsciLexerPOV::CommentLine);
    setColor(color, QsciLexerPOV::Operator);
    setColor(QColor("#3900FF"), QsciLexerPOV::Identifier);
    setColor(QColor("#39FF00"), QsciLexerPOV::String);
    setColor(QColor("#06DD00"), QsciLexerPOV::UnclosedString);
    setColor(QColor("#39FFFF"), QsciLexerPOV::Directive);
    setColor(QColor("#FF3939"), QsciLexerPOV::BadDirective);
    setColor(QColor("#FF00FD"), QsciLexerPOV::ObjectsCSGAppearance);
    setColor(QColor("#FF00FD"), QsciLexerPOV::TypesModifiersItems);
    setColor(QColor("#FF00FD"), QsciLexerPOV::PredefinedIdentifiers);
    setColor(QColor("#FF00FD"), QsciLexerPOV::PredefinedFunctions);
    setColor(QColor("#FF6D00"), QsciLexerPOV::KeywordSet6);
    setColor(QColor("#FF6D00"), QsciLexerPOV::KeywordSet7);
    setColor(QColor("#FF6D00"), QsciLexerPOV::KeywordSet8);

    setFont(font, QsciLexerPOV::Default);
    setFont(font, QsciLexerPOV::Comment);
    setFont(font, QsciLexerPOV::CommentLine);
    setFont(font, QsciLexerPOV::Operator);
    setFont(font, QsciLexerPOV::Identifier);
    setFont(font, QsciLexerPOV::String);
    setFont(font, QsciLexerPOV::UnclosedString);
    setFont(font, QsciLexerPOV::Directive);
    setFont(font, QsciLexerPOV::BadDirective);
    setFont(font, QsciLexerPOV::ObjectsCSGAppearance);
    setFont(font, QsciLexerPOV::TypesModifiersItems);
    setFont(font, QsciLexerPOV::PredefinedIdentifiers);
    setFont(font, QsciLexerPOV::PredefinedFunctions);
    setFont(font, QsciLexerPOV::KeywordSet6);
    setFont(font, QsciLexerPOV::KeywordSet7);
    setFont(font, QsciLexerPOV::KeywordSet8);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?1");
    }

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?2");
    }

    for (const QString &str : QString(keywords(4)).split(" "))
    {
        api->add(str + "?3");
    }

    for (const QString &str : QString(keywords(5)).split(" "))
    {
        api->add(str + "?3");
    }

    api->prepare();
}
