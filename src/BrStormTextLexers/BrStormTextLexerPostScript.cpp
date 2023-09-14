/**
 * @brief BrStormTextLexerPostScript.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 26 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerPostScript.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerPostScript::BrStormTextLexerPostScript(QFont font, QColor color, QObject *parent)
    : QsciLexerPostScript(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldAtElse(true);
    setFoldCompact(true);

    setColor(color, QsciLexerPostScript::Default);
    setColor(QColor("#EA0000"), QsciLexerPostScript::Comment);
    setColor(QColor("#EA0000"), QsciLexerPostScript::DSCComment);
    setColor(QColor("#EA0000"), QsciLexerPostScript::DSCCommentValue);
    setColor(QColor("#3900FF"), QsciLexerPostScript::Name);
    setColor(QColor("#FF6D00"), QsciLexerPostScript::Keyword);
    setColor(color, QsciLexerPostScript::Literal);
    setColor(color, QsciLexerPostScript::ImmediateEvalLiteral);
    setColor(color, QsciLexerPostScript::ArrayParenthesis);
    setColor(color, QsciLexerPostScript::DictionaryParenthesis);
    setColor(color, QsciLexerPostScript::ProcedureParenthesis);
    setColor(color, QsciLexerPostScript::Text);
    setColor(QColor("#39FF00"), QsciLexerPostScript::HexString);
    setColor(QColor("#39FF00"), QsciLexerPostScript::Base85String);
    setColor(QColor("#06DD00"), QsciLexerPostScript::BadStringCharacter);

    setFont(font, QsciLexerPostScript::Default);
    setFont(font, QsciLexerPostScript::Comment);
    setFont(font, QsciLexerPostScript::DSCComment);
    setFont(font, QsciLexerPostScript::DSCCommentValue);
    setFont(font, QsciLexerPostScript::Name);
    setFont(font, QsciLexerPostScript::Keyword);
    setFont(font, QsciLexerPostScript::Literal);
    setFont(font, QsciLexerPostScript::ImmediateEvalLiteral);
    setFont(font, QsciLexerPostScript::ArrayParenthesis);
    setFont(font, QsciLexerPostScript::DictionaryParenthesis);
    setFont(font, QsciLexerPostScript::ProcedureParenthesis);
    setFont(font, QsciLexerPostScript::Text);
    setFont(font, QsciLexerPostScript::HexString);
    setFont(font, QsciLexerPostScript::Base85String);
    setFont(font, QsciLexerPostScript::BadStringCharacter);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    for (const QString &str : QString(keywords(2)).split(" "))
    {
        api->add(str + "?5");
    }

    for (const QString &str : QString(keywords(3)).split(" "))
    {
        api->add(str + "?1");
    }

    for (const QString &str : QString(keywords(4)).split(" "))
    {
        api->add(str + "?3");
    }

    api->prepare();
}
