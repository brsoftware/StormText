/**
 * @brief BrStormTextLexerCSS.cpp: A file of the StormText project.
 * @author Bright Software Foundation
 * @date Jun 8 2023
 *
 * See the project QMake file for details.
 */


#include "BrStormTextLexerCSS.hpp"

#include <Qsci/qsciapis.h>


BrStormTextLexerCSS::BrStormTextLexerCSS(QFont font, QColor color, QObject *parent)
    : QsciLexerCSS(parent)
{
    setAutoIndentStyle(QsciScintilla::AiMaintain);

    setFoldComments(true);
    setFoldCompact(true);

    setColor(color, QsciLexerCSS::Default);
    setColor(QColor("#3900FF"), QsciLexerCSS::Tag);
    setColor(QColor("#FF6D00"), QsciLexerCSS::ClassSelector);
    setColor(color, QsciLexerCSS::Operator);
    setColor(QColor("#FF00FD"), QsciLexerCSS::CSS1Property);
    setColor(QColor("#FF00FD"), QsciLexerCSS::CSS2Property);
    setColor(QColor("#FF00FD"), QsciLexerCSS::CSS3Property);
    setColor(QColor("#FF9900"), QsciLexerCSS::UnknownProperty);
    setColor(QColor("#FF9900"), QsciLexerCSS::UnknownPseudoClass);
    setColor(QColor("#39FF00"), QsciLexerCSS::DoubleQuotedString);
    setColor(QColor("#39FF00"), QsciLexerCSS::SingleQuotedString);
    setColor(QColor("#FF6D00"), QsciLexerCSS::IDSelector);
    setColor(color, QsciLexerCSS::Value);
    setColor(QColor("#FF6D00"), QsciLexerCSS::Attribute);
    setColor(QColor("#FF00FD"), QsciLexerCSS::ExtendedCSSProperty);
    setColor(defaultColor(QsciLexerCSS::PseudoClass),
             QsciLexerCSS::ExtendedPseudoClass);
    setColor(defaultColor(QsciLexerCSS::PseudoElement),
             QsciLexerCSS::ExtendedPseudoElement);
    setColor(color, QsciLexerCSS::MediaRule);
    setColor(color, QsciLexerCSS::Variable);
    setColor(QColor("#EA0000"), QsciLexerCSS::Comment);
    setColor(QColor("#FF3300"), QsciLexerCSS::Important);

    setFont(font, QsciLexerCSS::Default);
    setFont(font, QsciLexerCSS::Tag);
    setFont(font, QsciLexerCSS::ClassSelector);
    setFont(font, QsciLexerCSS::Operator);
    setFont(font, QsciLexerCSS::CSS1Property);
    setFont(font, QsciLexerCSS::CSS2Property);
    setFont(font, QsciLexerCSS::CSS3Property);
    setFont(font, QsciLexerCSS::UnknownProperty);
    setFont(font, QsciLexerCSS::UnknownPseudoClass);
    setFont(font, QsciLexerCSS::DoubleQuotedString);
    setFont(font, QsciLexerCSS::SingleQuotedString);
    setFont(font, QsciLexerCSS::IDSelector);
    setFont(font, QsciLexerCSS::Value);
    setFont(font, QsciLexerCSS::Attribute);
    setFont(font, QsciLexerCSS::ExtendedCSSProperty);
    setFont(font, QsciLexerCSS::ExtendedPseudoClass);
    setFont(font, QsciLexerCSS::ExtendedPseudoElement);
    setFont(font, QsciLexerCSS::MediaRule);
    setFont(font, QsciLexerCSS::Variable);
    setFont(font, QsciLexerCSS::Comment);
    setFont(font, QsciLexerCSS::Important);
    setFont(font, QsciLexerCSS::PseudoClass);
    setFont(font, QsciLexerCSS::PseudoElement);

    setPaper(QsciLexer::defaultPaper());

    QsciAPIs *api;
    api = new QsciAPIs(this);

    for (const QString &str : QString(css1Properties).split(" "))
    {
        api->add(str + "?7");
    }

    for (const QString &str : QString(css2Properties).split(" "))
    {
        api->add(str + "?7");
    }

    for (const QString &str : QString(css3Properties).split(" "))
    {
        api->add(str + "?7");
    }

    for (const QString &str : QString(cssPseudoClasses).split(" "))
    {
        api->add(str + "?8");
    }

    for (const QString &str : QString(cssPseudoElement).split(" "))
    {
        api->add(str + "?9");
    }

    for (const QString &str : QString(cssExtendedProperties).split(" "))
    {
        api->add(str + "?7");
    }

    for (const QString &str : QString(cssExtendedPseudoClass).split(" "))
    {
        api->add(str + "?8");
    }

    for (const QString &str : QString(cssExtendedPseudoElement).split(" "))
    {
        api->add(str + "?9");
    }

    api->prepare();
}

