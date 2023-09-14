/**
 * @brief BrStormTextLexerCoffeeScript.hpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerCoffeeScript.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerCoffeeScript::BrStormTextLexerCoffeeScript(QFont font, QColor color, QObject *parent)
    : QsciLexerCoffeeScript(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setColor(color, QsciLexerCoffeeScript::Default);
    setColor(QColor("#EA0000"), QsciLexerCoffeeScript::Comment);
    setColor(QColor("#EA0000"), QsciLexerCoffeeScript::CommentLine);
    setColor(QColor("#EA0000"), QsciLexerCoffeeScript::CommentDoc);
    setColor(QColor("#FF6D00"), QsciLexerCoffeeScript::Keyword);
    setColor(QColor("#39FF00"), QsciLexerCoffeeScript::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerCoffeeScript::SingleQuotedString);
    setColor(QsciLexerCoffeeScript::defaultColor(QsciLexerCoffeeScript::Number),
             QsciLexerCoffeeScript::UUID);
    setColor(QColor("#FF00FD"), QsciLexerCoffeeScript::PreProcessor);
    setColor(color, QsciLexerCoffeeScript::Operator);
    setColor(QColor("#3900FF"), QsciLexerCoffeeScript::Identifier);
    setColor(QColor("#06CC00"), QsciLexerCoffeeScript::UnclosedString);
    setColor(QColor("#17DD00"), QsciLexerCoffeeScript::VerbatimString);
    setColor(color, QsciLexerCoffeeScript::Regex);
    setColor(QColor("#EA0000"), QsciLexerCoffeeScript::CommentLineDoc);
    setColor(QColor("#FF6D00"), QsciLexerCoffeeScript::KeywordSet2);
    setColor(QColor("#999900"), QsciLexerCoffeeScript::CommentDocKeyword);
    setColor(QColor("#666699"), QsciLexerCoffeeScript::CommentDocKeywordError);
    setColor(QColor("#39FF00"), QsciLexerCoffeeScript::GlobalClass);
    setColor(QColor("#EA0000"), QsciLexerCoffeeScript::CommentBlock);
    setColor(color, QsciLexerCoffeeScript::BlockRegex);
    setColor(QColor("#EA0000"), QsciLexerCoffeeScript::BlockRegexComment);
    setColor(color, QsciLexerCoffeeScript::InstanceProperty);

    setFont(font, QsciLexerCoffeeScript::Default);
    setFont(font, QsciLexerCoffeeScript::Comment);
    setFont(font, QsciLexerCoffeeScript::CommentLine);
    setFont(font, QsciLexerCoffeeScript::CommentDoc);
    setFont(font, QsciLexerCoffeeScript::Keyword);
    setFont(font, QsciLexerCoffeeScript::DoubleQuotedString);
    setFont(font, QsciLexerCoffeeScript::SingleQuotedString);
    setFont(font, QsciLexerCoffeeScript::UUID);
    setFont(font, QsciLexerCoffeeScript::PreProcessor);
    setFont(font, QsciLexerCoffeeScript::Operator);
    setFont(font, QsciLexerCoffeeScript::Identifier);
    setFont(font, QsciLexerCoffeeScript::UnclosedString);
    setFont(font, QsciLexerCoffeeScript::VerbatimString);
    setFont(font, QsciLexerCoffeeScript::Regex);
    setFont(font, QsciLexerCoffeeScript::CommentLineDoc);
    setFont(font, QsciLexerCoffeeScript::KeywordSet2);
    setFont(font, QsciLexerCoffeeScript::CommentDocKeyword);
    setFont(font, QsciLexerCoffeeScript::CommentDocKeywordError);
    setFont(font, QsciLexerCoffeeScript::GlobalClass);
    setFont(font, QsciLexerCoffeeScript::CommentBlock);
    setFont(font, QsciLexerCoffeeScript::BlockRegex);
    setFont(font, QsciLexerCoffeeScript::BlockRegexComment);
    setFont(font, QsciLexerCoffeeScript::InstanceProperty);

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(keywords(1)).split(" "))
    {
        api->add(str + "?4");
    }

    api->prepare();
}
